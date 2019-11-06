//Thursday, 8/30/18 (week 1)
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int CalculateMax(int a1, int a2, int a3, int a4);
int CalculateMin(int a1, int a2, int a3, int a4);
int CalculateAvg(int a1, int a2, int a3, int a4);

int main()
{
  int stuID, a1, a2, a3, a4; //student ID, grades for each assignment
  ifstream fin;
  int min = 0, max = 0, avg = 0; //minimum grade, maximum grade, average

  fin.open("data.txt");
  
  if(!fin)
    cout << "Error: File not found\n" << endl;
  else
    {
      cout << endl;
      cout << left << setw(10) << "Std-Id";
      cout << left << setw(5) << "A1" << left << setw(5) << "A2";
      cout << left << setw(5) << "A3" << left << setw(5) << "A4";
      cout << left << setw(5) << "Min" << left << setw(5) << "Max" << "Average" << endl;
      cout << "--------------------------------------------------" << endl;

      fin >> stuID;
      fin >> a1;
      fin >> a2;
      fin >> a3;
      fin >> a4;


      while(fin)
	{
	  max = CalculateMax(a1, a2, a3, a4);
	  min = CalculateMin(a1, a2, a3, a4);
	  avg = CalculateAvg(a1, a2, a3, a4);
	  cout << left << setw(10) << stuID;
	  cout << left << setw(5) << a1 << left << setw(5) << a2;
	  cout << left << setw(5) << a3 << left << setw(5) << a4;
	  cout << left << setw(5) << min << left << setw(5) << max << avg << endl;

	  fin >> stuID;
	  fin >> a1;
	  fin >> a2;
	  fin >> a3;
	  fin >> a4;
	}
    }

  cout << endl;
  fin.close();

  return 0;
}

int CalculateMin(int a1, int a2, int a3, int a4)
{
  int min = a1;
  
  if(a2 < min)
    min = a2;
  if(a3 < min)
    min = a3;
  if(a4 < min)
    min = a4;

  return min;
}

int CalculateMax(int a1, int a2, int a3, int a4)
{
  int max = a1;
  
  if(a2 > max)
    max = a2;
  if(a3 > max)
    max = a3;
  if(a4 > max)
    max = a4;

  return max;
}

int CalculateAvg(int a1, int a2, int a3, int a4)
{
  return (a1+a2+a3+a4)/4;
}