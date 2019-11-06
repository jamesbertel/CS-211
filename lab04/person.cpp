#include "person.h"
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef PERSON_CPP
#define PERSON_CPP

void Person::setPerson(long s, string fn, string ln, int a, char g)
{
  ssn = s;
  fname = fn;
  lname = ln;
  age = a;
  gender = g;
}

void Person::printPerson()
{
  cout << left;
  cout << setw(12) << ssn;
  cout << setw(10) << fname;
  cout << setw(10) << lname;
  cout << setw(4) << age;
  cout << setw(8) << gender;
}
#endif
