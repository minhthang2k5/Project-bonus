#include "class.h"

Student *createStudent(int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1)
{
    Student *stu1 = new Student();
    if (!stu1)
    {
        cout << "Memory error while creating new student!";
        return nullptr;
    }
    stu1->studentID = id1;
    stu1->fullName = fullName1;
    stu1->gender = gender1;
    stu1->dateOfBirth = dateOfBirth1;
    stu1->socialID = socialID1;
    stu1->pNextStudent = nullptr;
    return stu1;
}

Class *createClass(string className1, int numberOfStudents1)
{
    Class *class1 = new Class();
    if (!class1)
    {
        cout << "Memory error while creating new class!" << endl;
        return nullptr;
    }
    class1->className = className1;
    class1->numberOfStudents = numberOfStudents1;
    class1->pHeadStudent = nullptr;
    class1->pNextClass = nullptr;
    return class1;
}

ClassList *createClassList()
{
    ClassList *claList1 = new ClassList();
    if (!claList1)
    {
        cout << "Memory error while creating new class list!:" << endl;
        return nullptr;
    }
    claList1->pHeadClass = nullptr;
    return claList1;
}

void addStudentIntoClass(Class *class1, Student *stu1)
{
    if (class1->pHeadStudent == nullptr)
    {
        class1->pHeadStudent = stu1;
        return;
    }
    Student *temp = class1->pHeadStudent;
    while (temp->pNextStudent != nullptr)
    {
        temp = temp->pNextStudent;
    }
    temp->pNextStudent = stu1;
}

void addClassIntoClassList(ClassList *claList1, Class *class1)
{
    if (claList1->pHeadClass == nullptr)
    {
        claList1->pHeadClass = class1;
        return;
    }
    Class *temp = claList1->pHeadClass;
    while (temp->pNextClass != nullptr)
    {
        temp = temp->pNextClass;
    }
    temp->pNextClass = class1;
}
void readStudentsOfClassFromCSVFile(string fileName, Class *newClass)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening file\"" << fileName << "\"" << endl;
        return;
    }
    int numberOfStudents = 0;
    string positionInClassString, idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    Date dateOfBirth;
    while (!fileIn.eof())
    {
        getline(fileIn, positionInClassString, ',');
        int positionInClass = stoi(positionInClassString);
        getline(fileIn, idString, ',');
        int id = stoi(idString);
        getline(fileIn, firstName, ',');
        getline(fileIn, lastName, ',');
        getline(fileIn, gender, ',');
        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);
        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);
        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);
        getline(fileIn, socialIDString, '\n');
        int socialID = stoi(socialIDString);
        numberOfStudents++;
    }
    fileIn.close();
}