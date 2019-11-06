#include <vector>
#include "course.h"
#include "person.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student: public Person
{
 protected:
  int id;
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId; //initialize it to 500

 public:
  Student();
  Student(string n, string e, string a, string d, string g, int y, string m, long adv);
  long getid() const;
  long getadvisorid() const;
  vector <Course> getcourses();
  void assigncourse(Course temp);
};
#endif
