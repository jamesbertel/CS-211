//Thursday 8/30/18 week 1
//Tuesday 9/04/18 Week 2
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

void ReadData(float arr1[]);
void CopyReverseArray(float a1[], float a2[]);
void Print(float a[]);
int NumofElemDiv(float a1[], int div);
float AvgFct(float a1[]);
int NumofElem(float a1[]);
float MaxNum(float a1[]);
void InputKey(float a[]);

int main()
{
  float arr1[SIZE];
  float arr2[SIZE];

  cout << endl << fixed << setprecision(1);

  ReadData(arr1);
  CopyReverseArray(arr1, arr2);
  Print(arr1);
  Print(arr2);
  cout << "Number of Elements in Arr1 >=80 and <=100: " << NumofElem(arr1) << endl;
  cout << "Num of Elements in Arr1 div by 5: " << NumofElemDiv(arr1, 5) << endl;
  cout << "Num of Elements in Arr1 div by 3: " << NumofElemDiv(arr1, 3) << endl;
  cout << "Mean of Arr1: " << AvgFct(arr1) << endl;
  cout << "Max Num in Arr1: " << MaxNum(arr1) << endl;
  InputKey(arr1);

  return 0;
}

void InputKey(float a[])
{
  bool k = false;
  float key;
  cout << "Input Key: ";
  cin >> key;

  for(int i = 0; i < SIZE; i++)
    {
      if(a[i] == key)
	  k =true;
    }

  if(k == false)
    cout << "Key " << key << " does not exist in this array.\n" << endl;
  else //k == true
    cout << "Key " << key << " exists in this array.\n" << endl;
}

float MaxNum(float a1[])
{
  float max = 0;

  for(int i = 0; i < SIZE; i++)
    {
      if(a1[i] > max)
	max = a1[i];
    }
  return max;
}

float AvgFct(float a1[])
{
  float total = 0.0;
  
  for(int i = 0; i < SIZE; i++)
    total += a1[i];

  return total/SIZE;
}

int NumofElemDiv(float a[], int div)
{
  int num = 0;

  for(int i = 0; i < SIZE; i++)
    {
      if( (int)a[i] % div == 0 && int(a[i]) == a[i] )// (static_cast<int>(a[i] - a[i])) == 0 && (static_cast<int>(a[i]) % div == 0) )
	num++;
    }

  return num;
}

int NumofElem(float a1[])
{
  int ans = 0;

  for(int i = 0; i < SIZE; i++)
    {
      if(a1[i] >= 80 && a1[i] <= 100)
	ans++;
    }

  return ans;
}


void Print(float a[])
{

  for(int i = 0; i < SIZE; i++)
    cout << left << setw(5) << a[i];
  cout << endl;
}

void CopyReverseArray(float a1[], float a2[])
{
  for(int i = 0; i < SIZE; i++)
      a2[SIZE-1-i] = a1[i];
}

void ReadData(float arr1[])
{
  ifstream fin;
  fin.open("data2.txt");

  if(!fin)
    cout << "Error: file not found" << endl;
  else
    {
      for(int i = 0; i < SIZE; i++)
	fin >> arr1[i];
    }

  fin.close();
}
