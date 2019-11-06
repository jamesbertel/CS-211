#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "day.h"
#include "week.h"
#include "total.h"
#ifndef APP_CPP
#define APP_CPP

class Day;
class Week;
class Total;
/*
class Day
{
protected:
  int day;
  int month;
  int year;
public:
  Day(){ day = month = year = 0;};
  Day(int d, int m, int y){day = d; month = m; year = y;};
};


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
};

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
};
*/
void RunApp()
{
  


}

int main()
{
  RunApp();
  return 0;
}
#endif
