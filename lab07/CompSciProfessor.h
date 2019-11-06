#include <string>
#include <iostream>
#ifndef COMPSCIPROFESSOR_H
#define COMPSCIPROFESSOR_H
using namespace std;

class CompSciProfessor
{
 protected:
  string name;
  string email;
  long facultyId;
 public:
  CompSciProfessor();
  void getCompSciProfessor();
  void setCompSciProfessor(string n, string e, long id);
};
#endif
