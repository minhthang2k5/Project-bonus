#include "teacher.h"
#include "student.h"
#include "class.h"
listYear ls;
ListAccount *accstudent;
Staff_List accstaff;
const char *warehousepath1 = "Saveaccount/accountforstaff.txt";
const char *warehousepath2 = "Saveaccount/accountforstudent.txt";
int main()
{
	ls.pHead = NULL;
	int check1 = LoadStaffAccount(accstaff, warehousepath1);
	int check2 = LoadStudentAccount(accstudent, warehousepath2);
	readListYear("listYear/listYear.txt", ls);
	readSenester(ls);
	readListCourse(ls);
	readListStudentToCourse(ls);
	readClassAll(ls);
	int choice;
	do
	{
		cout << "Choose type of user: " << endl;
		cout << "1. Student" << endl;
		cout << "2. Staff" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		system("cls");
		int choice1 = -2;
		do
		{
			// menu cho student

			if (choice == 1)
			{
				cout << "1. Sign in" << endl;
				cout << "0. Back" << endl;
				cout << "-1. Exit" << endl;
				cout << "Your choice: ";

				cin >> choice1;
				system("cls");
				if (choice1 == 1)
				{
					int check1 = Login(accstudent);
					int choice2;
					do
					{
						// các chức năng của sinh viên
						cout << "1. View your profile" << endl;
						cout << "2. Change the password" << endl;
						cout << "3. View your list of course" << endl;
						cout << "4. View your scoreboard" << endl;
						cout << "5. Sign out" << endl;
						cout << "0. Exit" << endl;
						cout << "Your choice:";
						cin >> choice2;
						system("cls");
						if (choice2 == 5)
						{
							cout << "Sign out successfully" << endl;
							break;
						}
						if (choice2 == 0)
						{
							cout << "Exit successfully!" << endl;
							return 1;
						}
						if (choice2 == 3)
						{
							string yearName;
							cin.ignore();
							cout << "Input school year: ";
							getline(cin, yearName);
							// lấy node school year để thực hiện các chức năng dưới
							schoolYear *current = getSchoolYear(ls, yearName);
							while (current == NULL)
							{
								cout << "School year isn't exited" << endl;
								cout << "Input again";
								getline(cin, yearName);
								current = getSchoolYear(ls, yearName);
							}
							int semesterName;
							cout << "Input semester: ";
							cin >> semesterName;
							// lấy node semester để thực hiện các chức năng dưới
							nodeSemester *curSemester = getSemester(current, semesterName);
							while (curSemester == NULL)
							{
								cout << "Semester isn't exited" << endl;
								cout << "Input again";
								cin >> semesterName;
								curSemester = getSemester(current, semesterName);
							}
							viewListOfCoursesForStudent(curSemester);
						}
						if (choice2 < 0 || choice2 > 5)
						{
							cout << "Invalid choice" << endl;
							break;
						}
					} while (choice2 != -1);
				}
				if (choice1 == -1)
				{
					cout << "Exit successfully!" << endl;
					return 1;
				}
				if (choice1 == 0)
				{
					break;
				}
			}

			// menu cho staff
			if (choice == 2)
			{
				cout << "1. Sign up" << endl;
				cout << "2. Sign in" << endl;
				cout << "0. Back" << endl;
				cout << "-1. Exit" << endl;
				cout << "Your choice: ";
				cin >> choice1;
				system("cls");
				if (choice1 == 1)
				{
					int check1 = SignUp(accstaff, warehousepath1);
					system("cls");
					continue;
				}

				if (choice1 == 2)
				{
					int check2 = SignIn(accstaff);
					int choice2;
					do
					{
						// các chức của staff
						cout << "1.Create a school year" << endl;
						cout << "2.Choose school year to operate" << endl;
						cout << "3.Back" << endl;
						cout << "4.Exit" << endl;
						cout << "Your choice:";
						cin >> choice2;
						cin.ignore();
						if (choice2 == 1)
						{
							addHeadNewSchoolYear(ls);
							writeListYear("listYear/listYear.txt", ls);
						}
						if (choice2 == 2)
						{
							string yearName;
							cout << "Input school year: ";
							getline(cin, yearName);
							// lấy node school year để thực hiện các chức năng dưới
							schoolYear *current = getSchoolYear(ls, yearName);
							while (current == NULL)
							{
								cout << "School year isn't exited" << endl;
								cout << "Input again";
								getline(cin, yearName);
								current = getSchoolYear(ls, yearName);
							}
							system("cls");
							int choice3;
							do
							{
								cout << "1. Create new class" << endl;
								cout << "2. Add a student into class" << endl;
								cout << "3. Creat a semester" << endl;
								cout << "4. Choose a semester" << endl;
								cout << "5. Read all student of a class from CSV file" << endl;
								cout << "6. Choose a semester" << endl;
								cout << "7. View list of classes" << endl;
								cout << "8. View list of students of a class" << endl;
								cout << "9. View scoreboard of a class" << endl;
								cout << "0. Back" << endl;
								cout << "-1. Exit" << endl;
								cout << "Your choice: ";

								cin >> choice3;
								cin.ignore();
								if (choice3 == -1)
								{
									cout << "Exit successfully!" << endl;
									return 1;
								}
								if (choice3 == 0)
								{
									continue;
								}
								if (choice3 == 1)
								{
									string className;
									cout << "Input class name: ";
									cin >> className;
									Class *newClass = createClass(className, 0);
									noPointerAddClassIntoClassList(current->listClass, newClass);
									createEmptyClassCSVFile(current, className);
									cout << "Add new class successfully!" << endl;
								}
								if (choice3 == 2)
								{
									cout << "Input class name: ";
									string className4;
									cin.ignore();
									getline(cin, className4);
									Class *curClass = current->listClass.pHeadClass;
									while (curClass->className != className4)
									{
										curClass = curClass->pNextClass;
									}
									cout << "Input student information:" << endl;
									Student stu = inputStudentInformation();

									int opt1;
									cout << "1. Save this student" << endl;
									cout << "2. Don't save this student" << endl;
									cout << "0. Back" << endl;
									cout << "-1. Exit" << endl;
									do
									{
										cout << "Input choice: ";
										cin >> opt1;
										if (opt1 != 1 && opt1 != 2 && opt1 != -1 && opt1 != 0)
										{
											cout << "Invalid choice!" << endl;
										}
									} while (opt1 != 1 && opt1 != 2 && opt1 != -1 && opt1 != 0);
									if (opt1 == 1)
									{
										addStudentIntoClass(curClass, stu);
										noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
										writeClassIntoCSVFile(current, curClass);
									}
									else if (opt1 == 2)
									{
										break;
									}
									else if (opt1 == 0)
									{
										break;
									}
									else if (opt1 == -1)
									{
										return 0;
									}
									else
									{
										cout << "Invalid choice!" << endl;
									}
								}
								if (choice3 == 3)
								{
									inputInformationSemesterAndAddSchoolYear(current);
								}
								if (choice3 == 4)
								{
									int semesterName;
									cout << "Input semester: ";
									cin >> semesterName;
									// lấy node semester để thực hiện các chức năng dưới
									nodeSemester *curSemester = getSemester(current, semesterName);
									while (curSemester == NULL)
									{
										cout << "Semester isn't exited" << endl;
										cout << "Input again";
										cin >> semesterName;
										curSemester = getSemester(current, semesterName);
									}
									system("cls");
									int choice4;
									// menu các chức năng của course
									do
									{
										cout << "1. Create and add course to semester" << endl;
										cout << "2. Add a student to course" << endl;
										cout << "3.View list course" << endl;
										cout << "4. Update information course" << endl;
										cout << "5. View list student of course:" << endl;
										cout << "0. Back" << endl;
										cout << "-1. Exit" << endl;
										cout << "Your choice: ";

										cin >> choice4;
										if (choice4 == 5)
										{
											viewListStudentIncourse(curSemester);
										}
										if (choice4 == 3)
										{
											viewListCourse(curSemester);
										}
										if (choice4 == -1)
										{
											cout << "Exit successfully!" << endl;
											return 1;
										}
										if (choice4 == 0)
										{
											break;
										}
										if (choice4 == 1)
										{
											inputInformationToAddCourse(curSemester, current);
											system("cls");
										}
										if (choice4 == 2)
										{
											cin.ignore();
											string Coursename;
											cout << "Input course name: ";
											getline(cin, Coursename);
											nodeCourse *curCourse = getCourse(curSemester, Coursename);
											while (curCourse == NULL)
											{
												cout << "Course isn't exited" << endl;
												cout << "Input again";
												getline(cin, Coursename);
												curCourse = getCourse(curSemester, Coursename);
											}
											addStudentToCourse(curCourse, curSemester, current);
										}
										if (choice4 == 4)
										{
											cin.ignore();
											string Coursename;
											cout << "Input course name: ";
											getline(cin, Coursename);
											nodeCourse *curCourse = getCourse(curSemester, Coursename);
											while (curCourse == NULL)
											{
												cout << "Course isn't exited" << endl;
												cout << "Input again";
												getline(cin, Coursename);
												curCourse = getCourse(curSemester, Coursename);
											}
											updateInformationCourse(curCourse, curSemester, current);
										}
									} while (choice4 != -1);
								}
								if (choice3 == 5)
								{
									string fileName;
									cout << "Input file name (class name + \".csv\"): ";
									cin >> fileName;
									Class *newClass = readStudentsOfClassFromCSVFile(fileName);
									cout << "sl" << newClass->numberOfStudents << endl;
									noPointerAddClassIntoClassList(current->listClass, newClass);
									writeClassIntoCSVFile(current, newClass);
									cout << endl;
									cout << "Input file name (class name + \".csv\"): ";
									cin >> fileName;
									Class *newClass1 = readStudentsOfClassFromCSVFile(fileName);
									cout << "sl" << newClass1->numberOfStudents << endl;
									noPointerAddClassIntoClassList(current->listClass, newClass1);
									writeClassIntoCSVFile(current, newClass1);
									noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
								}
							} while (choice3 != -1);
						}
						if (choice2 == 3)
						{
							system("cls");
							break;
						}
						if (choice2 == 4)
						{
							return 1;
						}
						system("cls");
					} while (choice2 != -1);
				}
				if (choice1 == -1)
				{
					cout << "Exit successfully!" << endl;
					return 1;
				}
				if (choice1 == 0)
				{
					break;
				}
			}
			if (choice == 0)
			{
				cout << "Exit successfully!" << endl;
				return 1;
			}
			if (choice < 0 || choice > 2)
			{
				cout << "Invalid choice" << endl;
				break;
			}
		} while (choice < 0 || choice > 2);
	} while (choice >= 0 && choice <= 2);
	system("pause");
	return 0;
}