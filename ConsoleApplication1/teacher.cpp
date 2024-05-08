#pragma once
#include "teacher.h"

void eatline()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void addClass(nodeClass* &head)
{
	head = new nodeClass();
	cout << "Input the class name: ";
	char name[50];
	cin.getline(name, 50);
	head->name = new char[strlen(name) - 1];
	strcpy(head->name, name);
	head->next = NULL;
	while (4==4)
	{
		cout << "Intput the class name next ( <enter> to quit): ";
		cin.getline(name, 50);
		if (name[0] == '\0')
		{
			break;
		}
		nodeClass* temp = new nodeClass;
		temp->name = new char[strlen(name) - 1];
		strcpy(temp->name, name);
		temp->next = head;
		head = temp;
	}
}
void displayClass(nodeClass* head)
{
	while (head!=NULL)
	{
		cout << head->name << endl;
		head = head->next;
	}
}