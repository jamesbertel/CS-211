#include <iostream>
using namespace std;
#include "TenureTrackProf.h"
#ifndef TENURETRACKPROF_CPP
#define TENURETRACKPROF_CPP

TenureTrackProf::TenureTrackProf()
{
  rank = 'A';
  YearOfExp = 0;
}

float TenureTrackProf::findSalary() const
{
  if(rank == 'A')
    return ( (1500 * YearOfExp) + 65000);
  if(rank == 'S')
    return ( (1500 * YearOfExp) + 80000);
  if(rank == 'F')
    return ( (1500 * YearOfExp) + 90000);

}

void TenureTrackProf::print() const
{
  cout << "Name: " << name << endl;
  cout << "Email: " << email << "@csusm.edu" << endl;
  cout << "Faculty ID: " << facultyId << endl;

  cout << "Rank : " << rank << endl;
  cout << "Years of Exp: " << YearOfExp << endl;
}

void TenureTrackProf::setTenureTrackProf(char r, int y)
{
  rank = r;
  YearOfExp = y;
}
#endif
