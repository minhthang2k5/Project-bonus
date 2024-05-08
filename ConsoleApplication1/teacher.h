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