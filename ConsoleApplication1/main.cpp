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
	// viết hàm add student list từ file csv vào cái tiếp cái student list đã có sẵn trước đó
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
							string nameStudent;
							cout << "Input your name: ";
							cin.ignore();
							getline(cin, nameStudent);
							viewListOfCoursesForStudent(curSemester, nameStudent);
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
								cout << "3. Create a semester" << endl;
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
									cin.ignore();
									getline(cin, className);
									Class *newClass = createClass(className, 0);
									noPointerAddClassIntoClassList(current->listClass, newClass);
									createEmptyClassCSVFile(current, className);
									cout << "Add new class successfully!" << endl;
									cout << current->listClass.pHeadClass->className << endl;
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
										if (curClass == nullptr)
										{
											break;
										}
									}
									if (curClass == nullptr)
									{
										cout << "Not found class!" << endl;
									}
									else
									{
										cout << "Input student information:" << endl;
										Student stu = inputStudentInformation();
										addStudentIntoClass(curClass, stu);
										noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
										writeClassIntoCSVFile(current, curClass);
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
										cout << "2. View list course" << endl;
										cout << "3. Choose course to operate" << endl;
										cout << "0. Back" << endl;
										cout << "-1. Exit" << endl;
										cout << "Your choice: ";

										cin >> choice4;
										if (choice4 == 2)
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

										if (choice4 == 3)
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
											int choice5;
											do
											{
												cout << "1.  Add a student to course" << endl;
												cout << "2.  Update information course" << endl;
												cout << "3.  View list student of course:" << endl;
												cout << "4. Add other students by uploading CSV file" << endl;
												cout << "0.  Back" << endl;
												cout << "-1. Exit" << endl;
												cout << "Your choice: ";
												cin >> choice5;
												if (choice5 == 4)
												{
													string studentListFileName;
													cout << "Input file name: ";
													getline(cin, studentListFileName);
													StudentList *newStudentList = readStudentsOfCourseFromCSVFile(studentListFileName);
													appendNewStudentListToCurrentStudentList(curCourse->studentList, newStudentList);
													writeStudentListEnrollCourseToCSVFile(curCourse, curSemester, current);
												}
												if (choice5 == 3)
												{
													viewListStudentIncourse(curCourse);
												}
												if (choice5 == 2)
												{
													updateInformationCourse(curCourse, curSemester, current);
												}
												if (choice5 == 1)
												{
													addStudentToCourse(curCourse, curSemester, current);
												}
											} while (choice5 != -1);
										}

									} while (choice4 != -1);
								}
								if (choice3 == 5)
								{
									cout << "Input class name: ";
									string className4;
									cin.ignore();
									getline(cin, className4);
									Class *curClass = current->listClass.pHeadClass;
									while (curClass->className != className4)
									{
										curClass = curClass->pNextClass;
										if (curClass == nullptr)
										{
											break;
										}
									}
									if (curClass == nullptr)
									{
										cout << "Not found class!" << endl;
									}
									else
									{
										string fileName;
										do
										{
											cout << "Input file name (class name + \".csv\"): ";
											getline(cin, fileName);
											if (className4 != extractFileName(fileName))
											{
												cout << "File name must be \"class name + .csv\"" << endl;
											}
										} while (className4 != extractFileName(fileName));

										Class *newClass = readStudentsOfClassFromCSVFile(fileName);
										if (newClass != nullptr)
										{
											appendNewStudentsOfClassToCurrentClass(curClass, newClass);
											writeClassIntoCSVFile(current, curClass);
											cout << endl;
											noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
										}
										else
										{
											cout << "Class is empty or error while opening file!" << endl;
										}
									}
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