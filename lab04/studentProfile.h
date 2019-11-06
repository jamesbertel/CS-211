#include "person.h"
#include "student.h"
#include <vector>
using namespace std;
#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

class StudentProfile
{
 private:
  Person PersonalInfo;
  Student StdInfo;
 public:
  void setStudentProfile(Person pInfo, Student sInfo);
  void Print();
};
#endif
