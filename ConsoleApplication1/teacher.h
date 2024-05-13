#pragma once
using namespace std;
#include <iostream>
#include <string>
//#include "student.h"
#pragma warning(disable:4996)
struct nodeClass
{
	char* name;
	//list student
	nodeClass* next;
};
struct schoolYear
{
	int beginYear;
	int lastYear;
	nodeClass* listClass;
	schoolYear* next;
};
struct listYear
{
	schoolYear* pHead;
};
listYear* creatListYear();
void eatline();
void addClass(listYear*& lY);
void displayClass(nodeClass* head);
bool checkNumber(char a);
void detachedYear(int& begin, int& last, string year);
void addHeadNewSchoolYear(listYear*& lY);
struct Date 
{
	int day, month, year;
};

struct Teacher_Info {
	string fullname;
	Date birthday;
	string username;
	string password;
	string email;
	int gender;
};

struct Teacher_Node {
	Teacher_Info teacher;
	Teacher_Node* pNext;
};

struct Teacher_List {
	Teacher_Node* pHead;
};
listYear* creatListYear();
int CheckFullName(string fullname);
bool isLeapYear(int y);
int CheckDate(Date d);
int CheckUsername(string username);
int CheckPassword(string password);
int CheckEmail(string email);
bool isDifferentUsername(Teacher_List l, string username);
bool isDifferentPassword(Teacher_List l, string password);
Teacher_Info GetTeacherInfo(Teacher_List l);
Teacher_Node* CreateNewNode(Teacher_Info info);
void Init(Teacher_List& l);
void AddTail(Teacher_List& l, Teacher_Info info);
void PrintTeacherInfo(Teacher_Info info);
void PrintList(Teacher_List l);
int SignUp(Teacher_List& l);

int GetTeacherAccount(Teacher_List l, string inUsername, string inPassword);
int SignIn(Teacher_List l);
