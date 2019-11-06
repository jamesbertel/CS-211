#include <string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person
{
 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
 public:
  Person();
  Person(string n, string e, string a, string d, string g);
  void printPerson();
  string getname() const;

};
#endif
