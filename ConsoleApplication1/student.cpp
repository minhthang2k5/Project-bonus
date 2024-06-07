#include "student.h"
#include "teacher.h"

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
