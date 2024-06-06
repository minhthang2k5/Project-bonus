#ifndef _STUDENT_H_
#define _STUDENT_H_

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

struct Student_Info
{
	string fullname;
	Date birthday;
	string username;
	string password;
	string email;
	int gender;
	int id;
	int form;
	string sclass;
	int faculty;
};

struct Student_Node
{
	Student_Info student;
	Student_Node *pNext;
};

struct Student_List
{
	Student_Node *pHead;
};

int checkFullName(string fullname);
int checkDate(Date d);
int checkUsername(string username);
int checkPassword(string password);
int checkEmail(string email);
bool isDifferentUsername(Student_List l, string username);
bool isDifferentPassword(Student_List l, string password);
Student_Info getStudentInfo(Student_List l);
Student_Node *createNewNode(Student_Info info);
void init(Student_List &l);
void addTail(Student_List &l, Student_Info info);
void printStudentInfo(Student_Info info);
void printList(Student_List l);
int signUp(Student_List &l);

int getStudentAccount(Student_List l, string inUsername, string inPassword);
int signIn(Student_List l);

// c�c h�m cho StudentList
Student getStudentInfo();
StudentNode *createNewNode(Student info);
void addTail(StudentList *&l, Student info);

void viewListCourseOfSpecificStudent(nodeSemester sem);

#endif
