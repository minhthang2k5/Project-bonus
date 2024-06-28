#ifndef _TEACHER_H_
#define _TEACHER_H_
#include "struct.h"
#pragma warning(disable : 4996)
// function List Year
listYear createListYear();
void eatline();
// void addClass(listYear *&lY);
// void displayClass(nodeClass *head);
void viewListStudentIncourse(nodeCourse*p);
bool checkNameSemester(nodeSemester* p, int name);
bool checkNumber(char a);
void detachedYear(int &begin, int &last, string year);
void addHeadNewSchoolYear(listYear &lY);
void inputDateInSemester(int &day, int &month, int &year);
nodeSemester *initSemester();
void addHeadSemester(listSemester &list, nodeSemester *p);
void inputInformationSemesterAndAddSchoolYear(schoolYear* &temp);
void writeSemester(listSemester ls, string name);
void readListYear(const char* name, listYear& lY);
void writeListYear(const char* name, listYear ls);
void readSenester(listYear &ls);
schoolYear* getSchoolYear(listYear lY, string name);
nodeSemester* getSemester(schoolYear* year, int name);
nodeCourse* getCourse(nodeSemester* ls, string name);
void readListCourse(listYear& ls);
void writeListCourse(listCourse lc, string name);
void writeListStudentInCourse(StudentList* slist, string name);
void readListStudentToCourse(listYear& ls);
void viewListCourse(nodeSemester* p);
struct Staff_Info
{
	string fullname;
	Date birthday;
	string username;
	string password;
	string email;
	int gender;
};

struct Staff_Node
{
	Staff_Info staff;
	Staff_Node* pNext;
};

struct Staff_List
{
	Staff_Node* pHead;
};
int CheckFullName(string fullname);
bool isLeapYear(int y);
int CheckDate(Date d);
int CheckUsername(string username);
int CheckPassword(string password);
int CheckEmail(string email);
bool isDifferentUsername(Staff_List l, string username);
bool isDifferentPassword(Staff_List l, string password);
Staff_Info GetStaffInfo(Staff_List l);
Staff_Node *CreateNewNode(Staff_Info info);
void Init(Staff_List &l);
void AddTail(Staff_List &l, Staff_Info info);
void PrintStaffInfo(Staff_Info info);
void PrintList(Staff_List l);
int SignUp(Staff_List &l, const char* warehousepath);
int GetStaffAccount(Staff_List l, string inUsername, string inPassword);
int SignIn(Staff_List l);

int StaffAccountDataWarehouse(Staff_List l, const char* warehousepath);
int LoadStaffAccount(Staff_List &l, const char* warehousepath);
int ChangePasswordOfStaff(Staff_List& l, const char* warehousepath);

// function of course
nodeCourse *initCourse();

void addHeadCourse(listCourse &listC, nodeCourse *p);
void inputInformationToAddCourse(nodeSemester*& tempSemester, schoolYear* current);

void updateInformationCourse(nodeCourse* &course, nodeSemester* curSemester, schoolYear* curYear);

void addStudentToCourse(nodeCourse* course, nodeSemester* curSemester, schoolYear* curYear);

// void removeStudentFromCourse(nodeCourse *course);
// void deleteCourse(nodeCourse *course);

// typedef void removeOneCourseOutOfCourseList(listCourse *courseList);

void inputClassToAddSchoolYear(listYear &lY);

void viewListOfClasses(listYear lY);
void viewListOfStudentClass(listYear lY);
void viewListOfCourses(listYear lY);
void removeNodeCourse(listCourse& ls, nodeCourse* p);
void deleteCourse(nodeSemester* tempSemester, schoolYear* current, nodeCourse* course);
#endif