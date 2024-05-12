#pragma once
#include "teacher.h"
void eatline()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void addTailYear(listYear* p)
{




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

int CheckFullName(string fullname) {
	int space = 0;
	for (int i = 0; i < fullname.length(); i++) {
		if (fullname[i] == ' ') {
			space = 1;
		}
	}
	if (space == 0) {
		return 0;
	}
	return 1;
}
bool isLeapYear(int y) {
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
		return true;
	}
	return false;
}
int CheckDate(Date d) {
	if ((d.day <= 0 && d.day >= 32) || (d.month <= 0 && d.month >= 13) || d.year <= 0) {
		return 0;
	}
	if (isLeapYear(d.year)) {
		switch (d.month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (d.day >= 32) {
				return 0;
			}
		case 2:
			if (d.day >= 30) {
				return 0;
			}
		case 4: case 6: case 9: case 11:
			if (d.day >= 31) {
				return 0;
			}
		}
	}
	if (!isLeapYear(d.year)) {
		switch (d.month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (d.day >= 32) {
				return 0;
			}
		case 2:
			if (d.day >= 29) {
				return 0;
			}
		case 4: case 6: case 9: case 11:
			if (d.day >= 31) {
				return 0;
			}
		}
	}
	return 1;
}
int CheckUsername(string username) {
	string test("admin");
	int found = username.find(test);
	if (found != string::npos) {
		return 0;
	}
	return 1;
}
int CheckPassword(string password) {
	if (password.length() < 6) {
		return 0;
	}
	int upper = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			upper = 1;
		}
	}
	if (upper == 0) {
		return 0;
	}
	int character = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			character = 1;
		}
		if (password[i] >= 'a' && password[i] <= 'z') {
			character = 1;
		}
	}
	if (character == 0) {
		return 0;
	}
	int digit = 0;
	for (int i = 0; i < password.length(); i++) {
		if (password[i] >= '0' && password[i] <= '9') {
			digit = 1;
		}
	}
	if (digit == 0) {
		return 0;
	}
	return 1;
}
int CheckEmail(string email) {
	int at = 0;
	int dot = 0;
	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '.') {
			dot = 1;
		}
		if (email[i] == '@') {
			at = 1;
		}
	}
	if (dot == 0 && at == 0) {
		return 0;
	}
	return 1;
}
bool isDifferentUsername(Teacher_List l, string username) {
	if (l.pHead == NULL) {
		return true;
	}
	else {
		Teacher_Node* p = l.pHead;
		while (p != NULL) {
			if (p->teacher.username == username) {
				return false;
			}
		}
	}
	return true;
}

bool isDifferentPassword(Teacher_List l, string password) {
	if (l.pHead == NULL) {
		return true;
	}
	else {
		Teacher_Node* p = l.pHead;
		while (p != NULL) {
			if (p->teacher.password == password) {
				return false;
			}
		}
	}
	return true;
}
Teacher_Info GetTeacherInfo(Teacher_List l) {
	Teacher_Info info;
	cout << "Input your infomation..." << endl;
	cout << "Your fullname: ";
	getline(cin, info.fullname);
	while (CheckFullName(info.fullname) == 0) {
		cout << "Your fullname is invalid. Please input again!" << endl;
		cout << "Your fullname: ";
		getline(cin, info.fullname);
	}

	cout << "Your email <Type your email without space>: ";
	cin >> info.email;
	while (CheckEmail(info.email) == 0) {
		cout << "Your email is invalid. Please input again!" << endl;
		cout << "Your email <Type your email without space>: ";
		cin >> info.email;
	}

	cout << "Your birthday: " << endl;
	cout << "  Day: ";
	cin >> info.birthday.day;
	cout << "  Month: ";
	cin >> info.birthday.month;
	cout << "  Year: ";
	cin >> info.birthday.year;
	while (CheckDate(info.birthday) == 0) {
		cout << "Your birthday is invalid. Please input again!" << endl;
		cout << "Your birthday: ";
		cout << "  Day: ";
		cin >> info.birthday.day;
		cout << "  Month: ";
		cin >> info.birthday.month;
		cout << "  Year: ";
		cin >> info.birthday.year;
	}

	cout << "Your gender <1: male, 0: female>: ";
	cin >> info.gender;
	cin.ignore();

	cout << "Your username <Type your username without space>: ";
	cin >> info.username;
	while (true) {
		if (CheckUsername(info.username) == 0) {
			cout << "Your username is invalid. Please input again!" << endl;
			cout << "Your username <Type your username without space>: ";
			cin >> info.username;
		}
		if (isDifferentUsername(l, info.username) == false) {
			cout << "Your username is invalid. Please input again!" << endl;
			cout << "Your username <Type your username without space>: ";
			cin >> info.username;
		}
		break;
	}

	cout << "  <At least 6 characters>" << endl;
	cout << "  <At least 1 capital character>" << endl;
	cout << "  <At least 1 digit>" << endl;
	cout << "Your password: ";
	cin >> info.password;
	while (true) {
		if (CheckPassword(info.password) == 0) {
			cout << "Your password is invalid. Please input again!" << endl;
			cout << "  <At least 6 characters>" << endl;
			cout << "  <At least 1 capital character>" << endl;
			cout << "  <At least 1 digit>" << endl;
			cout << "Your password: ";
			cin >> info.password;
		}
		//cin.ignore();
		if (isDifferentPassword(l, info.password) == false) {
			cout << "Your password is invalid. Please input again!" << endl;
			cout << "  <At least 6 characters>" << endl;
			cout << "  <At least 1 capital character>" << endl;
			cout << "  <At least 1 digit>" << endl;
			cout << "Your password: ";
			cin >> info.password;
		}
		cin.ignore();
		break;
	}

	return info;
}
Teacher_Node* CreateNewNode(Teacher_Info info) {
	Teacher_Node* node = new Teacher_Node;
	node->teacher = info;
	node->pNext = NULL;

	return node;
}
void Init(Teacher_List& l) {
	l.pHead = NULL;
}
void AddTail(Teacher_List& l, Teacher_Info info) {
	Teacher_Node* teacher = CreateNewNode(info);
	if (l.pHead == NULL) {
		l.pHead = teacher;
	}
	else {
		Teacher_Node* p = l.pHead;
		while (p->pNext != NULL) {
			p = p->pNext;
		}
		p->pNext = teacher;
	}
}

void PrintTeacherInfo(Teacher_Info info) {
	cout << "Fullname: " << info.fullname << endl;
	cout << "Email: " << info.email << endl;
	cout << "Birthday: " << info.birthday.day << "/" << info.birthday.month << "/" << info.birthday.year << endl;
	if (info.gender == 1) {
		cout << "Gender: Male" << endl;
	}
	else if (info.gender == 0) {
		cout << "Gender: Female" << endl;
	}
	cout << "Username: " << info.username << endl;
	cout << "Password: " << info.password << endl;
}
void PrintList(Teacher_List l) {
	Teacher_Node* p = l.pHead;
	while (p != NULL) {
		PrintTeacherInfo(p->teacher);
		cout << endl;
		p = p->pNext;
	}
}

int SignUp(Teacher_List& l) {
	Teacher_Info info = GetTeacherInfo(l);
	AddTail(l, info);
	cout << "Sign up successfully!" << endl;
	return 1;
}