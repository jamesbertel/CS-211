#include "course.h"
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
 public:
  void setStudent(long sNum, Course c1, Course c2, Course c3, Course c4, Course c5);
  void printStudent();
 private:
  long stNo;
  Course course1;
  Course course2;
  Course course3;
  Course course4;
  Course course5;
 
};
#endif
