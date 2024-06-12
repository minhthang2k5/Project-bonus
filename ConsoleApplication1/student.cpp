#include "student.h"
Student getStudentInfo() {
	Student info;
	cout << "Input classname: ";
	getline(cin, info.className);
	cout << "Input student ID: ";
	cin >> info.studentID;
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
StudentNode* CreateNewNode(Student info) {
	StudentNode* s = new StudentNode;
	s->data = info;
	s->pNextStudent = NULL;
	return s;
}
void AddTailToStudentList(StudentList* l, Student info) {
	StudentNode* student = CreateNewNode(info);
	if (l->pHeadStudent == NULL) {
		l->pHeadStudent = student;
	}
	else {
		StudentNode* p = l->pHeadStudent;
		while (p->pNextStudent != NULL) {
			p = p->pNextStudent;
		}
		p->pNextStudent = student;
	}
}

SignInInfo GetSignInInfo(Student stu) {
	SignInInfo info;
	info.username = to_string(stu.studentID);
	info.password = "random@#" + to_string(stu.studentID);
	return info;
}
NodeAccount* CreateAccountForStudent(SignInInfo info) {
	NodeAccount* acc = new NodeAccount;
	acc->info = info;
	acc->next = NULL;
	return acc;
}
void AddTailToStudentAccountList(ListAccount* l, SignInInfo info) {
	NodeAccount* acc = CreateAccountForStudent(info);
	if (l->head == NULL) {
		l->head = acc;
	}
	else {
		NodeAccount* p = l->head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = acc;
	}
}
ListAccount* CreateListAccount(ClassList* cl) {
	ListAccount* l = new ListAccount;
	l->head = NULL;
	Class* pcl = cl->pHeadClass;
	StudentNode* pstu = cl->pHeadClass->pHeadStudent;
	while (pcl != NULL) {
		while (pstu != NULL) {
			SignInInfo temp = GetSignInInfo(pstu->data);
			AddTailToStudentAccountList(l, temp);
			pstu = pstu->pNextStudent;
		}
		pcl = pcl->pNextClass;
	}
	return l;
}
void PrintListAccount(ListAccount* l) {
	NodeAccount* p = l->head;
	while (p != NULL) {
		cout << p->info.username << endl;
		cout << p->info.password << endl;
	}
}
int GetStudentAccount(ListAccount* l, string inUsername, string inPassword) {
	if (l->head == NULL)
	{
		return 0;
	}
	else
	{
		NodeAccount* p = l->head;
		while (p != NULL)
		{
			if (p->info.username == inUsername && p->info.password == inPassword)
			{
				return 1;
			}
			p = p->next;
		}
	}
	return 0;
}
int Login(ListAccount* l) {
	string inUsername;
	string inPassword;

	cout << "Input your username: ";
	cin >> inUsername;
	cout << "Input your password: ";
	cin >> inPassword;
	if (GetStudentAccount(l, inUsername, inPassword) == 1)
	{
		cout << "Sign in successfully!" << endl;
	}
	while (GetStudentAccount(l, inUsername, inPassword) == 0)
	{
		system("cls");
		cout << "Username or password maybe incorrect! Please try again!" << endl;
		cout << "Input your username: ";
		cin >> inUsername;
		cout << "Input your password: ";
		cin >> inPassword;
		if (GetStudentAccount(l, inUsername, inPassword) == 1)
		{
			cout << "Sign in successfully!" << endl;
		}
	}
	return 1;
}

void viewListOfCourses(listYear lY) {
	// Dò tới năm học chứa course cần sửa
	string year;
	int begin;
	int last;
	cout << "Input school year to view: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear* temp = lY.pHead;
	bool checkExitsYear = false;
	while (temp != NULL)
	{
		if (temp->beginYear == begin)
		{
			checkExitsYear = true;
			break;
		}
		temp = temp->next;
	}
	if (checkExitsYear == false)
	{
		cout << "The school year isn't exit";
		return;
	}

	// Dò tới kỳ học chứa course cần sửa
	nodeSemester* tempSemester = temp->listSem.head;
	int nameSemester;
	cout << "Input the name semester(1,2 or 3): ";
	cin >> nameSemester;
	eatline();
	bool checkexitsSemester = false;
	while (tempSemester != NULL)
	{
		if (tempSemester->name == nameSemester)
		{
			checkexitsSemester = true;

			break;
		}
		tempSemester = tempSemester->next;
	}
	if (checkexitsSemester == false)
	{
		cout << "The semester isn't exit";
		return;
	}
	nodeCourse* tempCourse = tempSemester->listCour.head;
	while (tempCourse != NULL) {
		cout << tempCourse->courseName << endl;
		tempCourse = tempCourse->next;
	}
}