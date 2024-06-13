#ifndef _CLASS_H_
#define _CLASS_H_
#include "struct.h"

//----
Student createStudent(string className1, int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1);
Student createStudent(int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1);
Class *createClass(string className1, int numberOfStudents1);
ClassList *createClassList(int numberOfClasses);
StudentList *createStudentList(int numberOfStudents1);
Class noPointerCreateClass(string className1, int numberOfStudents1);
ClassList noPointerCreateClassList(int numberOfClasses);
StudentList noPointerCreateStudentList(int numberOfStudents1);
void noPointerAddStudentIntoClass(Class class1, Student stu1);
void noPointerAddClassIntoClassList(ClassList claList1, Class *class1);
void addStudentIntoClass(Class *class1, Student stu1);
void addStudentIntoStudentList(StudentList *studentList, Student stu1);
void addClassIntoClassList(ClassList *claList1, Class *class1);

Class *readStudentsOfClassFromCSVFile(string fileName);
Class noPointerReadStudentsOfClassFromCSVFile(string fileName);

StudentList *readStudentsOfCourseFromCSVFile(string fileName);

//----
typedef bool (*CompareFunc)(const Student &, const void *);
bool compareByName(const Student &student, const void *name);
bool compareByID(const Student &student, const void *id);
//-
void removeStudentFromCourse(nodeCourse *course, CompareFunc compare, const void *value);
void removeLastStudentFromCourse(nodeCourse *course);

//----
typedef bool (*CompareCourseFunc)(const nodeCourse &, const void *);
bool compareCourseByName(const nodeCourse &course, const void *name);
bool compareCourseByID(const nodeCourse &course, const void *id);
//-
void deleteStudentList(StudentList *studentList);
void deleteScoreList(ListStudentScoreboardOfCourse *scoreList);
void deleteCourse(nodeCourse *&head, CompareCourseFunc compare, const void *value);

//----
void exportStudentListFromCourseToCSVFile(string fileName, nodeCourse *course);

//----
void addStudentScoreboardOfCourseIntoList(ListStudentScoreboardOfCourse *list, StudentScoreboardOfCourse stuScore);
NodeStudentScoreboardOfCourse *createNodeStudentScoreboardOfCourse(StudentScoreboardOfCourse stuScore);
ListStudentScoreboardOfCourse *createListStudentScoreboardOfCourse();
void importCourseScoreboardFromCSVFile(string fileName, nodeCourse *course);

//----
void viewCourseScoreboard(nodeCourse *course);
double calculateGPAInSemester(Student stu1, listCourse *course);
void viewClassScoreboard(Class *cla1, listCourse *course);
void viewStudentScoreboard(Student stu1, listCourse *course);

#endif
