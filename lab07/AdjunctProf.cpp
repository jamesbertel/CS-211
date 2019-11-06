#include <iostream>
using namespace std;
#include "AdjunctProf.h"
#ifndef ADJUNCTPROF_CPP
#define ADJUNCTPROF_CPP

AdjunctProf::AdjunctProf()
{
  degree = 'B';
  NoOfTA = NoOfCourses = 0;
}

float AdjunctProf::findSalary() const
{
  if(degree == 'B')
    return ( (1500 * NoOfTA) + (3000 * NoOfCourses));
  if(degree == 'M')
    return ( (2000 * NoOfTA) + (4000 * NoOfCourses));
  if(degree == 'P')
    return ( (2500 * NoOfTA) + (5000 * NoOfCourses));

}

void AdjunctProf::print() const
{
  cout << "Name: " << name << endl;
  cout << "Email: " << email << endl;
  cout << "Faculty ID: " << facultyId << endl;

  cout << "Degree: " << degree << endl;
  cout << "# of TA: " << NoOfTA << endl;
  cout << "# of Courses: " << NoOfCourses << endl;
}

void AdjunctProf::setAdjunctProf(char d, int ta, int c)
{
  degree = d;
  NoOfTA = ta;
  NoOfCourses = c;
}
#endif
