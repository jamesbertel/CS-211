//Thursday 9/13/18 Week 3
//Tuesday 9/18/18 Week 4
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//--------------------

class Person
{
public:
  long ssn;
  string fname;
  string lname;
  int age;
  char gender;
};

//---------------------

class Course
{
public:
  long courseNum;
  string courseName;
};

//----------------------

class Student
{
public:
  long stNo;
  Course course1;
  Course course2;
  Course course3;
  Course course4;
  Course course5;
};

//----------------------

class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;
};

//--------------------------------------------------------
//--------------------------------------------------------

void GetInfo(ifstream & fin, vector<StudentProfile> & student)
{
  StudentProfile st;

  fin >> st.PersonalInfo.ssn;
  fin >> st.PersonalInfo.fname;
  fin >> st.PersonalInfo.lname;
  fin >> st.PersonalInfo.age;
  fin >> st.PersonalInfo.gender;
  
  fin >> st.StdInfo.stNo;
  fin >> st.StdInfo.course1.courseNum;
  fin >> st.StdInfo.course1.courseName;
  fin >> st.StdInfo.course2.courseNum;
  fin >> st.StdInfo.course2.courseName;
  fin >> st.StdInfo.course3.courseNum;
  fin >> st.StdInfo.course3.courseName;
  fin >> st.StdInfo.course4.courseNum;
  fin >> st.StdInfo.course4.courseName;
  fin >> st.StdInfo.course5.courseNum;
  fin >> st.StdInfo.course5.courseName;
  
  student.push_back(st);    
}

//------------------------

void Print(const vector<StudentProfile> & st)
{
  cout << left << endl;
  cout << setw(10) << "SSN";
  cout << setw(10) << "First";
  cout << setw(10) << "Last";
  cout << setw(4) << "Age";
  cout << setw(8) << "Gender";
  cout << setw(10) << "Std ID";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << setw(8) << "Course#";
  cout << setw(10) << "Course";
  cout << endl;

  for(int i = 0; i < st.size() - 1; i++)
    {
      cout << setw(10) << st[i].PersonalInfo.ssn;
      cout << setw(10) << st[i].PersonalInfo.fname;
      cout << setw(10) << st[i].PersonalInfo.lname;
      cout << setw(4)  << st[i].PersonalInfo.age;
      cout << setw(8)  << st[i].PersonalInfo.gender;
      cout << setw(10) << st[i].StdInfo.stNo;
      cout << setw(8)  << st[i].StdInfo.course1.courseNum;
      cout << setw(10) << st[i].StdInfo.course1.courseName;
      cout << setw(8)  << st[i].StdInfo.course2.courseNum;
      cout << setw(10) << st[i].StdInfo.course2.courseName;
      cout << setw(8)  << st[i].StdInfo.course3.courseNum;
      cout << setw(10) << st[i].StdInfo.course3.courseName;
      cout << setw(8)  << st[i].StdInfo.course4.courseNum;
      cout << setw(10) << st[i].StdInfo.course4.courseName;
      cout << setw(8)  << st[i].StdInfo.course5.courseNum;
      cout << setw(10) << st[i].StdInfo.course5.courseName;
      cout << endl;
    }
  cout << endl;
}

//-----------------------------------------
//-----------------------------------------
int main()
{

  ifstream fin;
  vector<StudentProfile> StCollection;
  fin.open("text.txt");

  while(fin)
    GetInfo(fin, StCollection);

  Print(StCollection);

  fin.close();
  return 0;
}
  
