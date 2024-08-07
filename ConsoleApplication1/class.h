#ifndef _CLASS_H_
#define _CLASS_H_
#include "struct.h"

//--
void viewStudentScoreboard2(listYear yearList, int studentID, schoolYear *year, nodeSemester *sem);
//--
void viewProfileWhenViewingScoreboard(listYear year, int studentID);
//--
void viewStudentScoreboard2(listYear yearList, int studentID);
//--
void updateStudentResultOfCourse(nodeCourse *&course, nodeSemester *curSemester, schoolYear *curYear);

//--
void viewClassListBasicInfo(ClassList claList);
void viewAllStudentsOfClassInfo(Class *cla);
//---
void viewProfile(listYear year, int studentID);
//---
void appendNewStudentsOfClassToCurrentClass(Class *&source, Class *&newClass);
//---
void writeStudentListEnrollCourseToTxtFile(nodeCourse *course, nodeSemester *curSemester, schoolYear *curYear);
void writeListStudentInCourse2(StudentList *slist, string name);

void appendNewStudentListToCurrentStudentList(StudentList *&source, StudentList *&current);
string changeIntToStringYear2(int begin, int end);
//----
void createEmptyClassCSVFile(schoolYear *year, string className);
void writeClassIntoCSVFile(schoolYear *year, Class *class1);

//---
Student createStudent(string className1, int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1);
Student createStudent(int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1);
Class *createClass(string className1, int numberOfStudents1);
ClassList *createClassList(int numberOfClasses);
StudentList *createStudentList(int numberOfStudents1);
ClassList noPointerCreateClassList(int numberOfClasses);
StudentList noPointerCreateStudentList(int numberOfStudents1);
void noPointerAddClassIntoClassList(ClassList &claList1, Class *class1);
void addStudentIntoClass(Class *&class1, Student stu1);
void addStudentIntoStudentList(StudentList *&studentList, Student stu1);
void addClassIntoClassList(ClassList *&claList1, Class *class1);

Class *readStudentsOfClassFromCSVFile(string fileName);
Class *readStudentsOfClassFromCSVFile(string fileName, string className);
void readStudentsOfClassFromCSVFile(string fileName, Class *&class1);

StudentList *readStudentsOfCourseFromCSVFile(string fileName);

//---
void removeStudentFromCourseByID(nodeCourse *course, int studentID);
void removeCourseByID(listCourse &course, int courseID);

//----
void exportStudentListFromCourseToCSVFile(string fileName, nodeCourse *course);

//----
void addStudentScoreboardOfCourseIntoList(ListStudentScoreboardOfCourse *list, StudentScoreboardOfCourse stuScore);
NodeStudentScoreboardOfCourse *createNodeStudentScoreboardOfCourse(StudentScoreboardOfCourse stuScore);
ListStudentScoreboardOfCourse *createListStudentScoreboardOfCourse();
void importCourseScoreboardFromCSVFile(string fileName, nodeCourse *&course, schoolYear *curYear, nodeSemester *curSemester);

//----
void viewCourseScoreboard(nodeCourse *course);

double calculateGPAInSemester(Student stu1, listCourse course);
double calculateGPAInSemester(int studentID, listCourse courseList);
void viewClassScoreboard(Class *cla1, listCourse course);
void viewStudentScoreboard(Student stu1, listCourse course);
//----
void writeBasicClassListInfoIntoFile(schoolYear *year);
void noPointerWriteBasicClassListInfoIntoFile(schoolYear *year, ClassList claList);
ClassList *readBasicClassListInfoToFile(schoolYear *year);
ClassList noPointerReadBasicClassListInfoToFile(schoolYear *year);
//----
void createClassListFolder(schoolYear *year);

Student inputStudentInformation();

//--- doc class
string changeIntToStringYear2(int begin, int end);
void readClassAll(listYear &ls);

//---
string extractFileName(const string &filePath);
#endif
