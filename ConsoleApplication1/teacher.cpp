#include "teacher.h"
#include "student.h"
#include "class.h"
void eatline()
{
	cin.ignore();
}
listYear createListYear()
{
	listYear p;
	p.pHead = NULL;
	return p;
}
string changeIntToStringYear(int begin, int end)
{
	string beginN = to_string(begin);
	string endN = to_string(end);
	string year = beginN + "-" + endN;
	return year;
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
void detachedYear(int &begin, int &last, string year)
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
void readListYear(const char* name, listYear& lY)
{
	ifstream iFile;
	iFile.open(name);
	if (!iFile.is_open())
	{
		cout << "can't open file";
		return;
	}
	string nameYear;
	while (getline(iFile, nameYear))
	{
		int begin, last;
		detachedYear(begin, last, nameYear);
		if (lY.pHead == NULL)
		{
			lY.pHead = new schoolYear;
			lY.pHead->beginYear = begin;
			lY.pHead->lastYear = last;
			lY.pHead->listSem.head = NULL;
			lY.pHead->listClass.pHeadClass = NULL;
			lY.pHead->next = NULL;
		}
		else
		{
			schoolYear* temp = new schoolYear;
			temp->beginYear = begin;
			temp->lastYear = last;
			temp->listClass.pHeadClass = NULL;
			temp->listSem.head = NULL; 
			temp->next = lY.pHead;
			lY.pHead = temp;
		}
	}
	iFile.close();
}
schoolYear* getSchoolYear(listYear lY, string name)
{
	int begin;
	int last;
	detachedYear(begin, last, name);
	schoolYear* p = lY.pHead;
	while (p!=NULL)
	{
		if (p->beginYear==begin)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void writeListYear(const char* name, listYear ls)
{
	ofstream oFile;
	oFile.open(name);
	if (!oFile.is_open())
	{
		cout << "can't open file";
		return;
	}
	schoolYear* p = ls.pHead;
	while (p != NULL)
	{
		oFile << p->beginYear << "-" << p->lastYear << endl;
		p = p->next;
	}
	oFile.close();
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
	string nameFolder;
	string beginN = to_string(lY.pHead->beginYear);
	string lastN = to_string(lY.pHead->lastYear);
	nameFolder = "listYear/" + beginN + "-" + lastN;
	const char* nameChar = nameFolder.c_str();
	_mkdir(nameChar);
	//hien folde de up len git
	string gitFile;
	gitFile = nameFolder + "/" + "gitFile.txt";
	ofstream oFile(gitFile);
	oFile << "check";
	oFile.close();
}
// void addClassYear()
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
void inputDateInSemester(int &day, int &month, int &year)
{
	cin.ignore();
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
	nodeSemester *p = new nodeSemester;
	p->next = NULL;
	return p;
}
/*
hàm này để thêm kỳ học vào danh sách các kỳ học bằng cách thêm vào đầu
Input:Danh sách kỳ hoc,node kỳ học
Output:Không có
*/
void addHeadSemester(listSemester &list, nodeSemester *p)
{
	if (list.head == NULL)
	{
		list.head = p;
	}
	else
	{
		p->next = list.head;
		list.head = p;
	}
}
void inputClassToAddSchoolYear(listYear &lY)
{
	// Kiểm tra năm học nào để luu vào một node: temp
	string year;
	int begin;
	int last;
	cout << "Input school year to add class: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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
	Class *a = new Class;
	cout << "Input the class name:";
	getline(cin, a->className);
	cout << "The number of student:";
	cin >> a->numberOfStudents;
	cin.ignore();
	a->pHeadStudent = NULL;
	a->pNextClass = NULL;
	if (lY.pHead->listClass.pHeadClass == NULL)
	{
		lY.pHead->listClass.numberOfClasses = 1;
		lY.pHead->listClass.pHeadClass = a;
	}
	else
	{
		lY.pHead->listClass.numberOfClasses++;
		lY.pHead->listClass.pHeadClass->pNextClass = a;
	}
}
bool checkNameSemester(nodeSemester* p, int name)
{
	while (p!=NULL)
	{
		if (p->name==name)
		{
			return false;
		}
		p = p->next;
	}
	return true;
}
void readSenester(listYear ls)
{
	schoolYear* p = ls.pHead;
	while (p!=NULL)
	{
		string nameYear = changeIntToStringYear(ls.pHead->beginYear, ls.pHead->lastYear);
		string nameInput = "listYear/" + nameYear + "/listSemester.txt";
		ifstream iFile;
		iFile.open(nameInput);
		if (!iFile.is_open())
		{
			cout << "can't open file";
			return;
		}
		nodeSemester* q = new nodeSemester;
		while (iFile >> q->name >> q->begin.day >> q->begin.month >> q->begin.year >> q->end.day >> q->end.month >> q->end.year)
		{
			q->next = NULL;
			addHeadSemester(ls.pHead->listSem, q);
		}
		p = p->next;
	}
}
void writeSemester(listSemester ls,string name)
{
	nodeSemester* p = ls.head;
	name = name + ".txt";
	ofstream oFile(name);
	while (p!=NULL)
	{
		oFile << p->name << endl;
		oFile << p->begin.day << " " << p->begin.month << " " << p->begin.year << endl;
		oFile << p->end.day << " " << p->end.month << " " << p->end.year << endl;
		p = p->next;
	}
	oFile.close();
}
/*
hàm này để nhập thông tìn một khóa học
Input:Danh sách các năm học
Output:không có
*/
void inputInformationSemesterAndAddSchoolYear(schoolYear *temp)
{
	// Nhập năm học để thêm vào
	nodeSemester *seme = initSemester();
	cout << "Input the name semester 1,2 or 3:";
	cin >> seme->name;
	while (checkNameSemester(temp->listSem.head,seme->name)==false)
	{
		cout << "Name semester is exit,pleas input again:";
		cin >> seme->name;
	}
	cout << "Input the start date: ";
	inputDateInSemester(seme->begin.day, seme->begin.month, seme->begin.year);
	cout << endl;
	cout << "Input the end date: ";
	inputDateInSemester(seme->end.day, seme->end.month, seme->end.year);
	cout << endl;
	seme->listCour.head = NULL;
	addHeadSemester(temp->listSem, seme);
	
	//tạo folder
	string name;
	string year = changeIntToStringYear(temp->beginYear, temp->lastYear);
	string nameSemester = to_string(seme->name);
	name = "listYear/" + year + "/" + nameSemester;
	const char* nameChar = name.c_str();
	_mkdir(nameChar);
	//hien folde de up len git
	string gitFile;
	gitFile = "listYear/"+year+"/"+nameSemester + "/" + "gitFile.txt";
	ofstream oFile(gitFile);
	oFile << "check";
	oFile.close();
	//tao file txt
	string nameTxt = "listYear/" + year + "/listSemester";
	writeSemester(temp->listSem, nameTxt);
}

int CheckFullName(string fullname)
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
bool isLeapYear(int y)
{
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
	{
		return true;
	}
	return false;
}
int CheckDate(Date d)
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
int CheckUsername(string username)
{
	string test("admin");
	int found = username.find(test);
	if (found != string::npos)
	{
		return 0;
	}
	return 1;
}
int CheckPassword(string password)
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
int CheckEmail(string email)
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
bool isDifferentUsername(Staff_List l, string username)
{
	if (l.pHead == NULL)
	{
		return true;
	}
	else
	{
		Staff_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->staff.username == username)
			{
				return false;
			}
			p = p->pNext;
		}
	}
	return true;
}
bool isDifferentPassword(Staff_List l, string password)
{
	if (l.pHead == NULL)
	{
		return true;
	}
	else
	{
		Staff_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->staff.password == password)
			{
				return false;
			}
			p = p->pNext;
		}
	}
	return true;
}
Staff_Info GetStaffInfo(Staff_List l)
{
	cin.ignore();
	Staff_Info info;
	cout << "Input your information..." << endl;
	cout << "Your fullname: ";
	getline(cin, info.fullname);
	while (CheckFullName(info.fullname) == 0)
	{
		cout << "Your fullname is invalid. Please input again!" << endl;
		cout << "Your fullname: ";
		getline(cin, info.fullname);
	}

	cout << "Your email <Type your email without space>: ";
	cin >> info.email;
	while (CheckEmail(info.email) == 0)
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
	while (CheckDate(info.birthday) == 0)
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

	cout << "Your username <Type your username without space>: ";
	cin >> info.username;
	while (CheckUsername(info.username) == 0)
	{
		cout << "Your username is invalid. Please input again!" << endl;
		cout << "Your username <Type your username without space>: ";
		cin >> info.username;
	}

	cout << "  <At least 6 characters>" << endl;
	cout << "  <At least 1 capital character>" << endl;
	cout << "  <At least 1 digit>" << endl;
	cout << "Your password: ";
	cin >> info.password;
	while (CheckPassword(info.password) == 0)
	{
		cout << "Your password is invalid. Please input again!" << endl;
		cout << "  <At least 6 characters>" << endl;
		cout << "  <At least 1 capital character>" << endl;
		cout << "  <At least 1 digit>" << endl;
		cout << "Your password: ";
		cin >> info.password;
	}
	cin.ignore();

	return info;
}
Staff_Node *CreateNewNode(Staff_Info info)
{
	Staff_Node *node = new Staff_Node;
	node->staff = info;
	node->pNext = NULL;

	return node;
}
void Init(Staff_List &l)
{
	l.pHead = NULL;
}
void AddTail(Staff_List &l, Staff_Info info)
{
	Staff_Node *staff = CreateNewNode(info);
	if (l.pHead == NULL)
	{
		l.pHead = staff;
	}
	else
	{
		Staff_Node *p = l.pHead;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = staff;
	}
}
void PrintStaffInfo(Staff_Info info)
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
	cout << "Username: " << info.username << endl;
	cout << "Password: " << info.password << endl;
}
void PrintList(Staff_List l)
{
	Staff_Node *p = l.pHead;
	while (p != NULL)
	{
		PrintStaffInfo(p->staff);
		cout << endl;
		p = p->pNext;
	}
}
int SignUp(Staff_List &l, const char* warehousepath)
{

	Staff_Info info = GetStaffInfo(l);
	AddTail(l, info);
	cout << "Sign up successfully!" << endl;
	// +++
	int check = StaffAccountDataWarehouse(l, warehousepath);
	return 1;
}
int GetStaffAccount(Staff_List l, string inUsername, string inPassword)
{
	if (l.pHead == NULL)
	{
		return 0;
	}
	else
	{
		Staff_Node *p = l.pHead;
		while (p != NULL)
		{
			if (p->staff.username == inUsername && p->staff.password == inPassword)
			{
				return 1;
			}
			p = p->pNext;
		}
	}
	return 0;
}
int SignIn(Staff_List l)
{
	string inUsername;
	string inPassword;

	cout << "Input your username: ";
	cin >> inUsername;
	cout << "Input your password: ";
	cin >> inPassword;
	if (GetStaffAccount(l, inUsername, inPassword) == 1)
	{
		cout << "Sign in successfully!" << endl;
	}
	while (GetStaffAccount(l, inUsername, inPassword) == 0)
	{
		system("cls");
		cout << "Username or password maybe incorrect! Please try again!" << endl;
		cout << "Input your username: ";
		cin >> inUsername;
		cout << "Input your password: ";
		cin >> inPassword;
		if (GetStaffAccount(l, inUsername, inPassword) == 1)
		{
			cout << "Sign in successfully!" << endl;
		}
	}
	return 1;
}

