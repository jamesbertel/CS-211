#include <string>
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
using namespace std;

class Department
{
 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId; //Initialize to 100
 public:
  Department();
  Department(string n, string l, long c);
  void printDepartment();
  void assignChair(long facultyId);
  string getname();
  long getid();
};
#endif
