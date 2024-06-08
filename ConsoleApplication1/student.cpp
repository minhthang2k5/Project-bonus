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
