#include "teacher.h"
#include "student.h"
#include "class.h"
listYear ls;
ListAccount* accstudent;
Staff_List accstaff;
const char* warehousepath1 = "Saveaccount/account.txt";

int main()
{
	ls.pHead = NULL;
	int check1 = LoadStaffAccount(accstaff, warehousepath1);
	int choice;
	do {
		cout << "Choose type of user: " <<endl;
		cout << "1. Student" << endl;
		cout << "2. Staff" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		system("cls");
		int choice1 = -2;
		do {
			// menu cho student 
			
			if (choice == 1) {
				cout << "1. Sign in" << endl;
				cout << "0. Back" << endl;
				cout << "-1. Exit" << endl;
				cout << "Your choice: ";
				
				cin >> choice1;
				system("cls");
				if (choice1 == 1) {
					int check1 = Login(accstudent);
					int choice2;
					do {
						// các chức năng của sinh viên 
						cout << "123" << endl;

						cin >> choice2;
						system("cls");
					} while (choice2 != -1);
				}
				if (choice1 == -1) {
					cout << "Exit successfully!" << endl;
					return 1;
				}
				if (choice1 == 0) {
					break;
				}
				
			}

			// menu cho staff
			if (choice == 2) {
					cout << "1. Sign up" << endl;
					cout << "2. Sign in" << endl;
					cout << "0. Back" << endl;
					cout << "-1. Exit" << endl;
					cout << "Your choice: ";
					cin >> choice1;
					system("cls");
					if (choice1 == 1) {
						int check1 = SignUp(accstaff, warehousepath1);
						system("cls");
						continue;
					}

					if (choice1 == 2) {
						int check2 = SignIn(accstaff);
						int choice2;
						do {
							// các chức của staff 
							cout << "1.Creat a school year" << endl;
							cout << "2.Choose school year to operate" << endl;
							cout << "Your choice:";
							cin >> choice2;
							if (choice1==1)
							{

							}
							system("cls");
						} while (choice2 == -1);
					}
					if (choice1 == -1) {
						cout << "Exit successfully!" << endl;
						return 1;
					}
					if (choice1 == 0) {
						break;
					}
			}
			if (choice == 0) {
				cout << "Exit successfully!" << endl;
				return 1;
			}
			if (choice < 0 || choice >2) {
				cout << "Invalid choice" << endl;
				break;
			}
			
		} while (choice < 0 || choice >2);
	} while (choice >= 0 && choice <=2);
	system("pause");
	return 0;
}