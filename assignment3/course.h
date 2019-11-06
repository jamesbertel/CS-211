#include <string>
#ifndef COURSE_H
#define COURSE_H
using namespace std;

class Course
{
 protected:
  long CRN;
  int maxAvaliableSeats;
  string name;
  long assignedSeats;
  long departId;
  long isTaughtBy;
  static long nextCRN; //Initialize to 200
 public:
  Course();
  Course(int max, string n, long d, long taught);
  void printCourse();
  long getdepartid() const;
  long getistaughtby() const;
  string getname() const;
  long getcrn() const;
  long getassignedseats() const;
  int getmaxseats() const;
  void assignInstructor(long id);
  void assignseatnum();
};
#endif
