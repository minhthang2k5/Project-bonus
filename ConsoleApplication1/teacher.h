#ifndef _TEACHER_H_
#define _TEACHER_H_
#include "struct.h"
#pragma warning(disable : 4996)
// function List Year
listYear createListYear();
void eatline();
// void addClass(listYear *&lY);
// void displayClass(nodeClass *head);
bool checkNumber(char a);
void detachedYear(int &begin, int &last, string year);
void addHeadNewSchoolYear(listYear &lY);
void inputDateInSemester(int &day, int &month, int &year);
nodeSemester *initSemester();
void addHeadSemester(listSemester &list, nodeSemester *p);
void inputInformationSemesterAndAddSchoolYear(listYear &lY);

int CheckFullName(string fullname);
bool isLeapYear(int y);
int CheckDate(Date d);
int CheckUsername(string username);
int CheckPassword(string password);
int CheckEmail(string email);
bool isDifferentUsername(Staff_List l, string username);
bool isDifferentPassword(Staff_List l, string password);
Staff_Info GetStaffInfo(Staff_List l);
Staff_Node *CreateNewNode(Staff_Info info);
void Init(Staff_List &l);
void AddTail(Staff_List &l, Staff_Info info);
void PrintStaffInfo(Staff_Info info);
void PrintList(Staff_List l);
int SignUp(Staff_List &l);
int GetStaffAccount(Staff_List l, string inUsername, string inPassword);
int SignIn(Staff_List l);

// function of course
nodeCourse *initCourse();
void addHeadCourse(listCourse &listC, nodeCourse *p);
void inputInformationToAddCourse(listYear &lY);

void updateInformationCourse(listYear &lY);
void addStudentToCourse(nodeCourse *course);

// void removeStudentFromCourse(nodeCourse *course);
// void deleteCourse(nodeCourse *course);

// typedef void removeOneCourseOutOfCourseList(listCourse *courseList);

void inputClassToAddSchoolYear(listYear &lY);

void viewListOfClasses(listYear lY);
void viewListOfStudentClass(listYear lY);
void viewListOfCourses(listYear lY);
#endif