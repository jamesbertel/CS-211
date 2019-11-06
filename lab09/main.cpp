/********************************************************************************************
/ CS 211 - Lab 9
/ Complete the program Lab09(Program).cpp and implement the routines that are not implemented
/ Weeks 11 & 12, Early-Mid November
/********************************************************************************************
/* Use the comments given in each routine to complete the following program */

#include <iostream>
#include<string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;

//--
class LL;

class Node 
{
  friend class LL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;
public:
  Node()
  {stName = stEmail = "unknown"; stId = stAge = 0;};
  Node(int id, string name, string email, int age)
  {stId = id; stName = name; stEmail = email; stAge = age;};
};

//--

class LL
{
  friend class Node;
private:
  NodePtr top;
  void destroy(NodePtr& top);

public:
  LL();
  LL(const LL& source);
  ~LL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};

// the default constructor
LL::LL()
{ top = NULL;}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{ copy(source.top, top); }
//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{ destroy(top);}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
void LL::insertDataFromFile()
{
  int id, age;
  string name, email;

  ifstream fin;
  fin.open("test.txt");
  
  while(fin >> id)
    {
      fin >> name;
      fin >> email;
      fin >> age;

      insertAfterLast(id, name, email, age);
    }
  fin.close();
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void LL::print ()
{
  NodePtr p = top;
  while( p != NULL)
    {
      cout << p->stId << "\t";
      cout << p->stName << "\t";
      cout << p->stEmail << "\t";
      cout << p->stAge << "\t";
      cout << endl;
      p = p->nextStudent;
    }
  cout << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search (int id)
{
  if(top == NULL)
    return false;
  
  NodePtr p = top;
  while(p!=NULL)
    {
      if(p->stId == id)
	return true;
      p = p->nextStudent;
    }
  return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);

  if(top != NULL)
    {
      p -> nextStudent = top -> nextStudent;
      top -> nextStudent = p;
    }
  else
    {
      p -> nextStudent = NULL;
      top = p;
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);

  if(top != NULL)
    {
      p -> nextStudent = top;
      top = p;
    }
  else
    {
      p -> nextStudent = NULL;
      top = p;
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL)
    insertBeforeFirst(id, name, email, age);
  else
    {
      NodePtr p = new Node(id ,name, email, age);
      NodePtr q = top;

      while(q -> nextStudent != NULL)
	q = q -> nextStudent;

      q -> nextStudent = p;
      p -> nextStudent = NULL;
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
  if(top == NULL)
    insertBeforeFirst(id, name, email, age);
  else
    {
      NodePtr p = new Node(id, name, email, age);
      NodePtr q = top;

      while( q -> nextStudent -> nextStudent != NULL)
	  q = q -> nextStudent;

      p -> nextStudent = q -> nextStudent;
      q -> nextStudent = p;
    }
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
  NodePtr p = top;
  NodePtr q = p -> nextStudent;

  while(q -> stId != id)
    {
      p = p -> nextStudent;
      q = q -> nextStudent;
    }

  p -> nextStudent = q -> nextStudent;
  delete q;
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy (NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr;
  destroy(btop);

  if(atop != NULL)
    {
      btop = new Node;
      btop -> stId = atop -> stId;
      btop -> stName = atop -> stName;
      btop -> stEmail = atop -> stEmail;
      btop -> stAge = atop -> stAge;

      acurr = atop;
      bcurr = btop;
      
      while(acurr -> nextStudent != NULL)
	{
	  bcurr -> nextStudent = new Node;
	  acurr = acurr -> nextStudent;
	  bcurr = bcurr -> nextStudent;

	  bcurr -> stId = acurr -> stId;
	  bcurr -> stName = acurr -> stName;
	  bcurr -> stEmail = acurr -> stEmail;
	  bcurr -> stAge = acurr -> stAge;
	}
      bcurr -> nextStudent = NULL;
    }
}       
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
  /*  if(top != NULL)
    {
      NodePtr q= top;
      top = top -> nextStudent;
      delete q;
      }*/

  NodePtr p = top;
  while (top != NULL)
    {
      top = top -> nextStudent;
      delete p;
      p = top;
    }
}

//--------------------------------------------

int main () 
{
  LL list1;
  list1.insertDataFromFile(); cout << endl;
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();

  bool found = list1.search (12321);

  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;

  list1.remove(54321);
  list1.print();
   
  LL list2(list1);
  list2.print();
  
  return 0;
}
