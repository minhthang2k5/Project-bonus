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
	readScoreboard(ls);
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
				cout << "1.  Sign in" << endl;
				cout << "0.  Back" << endl;
				cout << "-1. Exit" << endl;
				cout << "Your choice: ";

				cin >> choice1;
				system("cls");
				if (choice1 == 1)
				{
					int check1 = Login(accstudent);
					cout << endl;
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
						cout << "Your choice: ";
						cin >> choice2;
						system("cls");
						if (choice2 == 2)
						{
							ChangePasswordOfStudent(accstudent, warehousepath2);
						}
						if (choice2 == 4)
						{
							string yearName;
							cin.ignore();
							cout << "Input school year: ";
							getline(cin, yearName);
							// lấy node school year để thực hiện các chức năng dưới
							schoolYear *curYear = getSchoolYear(ls, yearName);
							while (curYear == NULL)
							{
								cout << "School year does not exist!" << endl;
								cout << "Input again: ";
								getline(cin, yearName);
								curYear = getSchoolYear(ls, yearName);
							}
							int semesterName;
							cout << "Input semester: ";
							cin >> semesterName;
							// lấy node semester để thực hiện các chức năng dưới
							nodeSemester *curSem = getSemester(curYear, semesterName);
							while (curSem == NULL)
							{
								cout << "Semester does not exist!" << endl;
								cout << "Input again: ";
								cin >> semesterName;
								curSem = getSemester(curYear, semesterName);
							}

							system("cls");
							viewProfileWhenViewingScoreboard(ls, check1);
							cout << endl;
							viewStudentScoreboard2(ls, check1, curYear, curSem);
							cout << endl
								 << endl
								 << endl;
						}
						if (choice2 == 1)
						{
							cout << endl
								 << endl;
							viewProfile(ls, check1);
							cout << endl
								 << endl;
						}
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
								cout << "School year does not exist!" << endl;
								cout << "Input again: ";
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
								cout << "Semester does not exist!" << endl;
								cout << "Input again: ";
								cin >> semesterName;
								curSemester = getSemester(current, semesterName);
							}

							viewListOfCoursesForStudent(curSemester, check1);
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
				cout << "1.  Sign up" << endl;
				cout << "2.  Sign in" << endl;
				cout << "0.  Back" << endl;
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
						cout << "1.  Create a school year" << endl;
						cout << "2.  Choose school year to operate" << endl;
						cout << "3.  Create list account for student" << endl;
						cout << "4.  Change password" << endl;
						cout << "0.  Back" << endl;
						cout << "-1. Exit" << endl;
						cout << "Your choice: ";
						cin >> choice2;
						cin.ignore();
						if (choice2 == -1)
						{
							return 1;
						}
						if (choice2 == 0)
						{
							break;
							system("cls");
						}
						if (choice2 == 4)
						{
							ChangePasswordOfStaff(accstaff, warehousepath1);

							break;
						}
						if (choice2 == 3)
						{
							ListAccount *l = CreateListAccount(ls, warehousepath2);
							StudentAccountDataWarehouse(l, warehousepath2);
						}
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
								cout << "School year does not exist!" << endl;
								cout << "Input again: ";
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
								if (choice3 == 9)
								{
									cin.ignore();
									cout << "Input class name: ";
									string className2;
									getline(cin, className2);
									Class *curClass = current->listClass.pHeadClass;
									while (curClass->className != className2)
									{
										curClass = curClass->pNextClass;
										if (curClass == nullptr)
										{
											break;
										}
									}
									if (curClass == nullptr)
									{
										cout << "Not found class!" << endl
											 << endl;
									}
									else
									{
										int semesterName;
										cout << "Input semester: ";
										cin >> semesterName;
										// lấy node semester để thực hiện các chức năng dưới
										nodeSemester *curSemester = getSemester(current, semesterName);
										if (curSemester == nullptr)
										{
											cout << "Not found semester" << endl
												 << endl;
										}
										else
										{
											viewClassScoreboard(curClass, curSemester->listCour);
										}
									}
								}
								if (choice3 == 7)
								{
									viewClassListBasicInfo(current->listClass);
								}
								if (choice3 == 8)
								{
									cin.ignore();
									cout << "Input class name: ";
									string className2;
									getline(cin, className2);
									Class *curClass = current->listClass.pHeadClass;
									while (curClass->className != className2)
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
										viewAllStudentsOfClassInfo(curClass);
									}
								}
								if (choice3 == -1)
								{
									cout << "Exit successfully!" << endl;
									return 1;
								}
								if (choice3 == 0)
								{
									break;
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
									system("cls");
									cout << "Add class " << className << " successfully!" << endl
										 << endl;
									noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
								}
								if (choice3 == 2)
								{
									if (current->listClass.pHeadClass == nullptr)
									{
										cout << "School year " << current->beginYear << "-" << current->lastYear << " has no class. Please create 1 class first!" << endl
											 << endl;
									}
									else
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
											// cin.ignore();
											// cout << "Input any keys to start inputing student information: ";
											// string temp;
											// getline(cin, temp);
											cout << "Input student information:" << endl;
											Student stu = inputStudentInformation();
											addStudentIntoClass(curClass, stu);
											noPointerWriteBasicClassListInfoIntoFile(current, current->listClass);
											writeClassIntoCSVFile(current, curClass);
											system("cls");
											cout << "Add new student to the class " << className4 << " successfully!" << endl;
										}
									}
								}
								if (choice3 == 3)
								{
									inputInformationSemesterAndAddSchoolYear(current);
									system("cls");
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
										cout << "Semester does not exist!" << endl;
										cout << "Input again: ";
										cin >> semesterName;
										curSemester = getSemester(current, semesterName);
									}
									system("cls");
									int choice4;
									// menu các chức năng của course
									do
									{
										cout << "1.  Create and add course to semester" << endl;
										cout << "2.  View list course" << endl;
										cout << "3.  Choose course to operate" << endl;
										cout << "0.  Back" << endl;
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
											system("cls");
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
											system("cls");
											while (curCourse == NULL)
											{
												cout << "Course does not exist!" << endl;
												cout << "Input again: ";
												getline(cin, Coursename);
												curCourse = getCourse(curSemester, Coursename);
											}
											int choice5;
											do
											{
												cout << "1.  Add a student to course" << endl;
												cout << "2.  Update information course" << endl;
												cout << "3.  View list student of course" << endl;
												cout << "4.  Add other students by uploading CSV file" << endl;
												cout << "5.  Delete this course" << endl;
												cout << "6.  Remove a student from course" << endl;
												cout << "7.  Upload scoreboard of course" << endl;
												cout << "8.  Export list student in course to CSV File" << endl;
												cout << "9.  View scoreboard of course" << endl;
												cout << "10. Update a student's result in course scoreboard" << endl;
												cout << "0.  Back" << endl;
												cout << "-1. Exit" << endl;
												cout << "Your choice: ";
												cin >> choice5;
												if (choice5 == 10)
												{
													updateStudentResultOfCourse(curCourse, curSemester, current);
												}
												if (choice5 == 9)
												{
													viewCourseScoreboard(curCourse);
												}
												if (choice5 == 8)
												{
													cin.ignore();
													string fileName6;
													cout << "Input file name (.csv) to export: ";
													getline(cin, fileName6);
													exportStudentListFromCourseToCSVFile(fileName6, curCourse);
													system("cls");
												}
												if (choice5 == 7)
												{
													cin.ignore();
													string fileName10;
													cout << "Input file name (.csv): ";
													getline(cin, fileName10);
													importCourseScoreboardFromCSVFile(fileName10, curCourse, current, curSemester);
													system("cls");
												}
												if (choice5 == 6)
												{
													cout << "Input student ID to remove: ";
													int stuID;
													cin >> stuID;
													removeStudentFromCourseByID(curCourse, stuID);
													writeStudentListEnrollCourseToTxtFile(curCourse, curSemester, current);
													system("cls");
												}
												if (choice5 == 5)
												{
													deleteCourse(curSemester, current, curCourse);
													break;
													system("cls");
												}
												if (choice5 == 4)
												{
													cin.ignore();
													string studentListFileName;
													cout << "Input file name (.csv): ";
													getline(cin, studentListFileName);
													StudentList *newStudentList = readStudentsOfCourseFromCSVFile(studentListFileName);
													if (newStudentList == NULL)
													{
														cout << "Error" << endl;
													}
													else
													{
														appendNewStudentListToCurrentStudentList(curCourse->studentList, newStudentList);
														writeStudentListEnrollCourseToTxtFile(curCourse, curSemester, current);
													}
													system("cls");
												}
												if (choice5 == 3)
												{
													viewListStudentIncourse(curCourse);
												}
												if (choice5 == 2)
												{
													cin.ignore();
													updateInformationCourse(curCourse, curSemester, current);
													system("cls");
												}
												if (choice5 == 1)
												{
													cin.ignore();
													addStudentToCourse(curCourse, curSemester, current);
													system("cls");
												}
												if (choice5 == -1)
												{
													return 1;
												}
												if (choice5 == 0)
												{
													system("cls");
													break;
												}
											} while (choice5 != -1);
										}

									} while (choice4 != -1);
								}
								if (choice3 == 5)
								{
									if (current->listClass.pHeadClass == nullptr)
									{
										cout << current->beginYear << "-" << current->lastYear << " has no class. Please create 1 class first!" << endl
											 << endl;
									}
									else
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
								}
							} while (choice3 != -1);
						}
						if (choice2 == 3)
						{
							system("cls");
							break;
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
		} while (choice1 != -1);
		if (choice == 0)
		{
			cout << "Exit successfully!" << endl;
			return 1;
		}
		if (choice == -1)
		{
			return 1;
		}
	} while (choice != -1);
	system("pause");
	return 0;
}