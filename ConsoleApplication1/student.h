#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "class.h"
#include "teacher.h"
#include <iostream>
using namespace std;

struct Date
{
	int day, month, year;
};

struct FullName
{
	string firstName;
	string lastName;
};

struct Student
{
	string className;
	int studentID;
	FullName fullName;
	string gender;
	Date dateOfBirth;
	int socialID;
};

struct StudentNode
{
	Student data;
	StudentNode *pNextStudent;
};

struct StudentList
{
	int numberOfStudents;
	StudentNode *pHeadStudent;
};

struct SignInInfo {
	string username;
	string password;
};

struct NodeAccount
{
	SignInInfo info;
	NodeAccount* next;
};

struct ListAccount {
	NodeAccount* head;
};

Student getStudentInfo();
StudentNode* CreateNewNode(Student info);
void AddTailToStudentList(StudentList* l, Student info);

SignInInfo GetSignInInfo(Student stu);
NodeAccount* CreateAccountForStudent(SignInInfo info);
void AddTailToStudentAccountList(ListAccount* l, SignInInfo info);
ListAccount* CreateListAccount(ClassList* cl);
#endif
