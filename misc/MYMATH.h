#ifndef MYMATH_H
#define MYMATH_H
#include <iostream>
using namespace std;
/*******************************

Functions:

bool getValidity(char choice)
char toLower(char let)

*******************************/

void toLower(char & let);
bool getValidity(char choice);

//------------------------------------

void toLower(char & let)
{
  int offset = 'a' - 'A';

  if(let >= 'A' && let <= 'Z')
    let = (char)(let + offset);
}

//-------------------------------

bool getValidity(char choice)
{
  toLower(choice);

  if(choice == 'a' || choice == 'b')
    return true;
  else if(choice == 'c' || choice == 'x')
    return true;

  else
    return false;
}

//--------------------------------
#endif