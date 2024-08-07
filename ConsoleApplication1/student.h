#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "struct.h"
#include "staff.h"
Student getStudentInfo();
StudentNode* CreateNewNode(Student info);
void AddTailToStudentList(StudentList* l, Student info);

SignInInfo GetSignInInfo(Student stu);
NodeAccount* CreateAccountForStudent(SignInInfo info);
void AddTailToStudentAccountList(ListAccount* l, SignInInfo info);
ListAccount* CreateListAccount(listYear ls, const char* warehousepath);
void PrintListAccount(ListAccount* l); 
int GetStudentAccount(ListAccount* l, string inUsername, string inPassword);
int Login(ListAccount* l);

void StudentAccountDataWarehouse(ListAccount* l, const char* warehousepath);
int LoadStudentAccount(ListAccount*& l, const char* warehousepath);
void ChangePasswordOfStudent(ListAccount*& l, const char* warehousepath);


bool getIdStudent(StudentList* l, int idStudent);
void viewListOfCoursesForStudent(nodeSemester* curSemester, int idStudent);
#endif
