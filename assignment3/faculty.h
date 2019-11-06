#include "person.h"
#ifndef FACULTY_H
#define FACULTY_H
using namespace std;

class Faculty: public Person
{
 protected:
  long id;
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId; //initialize to 600
 public:
  Faculty();
  Faculty(string n, string e, string a, string d, string g, float s, int y, long dep);
  long getdepartid() const;
  string getname() const;
  long getid() const;
};
#endif
