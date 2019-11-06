#indef SP_H
#define SP_H
#include"Person.h"
#include"Student.h"

class StudentProfile
{
 private:
  Person PersonalInfo;
  Student StdInfo;

 public:
  StudentProfile();
}

#endif
