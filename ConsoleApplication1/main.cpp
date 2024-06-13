#include "teacher.h"
#include "student.h"
#include "class.h"

int main()
{
	// Hàm hiển thị là staff hay student

	// // if là staff
	// //--
	// Staff_List staffList;
	// Init(staffList);
	// SignUp(staffList);
	// cout << endl;
	// PrintList(staffList);
	// //--
	// SignIn(staffList);

	// // Neu la student
	// //--
	// Class *CTT523 = readStudentsOfClassFromCSVFile("23CTT5.csv");
	// cout << CTT523->pHeadStudent->pNextStudent->data.studentID << endl;
	// ClassList *classList = createClassList(1);
	// addClassIntoClassList(classList, CTT523);
	// ListAccount *accountList = CreateListAccount(classList);
	// PrintListAccount(accountList);
	// cout << endl;
	// //---- dang nhap student
	// Login(accountList);

	//// Tao nam hoc
	listYear yearList = createListYear();
	addHeadNewSchoolYear(yearList);
	schoolYear* check = yearList.pHead;
	while (check!=NULL)
	{
		cout << check->beginYear << "-" << check->lastYear<<endl;
		check = check->next;
	}
	inputInformationSemesterAndAddSchoolYear(yearList);
	//inputInformationSemesterAndAddSchoolYear(yearList);
	nodeSemester* checkSemester = yearList.pHead->listSem.head;
	while (checkSemester!=NULL)
	{
		cout << checkSemester->name << endl;
		cout << "Begin: ";
		cout << checkSemester->begin.day << "-" << checkSemester->begin.month << "_" << checkSemester->begin.year << endl;
		cout << "End: ";
		cout << checkSemester->end.day << "-" << checkSemester->end.month << "_" << checkSemester->end.year << endl;
		checkSemester = checkSemester->next;
	}
	inputInformationToAddCourse(yearList);
	inputInformationToAddCourse(yearList);
	nodeCourse* checkCourse = yearList.pHead->listSem.head->listCour.head;
	while (checkCourse != NULL)
	{
		cout << checkCourse->courseName << endl;
		checkCourse = checkCourse->next;
	}
	system("pause");

	return 0;
}