int StaffAccountDataWarehouse(Staff_List l, const char* warehousepath) {
	ofstream dout;
	dout.open(warehousepath, ios::out);
	dout.seekp(0, ios::beg);
	bool flag = false;
	Staff_Node* p = l.pHead;
	while (true) {
		while (p != NULL) {
			dout << p->staff.username;
			dout << endl;
			dout << p->staff.password;
			dout << endl;
			p = p->pNext;
		}
		if (p == NULL) {
			flag = true;
			break;
		}
	}

	dout.flush();
	dout.close();

	if (flag == true) {
		return 1;
	}
	return 0;
}
int LoadStaffAccount(Staff_List &l, const char* warehousepath) {
	ifstream din;
	din.open(warehousepath, ios::in);
	bool flag = false;
	if (din.is_open() == false) {
		cout << "Cannot open file!" << endl;
		return 0;
	}
	
	while (true) {
		Staff_Info tempInfo;
		getline(din, tempInfo.username, '\n');
		getline(din, tempInfo.password, '\n');
		if (din.eof() == true) {
			break;
		}
		AddTail(l, tempInfo);
	}
		
	din.close();
	
	return 0;
}
int ChangePasswordOfStaff(Staff_List& l, const char* warehousepath) {
	string inUsername;
	cout << "Input username to change passward: ";
	cin >> inUsername;
	Staff_Node* p = l.pHead;
	while (p != NULL) {
		if (p->staff.username == inUsername) {
			cout << "Input new password: ";
			cin >> p->staff.password;
			break;
		}
		p = p->pNext;
	}
	int check = StaffAccountDataWarehouse(l, warehousepath);
	if (check == 1) {
		cout << "Change successfully!" << endl;
		return 1;
	}
	else {
		cout << "Change unsuccessfully!" << endl;
		return 0;
	}
}

