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
    unsigned int studentNum;
    Student *studentList;
};

void readStudentsOfClassFromCSVFile(string fileName, Class *newClass);

#endif