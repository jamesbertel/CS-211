#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

int Employee::totalNumofEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

Employee::Employee():officeNo(nextOfficeNo), empId(nextEmpId)
{
  name = "Unknown";
  deptNo = 0;
  empPosition = 'E';
  yearOfExp = 0;
  salary = 0;

  totalNumofEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):officeNo(nextOfficeNo), empId(nextEmpId)
{
  name = theName;
  deptNo = theDeptNo;
  empPosition = theEmpPosition;
  yearOfExp = theYearOfExp;
  salary = 0;

  totalNumofEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

Employee::~Employee()
{
  totalNumofEmployees--;
  nextOfficeNo--;
}

void Employee::Print() const
{
  cout << left << endl;
  cout << setw(20) << name;
  cout << setw(10) << deptNo;
  cout << setw(5) << empPosition;
  cout << setw(5) << yearOfExp;
  cout << right << "$" << left << setw(10) << salary;
  cout << setw(10) << empId;
  cout << setw(5) << officeNo;
  cout << setw(5) << totalNumofEmployees;
  cout << setw(10) << nextEmpId;
  cout << setw(5) << nextOfficeNo;
}

void Employee::GetInfo()
{
  cout << "\n\nEnter name: ";
  getline(cin, name);
  cout << "Enter employee position: ";
  cin >> empPosition;
  cout << "Enter # years of experience: ";
  cin >> yearOfExp;
}
#endif
