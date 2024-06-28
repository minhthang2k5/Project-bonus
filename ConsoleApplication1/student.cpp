#include "student.h"
Student getStudentInfo()
{
	Student info;
	cout << "Input classname: ";
	getline(cin, info.className);
	cout << "Input student ID: ";
	cin >> info.studentID;
	cin.ignore();
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
StudentNode *CreateNewNode(Student info)
{
	StudentNode *s = new StudentNode;
	s->data = info;
	s->pNextStudent = NULL;
	return s;
}
void AddTailToStudentList(StudentList *l, Student info)
{
	StudentNode *student = CreateNewNode(info);
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

SignInInfo GetSignInInfo(Student stu)
{
	SignInInfo info;
	info.username = to_string(stu.studentID);
	info.password = "random@#" + to_string(stu.studentID);
	return info;
}
NodeAccount *CreateAccountForStudent(SignInInfo info)
{
	NodeAccount *acc = new NodeAccount;
	acc->info = info;
	acc->next = NULL;
	return acc;
}
void AddTailToStudentAccountList(ListAccount *l, SignInInfo info)
{
	NodeAccount *acc = CreateAccountForStudent(info);
	if (l->head == NULL)
	{
		l->head = acc;
	}
	else
	{
		NodeAccount *p = l->head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = acc;
	}
}
ListAccount* CreateListAccount(listYear ls, const char* warehousepath)
{
	ListAccount* l = new ListAccount;
	l->head = NULL;
	schoolYear* pyear = ls.pHead;
	while (pyear != NULL) 
	{
		Class* pcl = pyear->listClass.pHeadClass;
		while (pcl != NULL)
		{
			StudentNode* pstu = pcl->pHeadStudent;
			while (pstu != NULL)
			{
				SignInInfo temp = GetSignInInfo(pstu->data);
				AddTailToStudentAccountList(l, temp);
				pstu = pstu->pNextStudent;
			}
			pcl = pcl->pNextClass;
		}
		pyear = pyear->next;
	}
	
	// +++
	//int check = StudentAccountDataWarehouse(l, warehousepath);
	return l;
}
void PrintListAccount(ListAccount *l)
{
	NodeAccount *p = l->head;
	while (p != NULL)
	{
		cout << p->info.username << endl;
		cout << p->info.password << endl;
		p = p->next;
	}
}
int GetStudentAccount(ListAccount *l, string inUsername, string inPassword)
{
	if (l->head == NULL)
	{
		return 0;
	}
	else
	{
		NodeAccount *p = l->head;
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
int Login(ListAccount *l)
{
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
	return stoi(inUsername);
}

void viewListOfCoursesForStudent(nodeSemester *curSemester)
{
	nodeCourse *temp = curSemester->listCour.head;
	cout << endl
		 << endl
		 << endl
		 << endl;
	cout << left << setw(5) << "ID" << setw(30) << "Course name" << setw(15) << "Class name" << setw(30) << "Teacher name" << setw(30) << "Number of credits/student" << setw(20) << "Day-Sesion" << endl;
	while (temp != NULL)
	{
		string result = to_string(temp->numberOfCredits) + "/" + to_string(temp->numberOfStudent);
		string result2 = temp->dayOfweek + "-" + temp->session;
		cout << left << setw(5) << temp->id << setw(30) << temp->courseName << setw(15) << temp->className << setw(30) << temp->teacher << setw(30) << result << setw(20) << result2 << endl;
		temp = temp->next;
	}
	cout << endl
		 << endl
		 << endl
		 << endl;
}

void StudentAccountDataWarehouse(ListAccount *l, const char *warehousepath)
{
	ofstream dout;
	dout.open(warehousepath, ios::out);
	//dout.seekp(0, ios::beg);
	bool flag = false;
	NodeAccount *p = l->head;
	while (true)
	{
		while (p != NULL)
		{
			dout << p->info.username;
			dout << endl;
			dout << p->info.password;
			dout << endl;
			p = p->next;
		}
		if (p == NULL)
		{
			flag = true;
			break;
		}
	}

	dout.flush();
	dout.close();
}
int LoadStudentAccount(ListAccount *&l, const char *warehousepath)
{
	l = new ListAccount;
	l->head = NULL;
	ifstream din;
	din.open(warehousepath, ios::in);
	bool flag = false;
	while (true)
	{
		SignInInfo tempInfo;
		getline(din, tempInfo.username, '\n');
		getline(din, tempInfo.password, '\n');
		if (din.eof() == true)
		{
			break;
		}
		AddTailToStudentAccountList(l, tempInfo);
	}
	din.close();

	return 0;
}
void ChangePasswordOfStudent(ListAccount *&l, const char *warehousepath)
{
	string inUsername;
	cout << "Input username to change passward: ";
	cin >> inUsername;
	NodeAccount *p = l->head;
	while (p != NULL)
	{
		if (p->info.username == inUsername)
		{
			cout << "Input new password: ";
			cin >> p->info.password;
			break;
		}
		p = p->next;
	}
	StudentAccountDataWarehouse(l, warehousepath);
	cout << "Change successfully!" << endl;
}

bool getNameStudent(StudentList *l, string nameStudent)
{
	StudentNode *p = l->pHeadStudent;
	while (p != NULL)
	{
		string tempName = p->data.fullName.lastName + " " + p->data.fullName.firstName;
		if (tempName == nameStudent)
		{
			return true;
		}
		p = p->pNextStudent;
	}
	return false;
}

void viewListOfCoursesForStudent(nodeSemester *curSemester, string nameStudent)
{
	nodeCourse *temp = curSemester->listCour.head;
	cout << endl
		 << endl
		 << endl
		 << endl;
	cout << left << setw(5) << "ID" << setw(30) << "Course name" << setw(15) << "Class name" << setw(30) << "Teacher name" << setw(30) << "Number of credits/student" << setw(20) << "Day-Sesion" << endl;
	while (temp != NULL)
	{
		if (getNameStudent(temp->studentList, nameStudent))
		{

			string result = to_string(temp->numberOfCredits) + "/" + to_string(temp->numberOfStudent);
			string result2 = temp->dayOfweek + "-" + temp->session;
			cout << left << setw(5) << temp->id << setw(30) << temp->courseName << setw(15) << temp->className << setw(30) << temp->teacher << setw(30) << result << setw(20) << result2 << endl;
		}
		temp = temp->next;
	}
	cout << endl
		 << endl
		 << endl
		 << endl;
}