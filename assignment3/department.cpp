 #include "department.h"
#ifndef DEPARTMENT_CPP
#define DEPARTMENT_CPP
using namespace std;

long Department::nextDepartId = 100;

Department::Department()
{
  id = chairId = 0;
  name = location = "unknown";
}

Department::Department(string n, string l, long c)
{
  id = nextDepartId;
  name = n;
  location = l;
  chairId = c;
  nextDepartId++;
}

void Department::assignChair(long facultyId)
{ chairId = facultyId;}

string Department::getname()
{
  return name;
}

long Department::getid()
{
  return id;
}

#endif
