#include "CompSciProfessor.h"
using namespace std;
#ifndef COMPSCIPROFESSOR_CPP
#define COMPSCIPROFESSOR_CPP

CompSciProfessor::CompSciProfessor()
{
  name = email = "UNKNOWN";
  facultyId = 0;
}

void CompSciProfessor::setCompSciProfessor(string n, string e, long id)
{
  name = n;
  email = e;
  facultyId = id;
}

void CompSciProfessor::getCompSciProfessor()
{
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter email: ";
  getline(cin, email);
  cout << "Enter facultyId: ";
  cin >> facultyId;
}
#endif
