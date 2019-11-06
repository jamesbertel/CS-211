#include "faculty.h"
#ifndef FACULTY_CPP
#define FACULTY_CPP
using namespace std;

long Faculty::nextFacultyId = 600;

Faculty::Faculty():Person()
{
  nextFacultyId = salary = yearOfExp = departId = 0;
}

Faculty::Faculty(string n, string e, string a, string d, string g, float s, int y, long dep):
  Person(n, e, a, d, g)
{
  id = nextFacultyId;
  salary = s;
  yearOfExp = y;
  departId = dep;
  nextFacultyId++;
}

long Faculty::getdepartid() const
{return departId;}

long Faculty::getid() const
{return id;}

string Faculty::getname() const
{return name;}
#endif
