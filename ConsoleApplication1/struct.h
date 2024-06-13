#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
using namespace std;
struct Date
{
	int day, month, year;
};

struct FullName
{
	string firstName;
	string lastName;
};

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
	Staff_Node *pNext;
};

struct Staff_List
{
	Staff_Node *pHead;
};

struct Student
{
	string className;
	int studentID;
	FullName fullName;
	string gender;
	Date dateOfBirth;
	int socialID;
};

struct StudentNode
{
	Student data;
	StudentNode *pNextStudent;
};

struct StudentList
{
	int numberOfStudents;
	StudentNode *pHeadStudent;
};

struct SignInInfo
{
	string username;
	string password;
};

struct NodeAccount
{
	SignInInfo info;
	NodeAccount *next;
};

struct ListAccount
{
	NodeAccount *head;
};

struct StudentScoreboardOfCourse
{
	int studentID;
	FullName fullName;
	double otherscore;
	double midscore;
	double finalscore;
	double totalscore;
};
struct NodeStudentScoreboardOfCourse
{
	StudentScoreboardOfCourse stuScoreboard;
	NodeStudentScoreboardOfCourse *next;
};

struct ListStudentScoreboardOfCourse
{
	NodeStudentScoreboardOfCourse *head;
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
	ListStudentScoreboardOfCourse *scoreList;
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

struct Class
{
	string className;
	int numberOfStudents;
	StudentNode *pHeadStudent = NULL;
	Class *pNextClass = NULL;
};

struct ClassList
{
	int numberOfClasses;
	Class *pHeadClass = NULL;
};

struct schoolYear
{
	int beginYear;
	int lastYear;
	ClassList listClass;
	listSemester listSem;
	schoolYear *next;
};

struct listYear
{
	schoolYear *pHead;
};
// struct nodeClass
//{
//	string name;
//	// list student
//	nodeClass *next;
// };

// struct ScoreboardOfStudent
// {
// 	int studentID;
// 	double overallGPA;
// 	// tự viết hàm, dùng biến phụ tính điểm trung bình của kì học, rồi tính overall GPA  và lưu vào overall GPA
// 	listCourse *coursesRegistered;
// };

// struct ScoreboardOfStudentNode
// {
// 	ScoreboardOfStudent data;
// 	ScoreboardOfStudentNode *pNext;
// };

// struct ScoreboardOfClass
// {
// 	ScoreboardOfStudentNode *pHead;
// };