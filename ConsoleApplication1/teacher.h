#pragma once
using namespace std;
#include <iostream>
#include "student.h"
#pragma warning(disable:4996)
struct schoolYear
{
	int beginYear;
	int lastYear;
};
struct nodeClass
{
	char* name;
	nodeClass* next;
};
void eatline();
void addClass(nodeClass*& head);
void displayClass(nodeClass* head);

struct Date {
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

int CheckFullName(string fullname);
bool isLeapYear(int y);
int CheckDate(Date d);
int CheckUsername(string username);
int CheckPassword(string password);
int CheckEmail(string email);
Teacher_Info GetTeacherInfo();
Teacher_Node* CreateNewNode(Teacher_Info info);
void Init(Teacher_List& l);
void AddTail(Teacher_List& l, Teacher_Info info);
void PrintTeacherInfo(Teacher_Info info);
void PrintList(Teacher_List l);
int SignUp(Teacher_List& l);