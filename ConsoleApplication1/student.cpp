#include "student.h"

int checkFullName(string fullname)
{
	int space = 0;
	for (int i = 0; i < fullname.length(); i++)
	{
		if (fullname[i] == ' ')
		{
			space = 1;
		}
	}
	if (space == 0)
	{
		return 0;
	}
	return 1;
}

int checkDate(Date d)
{
	if ((d.day <= 0 && d.day >= 32) || (d.month <= 0 && d.month >= 13) || d.year <= 0)
	{
		return 0;
	}
	if (isLeapYear(d.year))
	{
		switch (d.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d.day >= 32)
			{
				return 0;
			}
		case 2:
			if (d.day >= 30)
			{
				return 0;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (d.day >= 31)
			{
				return 0;
			}
		}
	}
	if (!isLeapYear(d.year))
	{
		switch (d.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d.day >= 32)
			{
				return 0;
			}
		case 2:
			if (d.day >= 29)
			{
				return 0;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (d.day >= 31)
			{
				return 0;
			}
		}
	}
	return 1;
}
int checkUsername(string username)
{
	string test("admin");
	int found = username.find(test);
	if (found != string::npos)
	{
		return 0;
	}
	for (int i = 0; i < username.length(); i++)
	{
		if (username[i] == ' ')
		{
			return 0;
		}
	}
	return 1;
}
int checkPassword(string password)
{
	if (password.length() < 6)
	{
		return 0;
	}
	int upper = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			upper = 1;
		}
	}
	if (upper == 0)
	{
		return 0;
	}
	int character = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			character = 1;
		}
		if (password[i] >= 'a' && password[i] <= 'z')
		{
			character = 1;
		}
	}
	if (character == 0)
	{
		return 0;
	}
	int digit = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= '0' && password[i] <= '9')
		{
			digit = 1;
		}
	}
	if (digit == 0)
	{
		return 0;
	}
	return 1;
}
int checkEmail(string email)
{
	int at = 0;
	int dot = 0;
	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '.')
		{
			dot = 1;
		}
		if (email[i] == '@')
		{
			at = 1;
		}
	}
	if (dot == 0 && at == 0)
	{
		return 0;
	}
	return 1;
}
bool isDifferentUsername(Student_List l, string username)
{
	if (l.pHead == NULL)
	{
		return true;
	}
	else
	{
		Student_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->student.username == username)
			{
				return false;
			}
		}
	}
	return true;
}
bool isDifferentPassword(Student_List l, string password)
{
	if (l.pHead == NULL)
	{
		return true;
	}
	else
	{
		Student_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->student.password == password)
			{
				return false;
			}
		}
	}
	return true;
}
Student_Info getStudentInfo(Student_List l)
{
	Student_Info info;
	cout << "Input your infomation..." << endl;
	cout << "Your fullname: ";
	getline(cin, info.fullname);
	while (checkFullName(info.fullname) == 0)
	{
		cout << "Your fullname is invalid. Please input again!" << endl;
		cout << "Your fullname: ";
		getline(cin, info.fullname);
	}

	cout << "Your email <Type your email without space>: ";
	cin >> info.email;
	while (checkEmail(info.email) == 0)
	{
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
	while (checkDate(info.birthday) == 0)
	{
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

	cout << "Your student ID: ";
	cin >> info.id;
	cin.ignore();

	cout << "Your class: ";
	cin >> info.sclass;

	cout << "1: Regular" << endl;
	cout << "2: APCS" << endl;
	cout << "3: CLC" << endl;
	cout << "Your form of training <Input by number>: ";
	cin >> info.form;

	do
	{
		cout << "1: Faculty of Mathematics and Computer Science" << endl;
		cout << "2: Faculty of Information Technology" << endl;
		cout << "3: Faculty of Physics and Engineering Physics" << endl;
		cout << "4: Faculty of Chemistry" << endl;
		cout << "5: Faculty of Biology and Biotechnology" << endl;
		cout << "6: Faculty of Environment" << endl;
		cout << "7: Faculty of Geology" << endl;
		cout << "8: Faculty of Materials Science and Technology" << endl;
		cout << "9: Faculty of Electronics and Telecommunications" << endl;
		cout << "10: Faculty of Interdisciplinary Science" << endl;
		cout << "Your faculty <Input by number>: ";
		cin >> info.faculty;
		cin.ignore();
	} while (info.faculty <= 0 || info.faculty >= 10);

	cout << "Your username <Type your username without space>: ";
	cin >> info.username;
	while (true)
	{
		if (checkUsername(info.username) == 0)
		{
			cout << "Your username is invalid. Please input again!" << endl;
			cout << "Your username <Type your username without space>: ";
			cin >> info.username;
		}
		if (isDifferentUsername(l, info.username) == false)
		{
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
	while (true)
	{
		if (checkPassword(info.password) == 0)
		{
			cout << "Your password is invalid. Please input again!" << endl;
			cout << "  <At least 6 characters>" << endl;
			cout << "  <At least 1 capital character>" << endl;
			cout << "  <At least 1 digit>" << endl;
			cout << "Your password: ";
			cin >> info.password;
		}
		// cin.ignore();
		if (isDifferentPassword(l, info.password) == false)
		{
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
Student_Node *createNewNode(Student_Info info)
{
	Student_Node *node = new Student_Node;
	node->student = info;
	node->pNext = NULL;

	return node;
}
void init(Student_List &l)
{
	l.pHead = NULL;
}
void addTail(Student_List &l, Student_Info info)
{
	Student_Node *student = createNewNode(info);
	if (l.pHead == NULL)
	{
		l.pHead = student;
	}
	else
	{
		Student_Node *p = l.pHead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = student;
	}
}
void printStudentInfo(Student_Info info)
{
	cout << "Fullname: " << info.fullname << endl;
	cout << "Email: " << info.email << endl;
	cout << "Birthday: " << info.birthday.day << "/" << info.birthday.month << "/" << info.birthday.year << endl;
	if (info.gender == 1)
	{
		cout << "Gender: Male" << endl;
	}
	else if (info.gender == 0)
	{
		cout << "Gender: Female" << endl;
	}

	cout << "ID: " << info.id << endl;

	cout << "Class: " << info.sclass << endl;

	cout << "Form of training: ";
	switch (info.form)
	{
	case 1:
		cout << "Regular" << endl;
		break;
	case 2:
		cout << "APCS" << endl;
		break;
	case 3:
		cout << "CLC" << endl;
		break;
	}

	cout << "Faculty: ";
	switch (info.faculty)
	{
	case 1:
		cout << "Mathematics and Computer Science" << endl;
		break;
	case 2:
		cout << "Information Technology" << endl;
		break;
	case 3:
		cout << "Physics and Engineering Physics" << endl;
		break;
	case 4:
		cout << "Chemistry" << endl;
		break;
	case 5:
		cout << "Biology and Biotechnology" << endl;
		break;
	case 6:
		cout << "Environment" << endl;
		break;
	case 7:
		cout << "Geology" << endl;
		break;
	case 8:
		cout << "Materials Science and Technology" << endl;
		break;
	case 9:
		cout << "Electronics and Telecommunications" << endl;
		break;
	case 10:
		cout << "Interdisciplinary Science" << endl;
		break;
	}
	cout << "Username: " << info.username << endl;
	cout << "Password: " << info.password << endl;
}
void printList(Student_List l)
{
	Student_Node *p = l.pHead;
	while (p != NULL)
	{
		printStudentInfo(p->student);
		cout << endl;
		p = p->pNext;
	}
}
int signUp(Student_List &l)
{
	Student_Info info = getStudentInfo(l);
	addTail(l, info);
	cout << "Sign up successfully!" << endl;
	return 1;
}

int getStudentAccount(Student_List l, string inUsername, string inPassword)
{
	if (l.pHead == NULL)
	{
		return 0;
	}
	else
	{
		Student_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->student.username == inUsername && p->student.password == inPassword)
			{
				return 1;
			}
			p = p->pNext;
		}
	}
	return 0;
}
int signIn(Student_List l)
{
	string inUsername;
	string inPassword;

	cout << "Input your username: ";
	cin >> inUsername;
	cout << "Input your password: ";
	cin >> inPassword;
	if (getStudentAccount(l, inUsername, inPassword) == 1)
	{
		cout << "Sign in successfully!" << endl;
	}
	while (getStudentAccount(l, inUsername, inPassword) == 0)
	{
		system("cls");
		cout << "Username or password maybe incorrect! Please try again!" << endl;
		cout << "Input your username: ";
		cin >> inUsername;
		cout << "Input your password: ";
		cin >> inPassword;
		if (getStudentAccount(l, inUsername, inPassword) == 1)
		{
			cout << "Sign in successfully!" << endl;
		}
	}
	return 1;
}

// c�c h�m cho StudentList

Student getStudentInfo()
{
	Student info;
	cout << "Input classname: ";
	getline(cin, info.className);
	cout << "Input student ID: ";
	cin >> info.studentID;
	eatline();
	cout << "Input firstname: ";
	getline(cin, info.fullName.firstName);
	cout << "Input lastname: ";
	getline(cin, info.fullName.lastName);
	cout << "Input gender: ";
	getline(cin, info.gender);
	cout << "Input date of birth: " << endl;
	cout << "Day: ";
	cin >> info.dateOfBirth.day;
	cout << "Month: ";
	cin >> info.dateOfBirth.month;
	cout << "Year: ";
	cin >> info.dateOfBirth.year;
	cout << "Input social ID: ";
	cin >> info.socialID;
	return info;
}
StudentNode *createNewNode(Student info)
{
	StudentNode *node = new StudentNode;
	node->data = info;
	node->pNextStudent = NULL;

	return node;
}
void addTail(StudentList *&l, Student info)
{
	StudentNode *student = createNewNode(info);
	if (l->pHeadStudent == NULL)
	{
		l->pHeadStudent = student;
	}
	else
	{
		StudentNode *p = l->pHeadStudent;
		while (p->pNextStudent != NULL)
		{
			p = p->pNextStudent;
		}
		p->pNextStudent = student;
	}
}