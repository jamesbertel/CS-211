#include "course.h"
#include <iomanip>
using namespace std;
#ifndef COURSE_CPP
#define COURSE_CPP

void Course::setCourse(long cNum, string cName)
{
  courseNum = cNum;
  courseName = cName;
}

void Course::printCourse()
{
  cout << left << setw(8) << courseNum << setw(10) << courseName;
}
#endif 
