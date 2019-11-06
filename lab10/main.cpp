//********************************************************************************************
// CS 211 - Lab 10
// Complete the program Lab10(Program).cpp and implement the routines that are not implemented
//********************************************************************************************

/* Use the comments given in each routine to complete the following program */
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;
class CircularDLL;

class Node 
{
  friend class CircularDLL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr next;
  NodePtr prev;
public:
  Node() {stName = stEmail = "unknown"; stId = stAge = 0;};
  Node(int id, string name, string email, int age)
  {stId = id; stName = name; stEmail = email; stAge = age;};
};

class CircularDLL
{
private:
  NodePtr  top;
  void destroy (NodePtr&);

public:
  CircularDLL();
  CircularDLL(const CircularDLL& source);
  ~CircularDLL();
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
//--------------------------------------------
//--------------------------------------------
// the default constructor
CircularDLL::CircularDLL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
  copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
CircularDLL::~CircularDLL()
{
  destroy(top);
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
   76543Marymary@csusm.edu19
   98765Kathykathy@csusm.edu30
   16438Floraflora@csusm.edu25
   43260Peterpeter@csusm.edu29
   87590kimkim@csusm.edu31
*/
void CircularDLL::insertDataFromFile()
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
void CircularDLL::print ()
{
  NodePtr p = top;
  cout << endl;

  while(p -> next != top)
    {
      cout << p -> stId << "\t";
      cout << p -> stName << "\t";
      cout << p -> stEmail << "\t";
      cout << p -> stAge << "\t";
      cout << endl;

      p = p -> next;
    }
  cout << p -> stId << "\t";
  cout << p -> stName << "\t";
  cout << p -> stEmail << "\t";
  cout << p -> stAge << "\t";
  cout << endl << endl;

}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search (int id)
{
  NodePtr p = top;

  if(p != NULL)
    {
      while(p -> next != top)
	{
	  if(p -> stId == id)
	    return true;
	  else
	    {
	      p = p -> next;
	      //p -> prev = p;
	    }
	}
    }

  return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);

  if(top != NULL)
    {
      p -> next = top -> next;
      p -> prev = top;

      NodePtr q = p -> next;
      q -> prev = p;

      top -> next = p;
    }
  else
    {
      p -> next = top;
      p -> prev = top;
      top = p;
    }

}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);

  if(top == NULL)
    {
      top = p;
      top -> next = top;
      top -> prev = top;
    }
  else
    {
      NodePtr k = top -> prev;
      k -> next = p;
      p -> next = top;
      p -> prev = k;
      top -> prev = p;
      top = p;
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL)
    insertBeforeFirst(id, name, email, age);
  else
    {
      NodePtr p = new Node(id, name, email, age);
      NodePtr q = top;

      while(q -> next != top)
	  q = q -> next;

      q -> next = p;
      p -> prev = q;
      top -> prev = p;
      p -> next = top;
    }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
  if(top == NULL)
    insertAfterLast(id, name, email, age);
  else
    {
      NodePtr p = new Node(id, name, email, age);
      NodePtr q = top;

      while(q -> next -> next != top)
	  q = q -> next;	  

      p -> next = q -> next;
      p -> prev = q;

      q -> next = p; 
      //p -> prev = q;
    }
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
  NodePtr p = top;
  NodePtr q = p -> next;
  
  while(q -> stId != id)
    {
      p = p -> next;
      q = q -> next;
    }

  p -> next = q -> next;
  delete q; 
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
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

      while(acurr -> next != atop)
	{
	  bcurr -> next = new Node;

	  acurr = acurr -> next;
	  bcurr = bcurr -> next;  

	  bcurr -> stId = acurr -> stId;
	  bcurr -> stName = acurr -> stName;
	  bcurr -> stEmail = acurr -> stEmail;
	  bcurr -> stAge = acurr -> stAge;
	}
      bcurr -> next = btop;
      btop -> prev = bcurr;
    }
}       
//--------------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{
  if(top == NULL)
    return;
  else
    {
      NodePtr p = top -> next;
      while(p != top)
	{
	  NodePtr q = p;
	  p = p -> next;
	  delete q;
	}
      delete top;
      top = NULL;
    }
}
//--------------------------------------------

int main () 
{
  CircularDLL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  bool  found = list1.search (12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;
  list1.remove (54321);
  list1.print();
   
  CircularDLL list2(list1);
  list2.print();
  return 0;
}