/*
Hàm này để khởi tạo khóa học
Input:không có
Output:Một khóa học mới
*/
nodeCourse *initCourse()
{
	nodeCourse *p = new nodeCourse;
	p->next = NULL;
	return p;
}
/*
hàm này để thêm danh sách lớp học vào khóa học
Input:Danh sách các khóa học,Node khóa học
output:Không có
*/
void addHeadCourse(listCourse &listC, nodeCourse *p)
{
	if (listC.head == NULL)
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
void inputInformationToAddCourse(listYear &lY)
{
	// Dò tới năm học cần thêm
	string year;
	int begin;
	int last;
	cout << "Input school year to add course: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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

	// Dò tới kỳ học cần thêm
	nodeSemester *tempSemester = temp->listSem.head;
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

	// Nhập các thông tin và thêm vào kỳ học
	nodeCourse *course = initCourse();
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
	while (course->numberOfStudent > 50)
	{
		cout << "exceed the allowed number of students to enter" << endl;
		cout << "Input number of student(max 50):";
		cin >> course->numberOfStudent;
	}
	eatline();
	cout << "Input the day of week: ";
	getline(cin, course->dayOfweek);
	cout << endl;
	cout << "Input the session" << endl;
	cout << "Choose a seesion:" << endl;
	cout << "S1 (07:30)" << endl;
	cout << "S2 (09:30)" << endl;
	cout << "S3 (13:30)" << endl;
	cout << "S4 (15:30)" << endl;
	getline(cin, course->session);
	addHeadCourse(tempSemester->listCour, course);
}

void updateInformationCourse(listYear &lY)
{
	// Dò tới năm học chứa course cần sửa
	string year;
	int begin;
	int last;
	cout << "Input school year to add course: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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
	nodeSemester *tempSemester = temp->listSem.head;
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
	// Dò tới course cần sửa
	nodeCourse *tempCourse = temp->listSem.head->listCour.head;
	string identifyCourse; // Định danh course bằng id hoặc tên -> người dùng có thể nhập 1 trong 2
	cout << "Input course id or course name: ";
	getline(cin, identifyCourse, '\n');
	bool checkexitsCourse = false;
	while (tempCourse != NULL)
	{
		if (tempCourse->id == identifyCourse || tempCourse->courseName == identifyCourse)
		{
			checkexitsCourse = true;
			break; // Sau khi break thì tempCourse sẽ là course muốn sửa
		}
		tempCourse = tempCourse->next;
	}
	if (checkexitsCourse == false)
	{
		cout << "The course isn't exit";
		return;
	}
	// Nhập các thông tin và ghi đè vào tempCourse

	cout << "Input id course: ";
	getline(cin, tempCourse->id);
	cout << endl;
	cout << "Input course name: ";
	getline(cin, tempCourse->courseName);
	cout << endl;
	cout << "Input class name: ";
	getline(cin, tempCourse->className);
	cout << endl;
	cout << "Input teacher name: ";
	getline(cin, tempCourse->teacher);
	cout << endl;
	cout << "Input number of credits: ";
	cin >> tempCourse->numberOfCredits;
	cout << endl;
	eatline();
	cout << "Input number of student(max 50): ";
	cin >> tempCourse->numberOfStudent;
	while (tempCourse->numberOfStudent > 50)
	{
		cout << "exceed the allowed number of students to enter" << endl;
		cout << "Input number of student(max 50):";
		cin >> tempCourse->numberOfStudent;
	}
	eatline();
	cout << "Input the day of week: ";
	getline(cin, tempCourse->dayOfweek);
	cout << endl;
	cout << "Input the session" << endl;
	cout << "Choose a seesion:" << endl;
	cout << "S1 (07:30)" << endl;
	cout << "S2 (09:30)" << endl;
	cout << "S3 (13:30)" << endl;
	cout << "S4 (15:30)" << endl;
	getline(cin, tempCourse->session);
}

void addStudentToCourse(nodeCourse *course)
{
	Student info = getStudentInfo();
	AddTailToStudentList(course->studentList, info);
}
void viewListOfClasses(listYear lY)
{
	// Dò tới năm học chứa course cần sửa
	string year;
	int begin;
	int last;
	cout << "Input school year to view: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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
	Class *tempClass = temp->listClass.pHeadClass;
	while (tempClass != NULL)
	{
		cout << tempClass->className << endl;
		tempClass = tempClass->pNextClass;
	}
}
void viewListOfStudentClass(listYear lY)
{
	// Dò tới năm học chứa course cần sửa
	string year;
	int begin;
	int last;
	cout << "Input school year to view: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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
	// Dò tới class cần xem
	string inClassName;
	cout << "Input class to view: ";
	getline(cin, inClassName);
	bool checkExitsClass = false;
	Class *tempClass = temp->listClass.pHeadClass;
	while (tempClass != NULL)
	{
		if (tempClass->className == inClassName)
		{
			checkExitsClass = true;
			break;
		}
	}
	if (checkExitsClass == false)
	{
		cout << "The class isn't exit";
		return;
	}
	StudentNode *tempStudent = tempClass->pHeadStudent;
	while (tempStudent != NULL)
	{
		cout << tempStudent->data.fullName.firstName << " " << tempStudent->data.fullName.lastName << endl;
		tempStudent = tempStudent->pNextStudent;
	}
}
void viewListOfCourses(listYear lY)
{
	// Dò tới năm học chứa course cần sửa
	string year;
	int begin;
	int last;
	cout << "Input school year to view: ";
	getline(cin, year);
	detachedYear(begin, last, year);
	schoolYear *temp = lY.pHead;
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
	nodeSemester *tempSemester = temp->listSem.head;
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
	nodeCourse *tempCourse = tempSemester->listCour.head;
	while (tempCourse != NULL)
	{
		cout << tempCourse->courseName << endl;
		tempCourse = tempCourse->next;
	}
}
