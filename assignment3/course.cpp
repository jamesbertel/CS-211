#include "course.h"
#ifndef COURSE_CPP
#define COURSE_CPP
using namespace std;

long Course::nextCRN = 200;

Course::Course()
{
  assignedSeats = CRN = maxAvaliableSeats = departId = isTaughtBy = 0;
  name = "unknown";
}

Course::Course(int max, string n, long d, long taught)
{
  assignedSeats = 0;
  CRN = nextCRN;
  maxAvaliableSeats = max;
  name = n;
  departId = d;
  isTaughtBy = taught;
  nextCRN++;
}

void Course::assignInstructor(long id)
{
  isTaughtBy = id;
}

void Course::assignseatnum()
{ assignedSeats++;}

long Course::getassignedseats() const
{ return assignedSeats;}

int Course::getmaxseats() const
{ return maxAvaliableSeats;}

long Course::getdepartid() const
{ return departId;}

long Course::getistaughtby() const
{ return isTaughtBy;}

long Course::getcrn() const
{ return CRN;}

string Course::getname() const
{ return name;}

#endif
