#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "department.h"
#include "student.h"
#include "person.h"
#include "course.h"
#include "faculty.h"
//#include "university.h"
#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP
using namespace std;

class University
{
  friend Department;
  friend Student;
  friend Course;
  friend Faculty;
  friend Person;

protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;

public:
  University();
  ~University();
  
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  //!!bool RemoveADepartment(long depId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,
			int sYearOfStudy, string sMajor, long sAdvisorId);
  //!!bool RemoveAStudent(long sStId); 
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  //!!bool RemoveACourse(long cCRN); // Optional 
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
			float fSalary, int fYearOfExp, long fDepId);
  //!!bool RemoveAFaculty(long fFactId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);
  
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  bool ProcessTransactionFile(string fileName);
};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{}

//----------------------------------------------------------------------------
University::~University()
{}

//----------------------------------------------------------------------------
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  bool depChairExists = false;

  if(depChairId == 0)
    depChairExists = true;
  else
    for(int i = 0; i < Faculties.size() && depChairExists == false; i++)
      if(Faculties[i].getdepartid() == depChairId)
	depChairExists = true;

  if(depChairExists == true)
    {
      Department Dept(depName, depLoc, depChairId);
      Departments.push_back(Dept);
      cout << "Department " << depName << " creation success.\n";
      return success;
    }
  else
    {
      cout << "Error: Department Chair ID not valid - cannot create department.\n" << endl;
      return failure;
    }
}
//----------------------------------------------------------------------------
/*!!
bool University::RemoveADepartment(long depId)
{
  /*
    - check if the depId passed to this method is a valid existing department id. If not
      return failure; otherwise,
      - search and remove the department from the Departments vector only if the department has no faculty 
        and offers no course and no student's major matches the department name 
	- return success
}
 !! */

//----------------------------------------------------------------------------
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  /*
    - Note: The vector CourseTaken should be initially empty. You can use the appropriate methods 
    shown in the University class to add or drop a course for a student later
  */
  
  //check to see if major exists in any department
  bool majorExists = false;

  for(int i = 0; i < Departments.size() && majorExists == false; i++)
    if(Departments[i].getname() == sMajor || sMajor == "0")
      majorExists = true;

  if(majorExists == false)
    {
      cout << "Error: Major Does Not Exist - Cannot create student.\n" << endl;
      return failure;
    }

  //check to see if faculty advisor exists
  bool advisorExists = false;

  for(int i = 0; i < Faculties.size() && advisorExists == false; i++)
    if(Faculties[i].getid() == sAdvisorId || sAdvisorId == 0)
      advisorExists = true;

  if(advisorExists == false)
    {  
      cout << "Error: Advisor Does Not Exist - Cannot create student.\n" << endl;
      return failure;
    }

  //create new student
  Student stu(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
  Students.push_back(stu);
  cout << "Student creation for " << sName << " success.\n";
  return success;
}

//----------------------------------------------------------------------------
/*!!
bool University::RemoveAStudent(long sStId)
{
  /*
    - check if the sStId passed to this method is a valid existing student id. If not
      return failure; otherwise,
      - search and remove the student from the Students vector
      - make sure that before removing the student, you need to call the drop course method to drop his/her
        courses
	- return success
  }
!!*/

//----------------------------------------------------------------------------
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{

  //check if faculty exists in department
  bool facultyExists = false;

  if(cTaughtBy == 0)
    facultyExists = true;
  else
      for(int i = 0; i < Faculties.size() && facultyExists == false; i++)
	if(Faculties[i].getid() == cTaughtBy)
	  facultyExists = true;
    
  if(facultyExists == false)
    {
      cout << "Error: Faculty does not exist - Cannot create course.\n" << endl;
      return failure;
    }

  //check if department exists among faculty
  bool deptExists = false;

  for(int i = 0; i < Faculties.size() && deptExists == false; i++)
    if(Faculties[i].getdepartid() == cDepId)
      deptExists = true;

  if(deptExists == false)
    {
      cout << "Error: Department does not exist - Cannot create course.\n" << endl;
      return failure;
    }

  //create new course
  Course cr(cMaxSeat, cName, cDepId, cTaughtBy);
  Courses.push_back(cr);
  return success;
}

