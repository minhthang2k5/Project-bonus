#include "teacher.h"
#include "student.h"
#include "class.h"
void eatline()
{
	cin.ignore();
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
void addHeadNewSchoolYear(listYear &lY)
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
		schoolYear *temp = new schoolYear;
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
void inputDateInSemester(int &day, int &month, int &year)
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
/*
hàm này để nhập thông tìn một khóa học
Input:Danh sách các năm học
Output:không có
*/
void inputInformationSemesterAndAddSchoolYear(listYear &lY)
{
	// Kiểm tra năm học nào để luu vào một node: temp
	string year;
	int begin;
	int last;
	cout << "Input school year to add semester: ";
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

	// Nhập năm học để thêm vào
	nodeSemester *seme = initSemester();
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





