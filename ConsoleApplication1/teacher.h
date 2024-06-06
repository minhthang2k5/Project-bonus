#ifndef _TEACHER_H_
#define _TEACHER_H_
#include <string>
#include "student.h"
#pragma warning(disable : 4996)

struct ScoreboardOfCourse {
	int studentID;
	double otherscore;
	double midscore;
	double finalscore;
	double totalscore;

};

struct NodeScoreboardOfCourse {
	ScoreboardOfCourse scoreboard;
	NodeScoreboardOfCourse* next;
};

struct ListScoreboardOfCourse {
	NodeScoreboardOfCourse* head;
};

struct nodeCourse
{
	string id;
	string courseName;
	string className;
	string teacher;
	int numberOfCredits;
	int numberOfStudent;
	string dayOfweek;
	string session;
	ListScoreboardOfCourse* scoreList;
	StudentList *studentList;
	nodeCourse *next;
};

struct listCourse
{
	nodeCourse *head;
};

struct nodeSemester
{
	// ky 1,2 hay 3
	listCourse listCour;
	int name;
	Date begin;
	Date end;
	nodeSemester *next;
};

struct listSemester
{
	nodeSemester *head;
};

//struct nodeClass
//{
//	string name;
//	// list student
//	nodeClass *next;
//};

struct schoolYear
{
	int beginYear;
	int lastYear;
	listSemester listSem;
	schoolYear *next;
};

struct listYear
{
	schoolYear *pHead;
};

// function List Year
listYear creatListYear();
void eatline();
//void addClass(listYear *&lY);
//void displayClass(nodeClass *head);
bool checkNumber(char a);
void detachedYear(int &begin, int &last, string year);
void addHeadNewSchoolYear(listYear &lY);
void inputDateInSemester(int &day, int &month, int &year);
nodeSemester *initSemester();
void addHeadSemester(listSemester &list, nodeSemester *p);
void inputInformationSemesterAndAddSchoolYear(listYear &lY);

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
	Staff_Info teacher;
	Staff_Node *pNext;
};

struct Staff_List
{
	Staff_Node *pHead;
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
int SignUp(Staff_List &l);
int GetStaffAccount(Staff_List l, string inUsername, string inPassword);
int SignIn(Staff_List l);

// function of course
nodeCourse *initCourse();
void addHeadCourse(listCourse &listC, nodeCourse *p);
void inputInformationToAddCourse(listYear &lY);
void updateInformationCourse(listYear &lY);
void addStudentToCourse(nodeCourse *course);


void removeStudentFromCourse(nodeCourse *course);
void deleteCourse(nodeCourse *course);

typedef void removeOneCourseOutOfCourseList(listCourse *courseList);

#endif