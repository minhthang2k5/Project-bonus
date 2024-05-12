#ifndef _CLASS_H_
#define _CLASS_H_

#include "student.h"
#include "teacher.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

struct Class
{
    string className;
    int numberOfStudents;
    Student* pHeadStudent;
    Class *pNextClass;
};

struct ClassList
{
    Class *pHeadClass;
};

Student *createStudent(int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1);
Class *createClass(string className1, int numberOfStudents1);
ClassList *createClassList();
void addStudentIntoClass(Class *class1, Student *stu1);
void addClassIntoClassList(ClassList *claList1, Class *class1);

void readStudentsOfClassFromCSVFile(string fileName, Class *newClass);

#endif