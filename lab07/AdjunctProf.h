#include "CompSciProfessor.h"
#ifndef ADJUNCTPROF_H
#define ADJUNCTPROF_H

class AdjunctProf: public CompSciProfessor
{
 protected:
  char degree;
  int NoOfTA;
  int NoOfCourses;
 public:
  AdjunctProf();
  void setAdjunctProf(char d, int ta, int c);
  void print() const;
  float findSalary() const;
};
#endif
