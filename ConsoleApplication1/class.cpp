#include "class.h"

Student createStudent(string className1, int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1)
{
    Student stu1;
    stu1.className = className1;
    stu1.studentID = id1;
    stu1.fullName = fullName1;
    stu1.gender = gender1;
    stu1.dateOfBirth = dateOfBirth1;
    stu1.socialID = socialID1;
    return stu1;
}

Student createStudent(int id1, FullName fullName1, string gender1, Date dateOfBirth1, int socialID1)
{
    Student stu1;
    stu1.studentID = id1;
    stu1.fullName = fullName1;
    stu1.gender = gender1;
    stu1.dateOfBirth = dateOfBirth1;
    stu1.socialID = socialID1;
    return stu1;
}

StudentNode *createStudentNode(Student stu)
{
    StudentNode *stuNode = new StudentNode();
    if (!stuNode)
    {
        cout << "Memory error while creating new student node!" << endl;
        return nullptr;
    }
    stuNode->data = stu;
    stuNode->pNextStudent = nullptr;
    return stuNode;
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

StudentList *createStudentList(int numberOfStudents1)
{
    StudentList *stuList = new StudentList();
    if (!stuList)
    {
        cout << "Memory error while creating new class!" << endl;
        return nullptr;
    }
    stuList->numberOfStudents = numberOfStudents1;
    stuList->pHeadStudent = nullptr;
    return stuList;
}

ClassList *createClassList(int numberOfClasses)
{
    ClassList *claList1 = new ClassList();
    if (!claList1)
    {
        cout << "Memory error while creating new class list!:" << endl;
        return nullptr;
    }
    claList1->numberOfClasses = numberOfClasses;
    claList1->pHeadClass = nullptr;
    return claList1;
}

void addStudentIntoClass(Class *class1, Student stu1)
{
    StudentNode *stuNode = createStudentNode(stu1);
    if (class1->pHeadStudent == nullptr)
    {
        class1->pHeadStudent = stuNode;
        class1->numberOfStudents++;
        return;
    }
    StudentNode *temp = class1->pHeadStudent;
    while (temp->pNextStudent != nullptr)
    {
        temp = temp->pNextStudent;
    }
    temp->pNextStudent = stuNode;
    class1->numberOfStudents++;
}

void addStudentIntoStudentList(StudentList *studentList, Student stu1)
{
    StudentNode *stuNode = createStudentNode(stu1);
    if (studentList->pHeadStudent == nullptr)
    {
        studentList->pHeadStudent = stuNode;
        studentList->numberOfStudents++;
        return;
    }
    StudentNode *temp = studentList->pHeadStudent;
    while (temp->pNextStudent != nullptr)
    {
        temp = temp->pNextStudent;
    }
    temp->pNextStudent = stuNode;
    studentList->numberOfStudents++;
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

Class *readStudentsOfClassFromCSVFile(string fileName)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening file\"" << fileName << "\"" << endl;
        return nullptr;
    }

    // lấy tên lớp học từ tên file CSV
    size_t lastDot = fileName.find_last_of(".");
    string className = fileName.substr(0, lastDot);

    Class *class1 = createClass(className, 0);

    string positionInClassString, idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (!fileIn.eof())
    {
        getline(fileIn, positionInClassString, ',');
        int positionInClass = stoi(positionInClassString);

        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, gender, ',');

        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);

        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);

        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);

        getline(fileIn, socialIDString, '\n');

        int socialID = stoi(socialIDString);

        Student stu1 = createStudent(id, fullName, gender, dateOfBirth, socialID);
        addStudentIntoClass(class1, stu1);
        class1->numberOfStudents++;
    }
    fileIn.close();
    return class1;
}

StudentList *readStudentsOfCourseFromCSVFile(string fileName)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening \"" << fileName << "\"!" << endl;
        return;
    }
    StudentList *stuList = createStudentList(0);
    string positionInClassString, idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (!fileIn.eof())
    {
        getline(fileIn, positionInClassString, ',');
        int positionInClass = stoi(positionInClassString);

        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, gender, ',');

        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);

        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);

        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);

        getline(fileIn, socialIDString, '\n');

        int socialID = stoi(socialIDString);
        Student stu1 = createStudent(id, fullName, gender, dateOfBirth, socialID);
        addStudentIntoStudentList(stuList, stu1);
        stuList->numberOfStudents++;
    }
    fileIn.close();
}