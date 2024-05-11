#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include "teacher.h"
#include "class.h"
using namespace std;

//struct Date
//{
//    int day, month, year;
//};

struct StudentFullName
{
    string firstName;
    string lastName;
};

enum Gender
{
    male,
    female
};

struct Student
{
    Class studentClass;
    unsigned int studentID;
    StudentFullName name;
    Gender gender;
    Date dateOfBirth;
    unsigned int socialID;
};


struct Student_Info {
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

struct Student_Node {
	Student_Info student;
	Student_Node* pNext;
};

struct Student_List {
	Student_Node* pHead;
};

int checkFullName(string fullname);
int checkDate(Date d);
int checkUsername(string username);
int checkPassword(string password);
int checkEmail(string email);
Student_Info getStudentInfo();
Student_Node* createNewNode(Student_Info info);
void init(Student_List& l);
void addTail(Student_List& l, Student_Info info);
void printStudentInfo(Student_Info info);
void printList(Student_List l);
int signUp(Student_List& l);
#endif