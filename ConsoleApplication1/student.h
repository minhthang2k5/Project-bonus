#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "struct.h"
Student getStudentInfo();
StudentNode* CreateNewNode(Student info);
void AddTailToStudentList(StudentList* l, Student info);

SignInInfo GetSignInInfo(Student stu);
NodeAccount* CreateAccountForStudent(SignInInfo info);
void AddTailToStudentAccountList(ListAccount* l, SignInInfo info);
ListAccount* CreateListAccount(ClassList* cl);
#endif
