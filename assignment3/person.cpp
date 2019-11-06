#include "person.h"
#include <iomanip>
#include <iostream>
#ifndef PERSON_CPP
#define PERSON_CPP
using namespace std;

Person::Person()
{
  name = email = address = dateOfBirth = gender + "unknown";
}

Person::Person(string n, string e, string a, string d, string g)
{
  name = n;
  email = e;
  address = a;
  dateOfBirth = d;
  gender = g;
}

void Person::printPerson()
{
  cout << setw(10) << name;
  cout << setw(20) << email;
  cout << setw(25) << address;
  cout << setw(10) << dateOfBirth;
  cout << setw(10) << gender;
  cout << endl;
}

string Person::getname() const
{return name;}
#endif
