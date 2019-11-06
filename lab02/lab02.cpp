//Thursday 9/6/18 Week 2 (Due Thursday 9/13/18 Week 3)
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

void Add(ifstream & fin, vector <string> & vec);
void Remove(ifstream & fin, vector <string> & vec);
void Print(const vector <string> & vec);

int main()
{
  vector <string> vec;
  ifstream fin;
  string operation; //variable for commands such as "add" "remove" and "print"

  fin.open("transaction.txt");
  cout << endl;
  
  if(!fin)
    cout << "Error: file DNE" << endl;
  else
    {
      fin >> operation; //puts first command into operation

      while(fin)
	{ //call proper function based on command
	  if(operation=="Add")
	    Add(fin, vec);
	  else if(operation=="Remove")
	    Remove(fin, vec);
	  else if(operation=="Print")
	    Print(vec);
	  else
	    { cout << "ERROR: NO COMMAND" << endl; break;}
	  fin >> operation;
	}
    }

  cout << endl;
  fin.close();
  return 0;
}

void Add(ifstream & fin, vector <string> & vec)
{
  int pos;
  string temp;
  fin >> temp;
  fin >> pos;

  if(vec.size() < pos)
    cout << "Error: Position #" << pos << " is out of range" << endl;
  else
    vec.insert(vec.begin() + pos, temp);
}

void Remove(ifstream & fin, vector <string> & vec)
{
  int pos;
  fin >> pos;

  if(vec.size() < pos)
    cout << "Error: Position #" << pos << " is out of range" << endl;
  else
    vec.erase(vec.begin() + pos);
}

void Print(const vector <string> & vec)
{
  for(int i = 0; i < vec.size(); i++)
  cout << vec[i] << " ";
  cout << endl;
}
