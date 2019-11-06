#include "student.h"
#include <iomanip>
using namespace std;
#ifndef STUDENT_CPP
#define STUDENT_CPP

void Student::setStudent(long sNum, Course c1, Course c2, Course c3, Course c4, Course c5)
{
  stNo = sNum;
  course1 = c1;
  course2 = c2;
  course3 = c3;
  course4 = c4;
  course5 = c5;
}

void Student::printStudent()
{
  cout << left << setw(12) << stNo;
  course1.printCourse();
  course2.printCourse();
  course3.printCourse();
  course4.printCourse();
  course5.printCourse();
}
#endif

