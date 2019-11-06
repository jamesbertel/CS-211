//Thursday 11/1/18 (Week 10)
#include <iostream>
using namespace std;

bool Fib(int x, int y, int z)
{
  int a = y + z;

  if(x == a|| x == 0)
    return true;
  else if (x < a)
    return false;
  else
    return Fib(x, z, a);

}

int main()
{
  int x;

  cout << "Enter a number (enter a negative number to quit): ";
  cin >> x;
  
  while(x >= 0)
    {
      bool fibby = Fib(x, 0, 1);

      if(!fibby)
	cout << "!!!!! Sorry, " << x << " is not a Fibonacci number" << endl;
      else
	cout << "Yes, you got it, " << x << " is a Fibonacci number" << endl;

      cout << "Enter a number (enter a negative number to quit): ";
      cin >> x;
    }

  cout << "\n(*Thanks - Have a good Day :) *)" << endl;

  return 0;
}