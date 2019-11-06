#include "week.h"
#ifndef TOTAL_H
#define TOTAL_H

class Total
{
  friend Week;

 protected:
  double balance;
  Week paycheck;
  Week gas;
  vector<Week> semesterWeeks;
 public:
  Total(){balance = 0;};
  Total(double t){balance = t;};
  void RunApp();
  void printInfo();
  bool EditWeekBalance();
  Week AddSemesterLine();
  void PrintSemesterWeeks(int num);
  void toLower(char & let);
  bool getValidity(char choice);
};
#endif
