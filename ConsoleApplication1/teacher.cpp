#pragma once
#include "teacher.h"
void eatline()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
listYear creatListYear()
{
	listYear p;
	p.pHead = NULL;
	return p;
}
bool checkNumber(char a)
{
	if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void detachedYear(int& begin, int& last, string year)
{
	string sBegin;
	string sLast;
	int start;
	bool flag = true;
	int end;
	for (int i = 0; i < year.size(); i++)
	{
		if (checkNumber(year[i]) == true && flag == true)
		{
			start = i;
			flag = false;
		}
		if (checkNumber(year[i]) == false && flag == false)
		{
			end = i;
			break;
		}

	}
	sBegin = year.substr(start, end - start);
	flag = true;
	for (int i = end; i < year.size(); i++)
	{
		if (checkNumber(year[i]) == true && flag == true)
		{
			start = i;
			flag = false;
		}
		if (checkNumber(year[i]) == false && flag == false)
		{
			end = i;
			break;
		}

	}
	sLast = year.substr(start, end - start);
	begin = stoi(sBegin);
	last = stoi(sLast);
}
void addHeadNewSchoolYear(listYear& lY)
{
	cout << "Input the school year:";
	string year;
	getline(cin, year);
	int begin, last;
	detachedYear(begin, last, year);
	if (lY.pHead == NULL)
	{
		lY.pHead = new schoolYear;
		lY.pHead->beginYear = begin;
		lY.pHead->lastYear = last;
		lY.pHead->listSem.head = NULL;
		lY.pHead->next = NULL;
	}
	else
	{
		schoolYear* temp = new schoolYear;
		temp->beginYear = begin;
		temp->lastYear = last;
		lY.pHead->listSem.head = NULL;
		temp->next = lY.pHead;
		lY.pHead = temp;
	}
}
/*
void addClass(listYear*& lY)
{
	string year;
	int begin;
	int last;
	cout << "Input school year to add class: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear* temp = lY->pHead;
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

	nodeClass* head = new nodeClass();
	cout << "Input the class name: ";
	string name;
	getline(cin,name);
	head->name = name;
	head->next = NULL;
	while (4 == 4)
	{
		cout << "Intput the class name next ( <enter> to quit): ";
		getline(cin, name);
		if (name == "")
		{
			break;
		}
		nodeClass* temp = new nodeClass;
		temp->name = name;
		temp->next = head;
		head = temp;
	}
	temp->listClass = head;
}

void displayClass(nodeClass* head)
{
	while (head != NULL)
	{
		cout << head->name << endl;
		head = head->next;
	}
}

*/
/*
hàm này để tách ngày tháng năm khi nhap bằng một string
Input: ngày tháng năm cần được tách
Output:Không có
VD: nhập 21-12-2005 thì nó se tách 
day=21
month=12
year=2005
*/
void inputDateInSemester(int& day, int& month, int& year)
{
	string DATE;
	getline(cin, DATE);
	int count = 0;
	int i = 0;
	while (count != 3)
	{
		if (checkNumber(DATE[i]) == true && count == 0)
		{
			day = stoi(DATE.substr(i, 2));
			i = i + 2;
			count++;
		}
		else if (checkNumber(DATE[i]) == true && count == 1)
		{
			month = stoi(DATE.substr(i, 2));
			i = i + 2;
			count++;
		}
		else if (checkNumber(DATE[i]) == true && count == 2)
		{
			year = stoi(DATE.substr(i, DATE.length() - i));
			i = i + 1;
			count++;
		}
		else
		{
			i++;
		}
	}
}
/*
hàm này để khởi tạo một kì học
Input:Không có
Output:Một node kì học mới 
*/
nodeSemester *initSemester()
{
	nodeSemester* p = new nodeSemester;
	p->next = NULL;
	return p;
}
/*
hàm này để thêm kỳ học vào danh sách các kỳ học bằng cách thêm vào đầu
Input:Danh sách kỳ hoc,node kỳ học
Output:Không có
*/
void addHeadSemester(listSemester &list, nodeSemester* p)
{
	if (list.head==NULL)
	{
		list.head = p;
	}
	else
	{
		p->next = list.head;
		list.head = p;
	}
}
/*
hàm này để nhập thông tìn một khóa học
Input:Danh sách các năm học
Output:không có
*/
void inputInformationSemesterAndAddSchoolYear(listYear & lY)
{
	//Kiểm tra năm học nào để luu vào một node: temp
	string year;
	int begin;
	int last;
	cout << "Input school year to add semester: ";
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


	//Nhập năm học để thêm vào
	nodeSemester* seme = initSemester();
	cout << "Input the name semester 1,2 or 3:";
	cin >> seme->name;
	eatline();
	cout << "Input the start date: ";
	inputDateInSemester(seme->begin.day, seme->begin.month, seme->begin.year);
	cout << endl;
	cout << "Input the end date: ";
	inputDateInSemester(seme->end.day, seme->end.month, seme->end.year);
	cout << endl;
	seme->listCour.head = NULL;
	addHeadSemester(temp->listSem, seme);
}
/*
Hàm này để khởi tạo khóa học
Input:không có
Output:Một khóa học mới
*/
nodeCourse* initCourse()
{
	nodeCourse* p = new nodeCourse;
	p->next = NULL;
	return p;
}
/*
hàm này để thêm danh sách lớp học vào khóa học
Input:Danh sách các khóa học,Node khóa học
output:Không có
*/
void addHeadCourse(listCourse& listC, nodeCourse* p)
{
	if (listC.head==NULL)
	{
		listC.head = p;
		return;
	}
	p->next = listC.head;
	listC.head = p;
}
/*
hàm này để nhập thông tin khóa học
Input:Danh sách các năm học
Output:không có
1*/
void inputInformationToAddCourse(listYear& lY)
{
	//Dò tới năm học cần thêm
	string year;
	int begin;
	int last;
	cout << "Input school year to add course: ";
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
	
	//Dò tới kỳ học cần thêm
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
	
	//Nhập các thông tin và thêm vào kỳ học
	nodeCourse* course = initCourse();
	cout << "Input id course: ";
	getline(cin, course->id);
	cout << endl;
	cout << "Input course name: ";
	getline(cin, course->courseName);
	cout << endl;
	cout << "Input class name: ";
	getline(cin, course->className);
	cout << endl;
	cout << "Input teacher name: ";
	getline(cin, course->teacher);
	cout << endl;
	cout << "Input number of credits: ";
	cin >> course->numberOfCredits;
	cout << endl;
	eatline();
	cout << "Input number of student(max 50): ";
	cin >> course->numberOfStudent;
	while (course->numberOfStudent>50)
	{
		cout << "exceed the allowed number of students to enter"<<endl;
		cout << "Input number of student(max 50):";
		cin >> course->numberOfStudent;
	}
	eatline();
	cout << "Input the day of week: ";
	getline(cin, course->dayOfweek);
	cout << endl;
	cout << "Input the session" << endl;
	cout << "Choose a seesion:"<<endl;
	cout << "S1 (07:30)" << endl;
	cout << "S2 (09:30)" << endl;
	cout << "S3 (13:30)" << endl;
	cout << "S4 (15:30)" << endl;
	getline(cin, course->session);
	addHeadCourse(tempSemester->listCour, course);

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
			p = p->pNext;
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
			p = p->pNext;
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

int GetTeacherAccount(Teacher_List l, string inUsername, string inPassword) {
	
	if (l.pHead == NULL) {
		return 0;
	}
	else {
		Teacher_Node* p = l.pHead;
		while (p != NULL) {
			if (p->teacher.username == inUsername && p->teacher.password == inPassword) {
				return 1;
			}
			p = p->pNext;
		}
	}
	return 0;
}

int SignIn(Teacher_List l) {
	string inUsername;
	string inPassword;

	cout << "Input your username: ";
	cin >> inUsername;
	cout << "Input your password: ";
	cin >> inPassword;
	if (GetTeacherAccount(l, inUsername, inPassword) == 1) {
		cout << "Sign in successfully!" << endl;
	}
	while (GetTeacherAccount(l, inUsername, inPassword) == 0) {
		system("cls");
		cout << "Username or password maybe incorrect! Please try again!" << endl;
		cout << "Input your username: ";
		cin >> inUsername;
		cout << "Input your password: ";
		cin >> inPassword;
		if (GetTeacherAccount(l, inUsername, inPassword) == 1) {
			cout << "Sign in successfully!" << endl;
		}
	}
	return 1;
}