#include "week.h"
#include <iostream>
using namespace std;
//#ifndef WEEK_CPP
//#define WEEK_CPP

double Week::gettotalAmount()
{ return totalAmount;}

void Week::editpaycheck()
{ 
  if(nameOfBuy.size() == 0)
    AddPaycheckLine();
  else
    {
      bool runtime = true;
      char choice;
      string function = "editPaycheck";
      do
	{
	  cout << "What would you like to do?\n" << endl;
	  cin >> choice;
	  
	  cout << "A:\tPrint All" << endl;
	  cout << "B:\tPrint Last 5 transactions" << endl;
	  cout << "C:\tAdd a line" << endl;
	  cout << "D:\tEdit a line" << endl;
	  cout << "E:\tDelete a line" << endl;
	  cout << endl;
  
	}while(getValidity(choice, function) == false);

      if(choice == 'a');


    }

  
}

void Week::editgas()
{}

void Week::AddPaycheckLine()
{}

void Week::printWeek()
{}

Week Week::AddASemester()
{}

//-----------

void Week:: toLower(char & let)
{
  int offset = 'a' - 'A';

  if(let >= 'A' && let <= 'Z')
    let = (char)(let + offset);
}

bool Week::getValidity(char choice, string function)
{
  toLower(choice);

  if(choice == 'a' || choice == 'b')
    return true;
  else if(choice == 'c' || choice == 'x')
    return true;
  else if(choice == 'e')
    return true;

  else
    return false;
}

//#endif