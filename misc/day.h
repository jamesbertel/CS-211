#ifndef DAY_H
#define DAY_H

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
#endif