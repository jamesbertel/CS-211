//Thursday 11/1/18 (Week 10)
#include <iostream>
using namespace std;

int gcd(int x, int y)
{

  if(y == 0)
    return x;
  else
    gcd(y, x%y);
}


int main()
{
  int x, y;

  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;

  cout << "GCD: " << gcd(x, y) << endl;

  return 0;
}
