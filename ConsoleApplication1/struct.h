#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
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
	StudentNode* pNextStudent;
};

struct StudentList
{
	int numberOfStudents;
	StudentNode* pHeadStudent;
};

struct SignInInfo {
	string username;
	string password;
};

struct NodeAccount
{
	SignInInfo info;
	NodeAccount* next;
};

struct ListAccount {
	NodeAccount* head;
};

struct ScoreboardOfCourse
{
	int studentID;
	double otherscore;
	double midscore;
	double finalscore;
	double totalscore;
};

struct NodeScoreboardOfCourse
{
	ScoreboardOfCourse scoreboard;
	NodeScoreboardOfCourse* next;
};

struct ListScoreboardOfCourse
{
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
	StudentList* studentList;
	nodeCourse* next;
};

struct listCourse
{
	nodeCourse* head;
};

struct nodeSemester
{
	// ky 1,2 hay 3
	listCourse listCour;
	int name;
	Date begin;
	Date end;
	nodeSemester* next;
};

struct listSemester
{
	nodeSemester* head;
};

// struct nodeClass
//{
//	string name;
//	// list student
//	nodeClass *next;
// };
struct Class
{
	string className;
	int numberOfStudents;
	StudentNode* pHeadStudent=NULL;
	Class* pNextClass=NULL;
};

struct ClassList
{
	int numberOfClasses;
	Class* pHeadClass=NULL;
};
struct schoolYear
{
	int beginYear;
	int lastYear;
	ClassList listClass;
	listSemester listSem;
	schoolYear* next;
};

struct listYear
{
	schoolYear* pHead;
};



struct ScoreboardOfStudent
{
	int studentID;
	double overallGPA;
	// tự viết hàm, dùng biến phụ tính điểm trung bình của kì học, rồi tính overall GPA  và lưu vào overall GPA
	listCourse* coursesRegistered;
};

struct ScoreboardOfStudentNode
{
	ScoreboardOfStudent data;
	ScoreboardOfStudentNode* pNext;
};

struct ScoreboardOfClass
{
	ScoreboardOfStudentNode* pHead;
};