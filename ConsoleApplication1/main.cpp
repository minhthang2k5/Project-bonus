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

	system("pause");
	return 0;
}