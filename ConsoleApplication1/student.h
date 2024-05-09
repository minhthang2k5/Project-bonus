#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include "teacher.h"
#include "class.h"
using namespace std;

struct Date
{
    int day, month, year;
};

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

#endif