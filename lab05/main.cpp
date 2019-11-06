#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef MAIN_CPP
#define MAIN_CPP

void SetSalary(Employee& emp)
{
  if((emp.empPosition == 'E' || emp.empPosition == 'e')&& emp.yearOfExp < 2)
    emp.salary = 50000;
  else if((emp.empPosition == 'E' || emp.empPosition == 'e') && emp.yearOfExp >= 2)
    emp.salary = 55000;
  else if((emp.empPosition == 'P' || emp.empPosition == 'p') && emp.yearOfExp < 4)
    emp.salary = 60000;
  else if((emp.empPosition == 'P' || emp.empPosition == 'p') && emp.yearOfExp >= 4)
    emp.salary = 65000;
  else if(emp.empPosition == 'M' || emp.empPosition == 'm')
    emp.salary = 70000;
  else if(emp.empPosition == 'D' || emp.empPosition == 'd')
    emp.salary = 80000;
  else
    {    
      cout << "Error: Invalid Employee Position\n.";
      emp.GetInfo();
    }
}

void printHeader()
{
  cout << left << endl;
  cout << setw(20) << "Name";
  cout << setw(10) << "Dept No.";
  cout << setw(5) << "Pos.";
  cout << setw(5) << "Exp";
  cout << setw(10) << "Salary";
  cout << setw(10) << "Emp Id";
  cout << setw(5) << "Off#";
  cout << setw(5) << "#emps";
  cout << setw(10) << "nextEmpId";
  cout << setw(5) << "nextOfficeNo";
}

int main()
{
  printHeader();

  Employee emp1;
  emp1.Print();

  Employee emp2("unknown", 10, '?', 0);
  emp2.GetInfo();

  SetSalary(emp2);
  emp2.Print();

  cout << endl;
  return 0;
}
#endif
