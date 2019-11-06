#include "MYMATH.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
  char choice;

  cout << "Enter char: ";
  cin >> choice;
  

  cout << getValidity(choice) << endl;

  return 0;
}
