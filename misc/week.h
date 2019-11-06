#include <string>
#include <vector>
#include "day.h"
using namespace std;
#ifndef WEEK_H
#define WEEK_H

class Week: public Day
{
 protected:
  vector<string> nameOfBuy;
  vector<double> buyAmount;
  double startAmount;
  double totalAmount;

 public:
  Week(){totalAmount = startAmount = 0;};
  Week(double start){totalAmount = startAmount = start;};
  double gettotalAmount();
  void editpaycheck();
  void editgas();
  void printWeek();
  void AddPaycheckLine();
  Week AddASemester();
  bool getValidity(char choice, string function);
  void toLower(char & let);
};
#endif