//----------------------------------------------------------------------------
/*!!
bool University::RemoveACourse(long cCRN)
{
  /*
    - check if the cCRN passed to this method is a valid existing course id. If not
      return failure; otherwise,
      - search and remove the course from the Courses vector only if no student is currently taking 
        this course 
	- return success
}  
!1*/

//----------------------------------------------------------------------------
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  for(int i = 0; i < Departments.size(); i++)
    if(Departments[i].getid() == fDepId)
      {
	Faculty fac(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
	Faculties.push_back(fac);
	cout << "Faculty creation for " << fName << " success.\n";
	return success;
      }	
  
  cout << "Error: Department ID Does not exist - cannot create faculty.\n" << endl;
  return failure; 
}

//----------------------------------------------------------------------------
/*!!
bool University::RemoveAFaculty(long fFactId)
{
  /*
    - check if the fFactId passed to this method is a valid existing faculty id. If not
      return failure; otherwise,
      - search and remove the faculty from the Faculties vector only if this faculty is not 
        teaching a course nor advising any student, nor chairing any department
	- return success
  }
!!*/

//----------------------------------------------------------------------------
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  /*
    - This routine should list all the courses (courseId and CourseName)
      that are currently being taught by a particular faculty 
      - make sure that the facultyId passed to this method is a valid existing 
        faculty id. If this is not the case print appropriate message and return failure; 
	  otherwise, return success

  */
  for(int i = 0; i < Faculties.size(); i++)
      if(Faculties[i].getid() == facultyId)
	{
	  cout << endl << Faculties[i].getname() << " teaches:\n";

	  for(int j = 0; j < Courses.size(); j++)
	    if(Courses[j].getistaughtby() == Faculties[i].getid())
	      {
		cout << setw(7) << Courses[j].getname() << " ";
		cout << setw(5) << Courses[j].getcrn() << endl;
	      }

	  cout << endl;
	  return success;
	}

  cout << "Error: Faculty Does Not Exist - cannot list courses.\n" << endl;
  return failure;
}

//----------------------------------------------------------------------------
bool University::ListCoursesTakenByStudent(long studentId)
{
  /*
    - This routine lists all the courses (courseId and CourseName) 
      that currently taken by a particular student
      - make sure that the studentId passed to this method is a valid existing 
        student id. If this is not the case print appropriate message and return failure; 
	  otherwise, return success

  */

  //if student found, list their courses
  for(int i = 0; i < Students.size(); i++)
    if(Students[i].getid() == studentId)
      {
	cout << Students[i].getname() << " has taken:\n";	
	
	for(int j = 0; j < Students[i].getcourses().size(); j++)
	  cout << Students[i].getcourses()[j].getname() << endl;

	cout << endl;
	return success;
      }

  cout << "Error: Student ID Does not exist - cannot list courses.\n" << endl;
  return failure;
}

//----------------------------------------------------------------------------
bool University::ListFacultiesInDepartment (long departId)
{
  /*
    - This routine lists all the faculties (facultyId, facultyName) in a particular 
      department
    - make sure that the departId passed to this method is a valid existing 
    department id. If this is not the case print appropriate message and return failure; 
  otherwise, return success

*/
  for(int i = 0; i < Departments.size(); i++)
    if(Departments[i].getid() == departId)
      {
	cout << "The faculties in the " << Departments[i].getname();
	cout << " departments are:\n";

	for(int j = 0; j < Faculties.size(); j++)
	  if(Faculties[j].getdepartid() == departId)
	    {
	      cout << setw(15) << Faculties[j].getname() << " ";
	      cout << setw(10) << Faculties[j].getid() << endl;
	    }
	cout << endl;
	return success;
      }
  cout << "Error: Departments Does Not Exist - cannot list faculties\n" << endl;
  return failure;
}

//----------------------------------------------------------------------------
bool University::ListStudentsOfAFaculty(long facultyId)
{
  /*
    - This routine lists all the students (studentId and studentName) of a particular 
      faculty
      - make sure that the facultyId passed to this method is a valid existing 
        faculty id. If this is not the case print appropriate message and return failure; otherwise, 
	  return success
	    
  */
  for(int i = 0; i < Faculties.size(); i++)
    if(Faculties[i].getid() == facultyId)
      {
	cout << "Students for " << Faculties[i].getname() << ":\n";

	for(int j = 0; j < Students.size(); j++)
	  if(Students[j].getadvisorid() == Faculties[i].getid())
	    {
	      cout << Students[j].getname() << " ";
	      cout << Students[j].getid();
	      cout << endl;
	    }
	return success;
      }

  cout << "Error: Faculty does not exist - cannot list students.\n" << endl;
  return failure;
}

