#include "student.h"
#ifndef STUDENT_CPP
#define STUDENT_CPP
#include <iostream>
using namespace std;

long Student::nextStId = 500;

Student::Student():Person()
{
  id = yearOfStudy = advisorId = 0;
  major = "unknown";
}

Student::Student(string n, string e, string a, string d, string g, int y, string m, long adv):
  Person(n, e, a, d, g)
{
  id = nextStId;
  yearOfStudy = y;
  major = m;
  advisorId = adv;
  nextStId++;
}

long Student::getid() const
{ return id;}

long Student::getadvisorid() const
{ return advisorId;}

vector<Course> Student::getcourses()
{ return coursesTaken;}

void Student::assigncourse(Course temp)
{ coursesTaken.push_back(temp);}

#endif
