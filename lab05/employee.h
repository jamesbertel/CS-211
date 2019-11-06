#include <string>
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
  friend void SetSalary(Employee& theEmp);

 private:
  string name;
  const long officeNo;
  const long empId;
  int deptNo;
  char empPosition; //'E' = entry level, 'M' = manager, 
                    //'D' = director, 'P' = project_leader
  int yearOfExp;
  float salary;
  static int totalNumofEmployees;
  static int nextEmpId;
  static int nextOfficeNo;

 public:
  Employee();
  ~Employee();
  Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp);
  void Print() const;
  void GetInfo();
};
#endif