//----------------------------------------------------------------------------
bool University::ListCoursesOfADepartment(long departId)
{
  /*
    - This routine lists all the courses offered by a particular department
    - make sure that the departId passed to this method is a valid existing 
      department id. If this is not the case print appropriate message and return failure; otherwise, 
        return success
  */

  for(int i = 0; i < Departments.size(); i++)
    if(Departments[i].getid() == departId)
      {
	cout << "Courses in the " << Departments[i].getname();
	cout << " department are:\n";

	for(int j = 0; j < Courses.size(); j++)
	  if(Courses[j].getdepartid() == departId)
	    cout << Courses[j].getname() << endl;
	cout << endl;
	return success;
      }

  cout << "Error: Departments Does Not Exist - cannot list courses!" << endl;
  return failure;
}

//----------------------------------------------------------------------------
bool University::AddACourseForAStudent(long courseId, long stId)
{
  /*
    - This routine adds a course for a student
    - When you add a course for a student, you need to ensure that there is enough seat in that class
      Increment the number of assigned seats if you could enroll the student for this course
      - make sure that the courseId and stId passed to this method are both valid 
        If this is not the case print appropriate message and return failure; otherwise, 
	  return success
  */

  for(int i = 0; i < Students.size(); i++)
    if(Students[i].getid() == stId)
      {
	for(int j = 0; j < Courses.size(); j++)
	  if(Courses[j].getcrn() == courseId)
	    {
	      if(Courses[j].getassignedseats() < Courses[j].getmaxseats())
		{
		  Students[i].getcourses().push_back(Courses[j]);
		  cout << "Course addition for " << Students[i].getname() << "success.\n";
		  return success;
		}
	    }
      }

  cout << "Error: Student ID Does not exist - cannot add course.\n" << endl;
  return failure;
}

//----------------------------------------------------------------------------
/*!!
bool University::DropACourseForAStudent(long courseId, long stId)
{
  /*
    - This routine drops a course for a student
    - When you drop a course for a student, you need to decrement the number of assigned 
      seats for that course
      - make sure that the courseId and stId passed to this method are both valid 
        If this is not the case print appropriate message and return failure; otherwise, 
	  return success
}  
!!*/


//----------------------------------------------------------------------------
bool University::AssignDepartmentChair(long facultyId, long departId)
{
  /*
    - This routine assigns a chair to a department
    - make sure that the facultyId and departId passed to this method are both valid 
      If this is not the case print appropriate message and return failure; otherwise, 
        return success
  */
  for(int i = 0; i < Departments.size(); i++)
    if(Departments[i].getid() == departId)
      {
        for(int j = 0; j < Faculties.size(); j++)
          if(Faculties[j].getid() == facultyId)
	    {
	      Departments[i].assignChair(facultyId);
	      cout << "Chair assignment for " << Departments[i].getname() << " success.\n";
	      return success;
	    }
      }

  cout << "Error: Department or faculty does not exist – cannot assign chair.\n";

  return failure;
}

//----------------------------------------------------------------------------
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  /*
    - This routine assigns a course to an instructor to teach
    - make sure that the courseId and facultyId passed to this method are both valid.
    If this is not the case print appropriate message and return failure; otherwise, 
									      return success
*/
  for(int i = 0; i < Courses.size(); i++)
    if(Courses[i].getcrn() == courseId)
      {
	for(int j = 0; j < Faculties.size(); j++)
	  if(Faculties[j].getid() == facultyId)
	    {
	      Courses[i].assignInstructor(facultyId);
	      cout << "Instructor assignment for " << Courses[i].getdepartid() << " success.\n";
	      return success;
	    }
      }

  cout << "Error: Course or faculty Does not exists - cannot assign instructor.\n";

  return failure;
}

//----------------------------------------------------------------------------
bool University::ListDepartments()
{
  /*
    - This method should list the department id's and department names only
  */
  cout << "DEPARTMENTS:\n";
  for(int i = 0; i < Departments.size(); i++)
    {
      cout << left;
      cout << setw(15) << Departments[i].getname();
      cout << setw(10) << Departments[i].getid();
      cout << endl;
    }
  cout << endl;
  return success;
}

