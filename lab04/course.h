#include <string>
#include <iostream>
using namespace std;
#ifndef COURSE_H
#define COURSE_H
class Course
{
 public:
  void setCourse(long cNum, string cName);
  void printCourse();
 private:
  long courseNum;
  string courseName;
};
#endif
