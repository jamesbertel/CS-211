#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//#include "university.h"
//#include "department.h"
//#include "student.h"
//#include "person.h"
//#include "course.h"
//#include "faculty.h"
//#include "MAIN.cpp"
using namespace std;
#ifndef TEST_CPP
#define TEST_CPP


class NEAT
{
private:
  int t1;
  string name;
public:
  NEAT(){t1 = 0; name = "unk";};
  NEAT(int o, string n){t1 = o; name = n;};
  string getname(){return name;}
};

class OKAY
{
private:
  vector <NEAT> test;
public:
  OKAY(){};
};

int main()
{
  NEAT n1(0, "Jack");
  NEAT n2(1, "Sally");
  NEAT n3(2, "Boogie");

  vector <NEAT> vec;

  vec.push_back(n1);
  vec.push_back(n2);
  vec.push_back(n3);

  cout << vec.size() << endl;
  string temp =  vec[0].getname();
  cout << temp << endl;
  
  for(int i = 0; i < vec.size(); i++)
    cout << vec[i].getname() << endl;

  return 0;
}
#endif
