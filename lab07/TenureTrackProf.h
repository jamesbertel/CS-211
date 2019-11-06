#include "CompSciProfessor.h"
#ifndef TENURETRACKPROF_H
#define TENURETRACKPROF_H

class TenureTrackProf: public CompSciProfessor
{
 protected:
  char rank;
  int YearOfExp;
 public:
  TenureTrackProf();
  void setTenureTrackProf(char r, int y);
  void print() const;
  float findSalary() const;
};
#endif
