#include "studentProfile.h"
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
#ifndef MAIN_CPP
#define MAIN_CPP

void PrintHeader();

int main()
{
  ifstream fin;
  vector<StudentProfile> StCollection;
  fin.open("text.txt");

  long ssn, stno, cnum1, cnum2, cnum3, cnum4, cnum5;
  string fname, lname, cname1, cname2, cname3, cname4, cname5;
  int age;
  char gen;

  StudentProfile temp;
  Person p;
  Student s;
  Course c1, c2, c3, c4, c5;
  
  while(fin >> ssn)
    {
      fin >> fname >> lname >> age >> gen >> stno;
      fin >> cnum1 >> cname1 >> cnum2 >> cname2 >> cnum3;
      fin >> cname3 >> cnum4 >> cname4 >> cnum5 >> cname5;
      
      p.setPerson(ssn, fname, lname, age, gen);

      c1.setCourse(cnum1, cname1);
      c2.setCourse(cnum2, cname2);
      c3.setCourse(cnum3, cname3);
      c4.setCourse(cnum4, cname4);
      c5.setCourse(cnum5, cname5);

      s.setStudent(stno, c1, c2, c3, c4, c5);

      temp.setStudentProfile(p, s);
      StCollection.push_back(temp);
    }

  PrintHeader();
  for(int i = 0; i < StCollection.size(); i++)
    {
      StCollection[i].Print();
      cout << endl;
    }
  cout << endl;

  fin.close();
  return 0;
}

void PrintHeader()
{
  cout << left << endl;
  cout << setw(12) << "SSN";
  cout << setw(10) << "First";
  cout << setw(10) << "Last";
  cout << setw(4) << "Age";
  cout << setw(8) << "Gender";
  cout << setw(12) << "Std ID";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << endl;
}
#endif
