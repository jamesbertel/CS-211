//Week 9; 10/23/18 && 10/25/19
#include "CompSciProfessor.h"
#include "AdjunctProf.h"
#include "TenureTrackProf.h"

#ifndef MAIN_CPP
#define MAIN_CPP

int main()
{
  AdjunctProf Obj1;

  Obj1.setCompSciProfessor("Adam Smith", "asmith@csusm.edu", 12345);
  Obj1.setAdjunctProf('M', 2, 1);

  float salary1 = Obj1.findSalary();
  
  cout << endl;
  Obj1.print();
  cout << "$" << salary1 << endl << endl;

  //-------------------

  TenureTrackProf Obj2;

  Obj2.setCompSciProfessor("Jim Anderson", "janderson@csusm.edu", 54321);
  Obj2.setTenureTrackProf('S', 8);

  float salary2 = Obj2.findSalary();

  Obj2.print();
  cout << "$" << salary2 << endl;
  cout << endl;

  return 0;
}
#endif