//----------------------------------------------------------------------------
bool University::ListStudents()
{
  /*
    - This method should list the student id's and student names only
  */
  cout << "STUDENTS:\n";
  for(int i = 0; i < Students.size(); i++)
    {
      cout << left;
      cout << setw(15) << Students[i].getname();
      cout << setw(10) << Students[i].getid();
      cout << endl;
    }
  cout << endl;
  return success;
}

//----------------------------------------------------------------------------
bool University::ListCourses()
{
  /*
    - This method should list the course id's and course names only
  */
  cout << "COURSES:\n";
  for(int i = 0; i < Courses.size(); i++)
    {
      cout << left;
      cout << setw(10) << Courses[i].getname();
      cout << setw(10) << Courses[i].getcrn();
      cout << endl;
    }
  cout << endl;
  return success;
}

//----------------------------------------------------------------------------
bool University::ListFaculties()
{
  cout << "FACULTIES:\n";
  for(int i = 0; i < Faculties.size(); i++)
    {
      cout << left;
      cout << setw(15) << Faculties[i].getname();
      cout << setw(10) << Faculties[i].getdepartid();
      cout << endl;
    }
  cout << endl;
  return success;
}

//----------------------------------------------------------------------------
bool University::ProcessTransactionFile (string fileName)
{
  string function;
  string name, email, address, DOB, gender, major;
  long YOS, salary, ID;

  ifstream fin;
  fin.open("TransactionFile.txt");

  if(!fin)
    return failure;
  
  cout << endl;
  while(fin >> function)
    {
      if(function == "CreateNewDepartment")
	{
	  fin >> name;
	  fin >> address;
	  fin >> ID;
	  CreateNewDepartment(name, address, ID);
	}
      else if(function == "ListDepartments")
	{
	  ListDepartments();
	}
      else if(function == "CreateNewFaculty")
	{
	  fin >> name;
	  fin >> email;
	  fin >> address;
	  fin >> DOB;
	  fin >> gender;
	  fin >> YOS;
	  fin >> salary;
	  fin >> ID;
	  CreateNewFaculty(name, email, address, DOB, gender, YOS, salary, ID);
	}
      else if(function == "ListFaculties")
	{	
	  ListFaculties();
	}
      else if(function == "ListFacultiesInDepartment")
	{
	  fin >> ID;
	  ListFacultiesInDepartment(ID);
	}
      else if(function == "CreateNewStudent")
	{
	  fin >> name;
	  fin >> email;
	  fin >> address;
	  fin >> DOB;
	  fin >> gender;
	  fin >> YOS;
	  fin >> major;
	  fin >> ID;
	  CreateNewStudent(name, email, address, DOB, gender, YOS, major, ID);
	}
      else if(function == "ListStudents")
	{
	  ListStudents();
	}
      else if(function == "ListStudentsOfAFaculty")
	{
	  fin >> ID;
	  ListStudentsOfAFaculty(ID);
	}
      else if(function == "CreateNewCourse")
	{
	  fin >> name;
	  fin >> YOS;
	  fin >> salary;
	  fin >> ID;
	  CreateNewCourse(name, YOS, salary, ID);
	}
      else if(function == "ListCourses")
	{
	  ListCourses();
	}
      else if(function == "ListCoursesTaughtByFaculty")
	{
	  fin >> ID;
	  ListCoursesTaughtByFaculty(ID);
	}
      else if(function == "ListCoursesOfADepartment")
	{
	  fin >> ID;
	  ListCoursesOfADepartment(ID);
	}
      else if(function == "AddACourseForAStudent")
	{
	  fin >> YOS;
	  fin >> ID;
	  AddACourseForAStudent(YOS, ID);
	}
      else if(function == "ListCoursesTakenByStudent")
	{
	  fin >> ID;
	  ListCoursesTakenByStudent(ID);
	}
      else if(function == "AssignDepartmentChair")
	{
	  fin >> YOS;
	  fin >> ID;
	  AssignDepartmentChair(YOS, ID);
	}
      else if(function == "AssignInstructorToCourse")
	{
	  fin >> YOS;
	  fin >> ID;
	  AssignInstructorToCourse(YOS, ID);
	}
      else
	{ cout << "ERROR!!! CHECK METHOD OR FILE!!!\n"; return failure;}
    }
  return success;
}

//----------------------------------------------------------------------------
int main() 
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");
}

//-------------------------------------------------------------------------
#endif
