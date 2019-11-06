#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "day.h"
#include "week.h"
#include "total.h"
using namespace std;
 
class Day;
class Week;
class Total;

void Total::RunApp()
{
  printInfo();

  bool runtime = true;
  char choice;  

  while(runtime)
    {

      do
	{
	  cout << "What would you like to do?\n" << endl;
	  cout << "A:\tEdit Paycheck balance" << endl;
	  cout << "B:\tEdit Gas balance" << endl;
	  cout << "C:\tEdit Week balance" << endl;
	  cout << "X:\tExit Program" << endl;
	  cout << endl;

	  cin >> choice;
	  cin.ignore(1000, '\n');

	}while( getValidity(choice) == false);

      if(choice == 'a')
	paycheck.editpaycheck();
      else if(choice == 'b')
	gas.editgas();
      else if(choice == 'c')
	EditWeekBalance();
      else if(choice == 'x')
	runtime = false;
      else
	{cout << "ERROR!\n"; return;}

    }
}

//-----------------------------------------------------------------

bool Total::EditWeekBalance()
{
  if(semesterWeeks.size() == 0)
    {
      semesterWeeks.push_back(AddSemesterLine());
      return true;
    }

  //-----
  char choice;  
  cout << "What would you like to do?" << endl;
  do
    {
      cout << "What would you like to do?\n" << endl;
      cin >> choice;
      
       cout << "A:\tPrint All" << endl;
      cout << "B:\tPrint Last 5 weeks" << endl;
      cout << "C:\tAdd a line" << endl;
      cout << "D:\tEdit a line" << endl;
      cout << "E:\tDelete a line" << endl;
      cout << "X:\tExit" << endl;
      cout << endl;
      
    }while(getValidity(choice));
  
  //-----

  if(choice == 'a')
    PrintSemesterWeeks(0);
  else if(choice == 'b')
    PrintSemesterWeeks(semesterWeeks.size() - 5);
  else if(choice == 'c')
    semesterWeeks.push_back(AddSemesterLine());
  else if(choice == 'd')
    {
      int num;
      do
	{
	  cout << "Which week would you like to edit?\n";
	  cin >> num;
	}while(num >= 0 && num <= semesterWeeks.size());
    }
  else if(choice == 'x')
    return true;
  else
    { cout << "ERROR!\n"; return true;}

}

//-----------------------------------------------------------------

void Total::PrintSemesterWeeks(int num)
{
  for(int i = num; i < semesterWeeks.size(); i++)
    {
      semesterWeeks[i].printWeek();
      cout << endl;
    }
  cout << endl;
}

Week Total::AddSemesterLine()
{
  Week temp;
  temp.AddASemester();
  return temp;
}

//-----------------------------------------------------------------

void Total::printInfo()
{
  cout << "------------------ WELCOME! ------------------" << endl << endl;
  cout << left;
  cout << setw(20) << "Current balance:" << "$" << balance << endl;
  cout << setw(20) << "Paycheck balance:" << "$" << paycheck.gettotalAmount() << endl;
  cout << setw(20) << "Gas balance:" << "$" << gas.gettotalAmount() << endl;

  cout << endl;
}

//-----------------------------------------------------------------

void Total::toLower(char & let)
{
  int offset = 'a' - 'A';

  if(let >= 'A' && let <= 'Z')
    let = (char)(let + offset);
}

bool Total::getValidity(char choice)
{
  toLower(choice);

  if(choice == 'a' || choice == 'b')
    return true;
  else if(choice == 'c' || choice == 'x')
    return true;

  else
    return false;
}

//-----------------------------------

int main()
{
  Total totalamount;
  cout << fixed << setprecision(2);

  totalamount.RunApp();
  return 0;
}
//#endif
