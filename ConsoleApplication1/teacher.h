#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "student.h"
#pragma warning(disable : 4996)
struct Date
{
	int day, month, year;
};
struct nodeCourse
{
	string id;
	string courseName;
	string className;
	string teacher;
	int numberOfCredits;
	int numberOfStudent;
	string dayOfweek;
	string session;
	StudentList *studentList;
	nodeCourse *next;
};
struct listCourse
{
	nodeCourse *head;
};
struct nodeSemester
{
	// ky 1,2 hay 3
	listCourse listCour;
	int name;
	Date begin;
	Date end;
	nodeSemester *next;
};
struct listSemester
{
	nodeSemester *head;
};
struct nodeClass
{
	string name;
	// list student
	nodeClass *next;
};
struct schoolYear
{
	int beginYear;
	int lastYear;
	listSemester listSem;
	schoolYear *next;
};
struct listYear
{
	schoolYear *pHead;
};
// function List Year
listYear creatListYear();
void eatline();
void addClass(listYear *&lY);
void displayClass(nodeClass *head);
bool checkNumber(char a);
void detachedYear(int &begin, int &last, string year);
void addHeadNewSchoolYear(listYear &lY);
void inputDateInSemester(int &day, int &month, int &year);
nodeSemester *initSemester();
void addHeadSemester(listSemester &list, nodeSemester *p);
void inputInformationSemesterAndAddSchoolYear(listYear &lY);

struct Teacher_Info
{
	string fullname;
	Date birthday;
	string username;
	string password;
	string email;
	int gender;
};

struct Teacher_Node
{
	Teacher_Info teacher;
	Teacher_Node *pNext;
};

struct Teacher_List
{
	Teacher_Node *pHead;
};
int CheckFullName(string fullname);
bool isLeapYear(int y);
int CheckDate(Date d);
int CheckUsername(string username);
int CheckPassword(string password);
int CheckEmail(string email);
bool isDifferentUsername(Teacher_List l, string username);
bool isDifferentPassword(Teacher_List l, string password);
Teacher_Info GetTeacherInfo(Teacher_List l);
Teacher_Node *CreateNewNode(Teacher_Info info);
void Init(Teacher_List &l);
void AddTail(Teacher_List &l, Teacher_Info info);
void PrintTeacherInfo(Teacher_Info info);
void PrintList(Teacher_List l);
int SignUp(Teacher_List &l);

int GetTeacherAccount(Teacher_List l, string inUsername, string inPassword);
int SignIn(Teacher_List l);

// function of course
nodeCourse *initCourse();
void addHeadCourse(listCourse &listC, nodeCourse *p);
void inputInformationToAddCourse(listYear &lY);
void updateInformationCourse(listYear &lY);
void addStudentToCourse(nodeCourse *course);

void viewCourseInformation(nodeCourse *course);
void viewListOfCoursesInformation(listCourse *courseList);
void viewStudentsOfCourse(nodeCourse *course);
void removeStudentFromCourse(nodeCourse *course);
void deleteCourse(nodeCourse *course);

typedef void removeOneCourseOutOfCourseList(listCourse *courseList);