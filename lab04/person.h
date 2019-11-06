#include <string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person
{
 private:
  long ssn;
  string fname;
  string lname;
  int age;
  char gender;

 public:
  void setPerson(long s, string fn, string ln, int a, char g);
  void printPerson();
};
#endif
