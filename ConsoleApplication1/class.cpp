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

    string idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (!fileIn.eof())
    {
        getline(fileIn, line, ',');

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
        return NULL;
    }
    StudentList *stuList = createStudentList(0);
    string idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (!fileIn.eof())
    {
        getline(fileIn, line, ',');

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
    return stuList;
}

bool compareByName(const Student &student, const void *name)
{
    const string *studentName = static_cast<const string *>(name);
    return student.fullName.firstName + " " + student.fullName.lastName == *studentName;
}
bool compareByID(const Student &student, const void *id)
{
    const int *studentID = static_cast<const int *>(id);
    return student.studentID == *studentID;
}
void removeStudentFromCourse(nodeCourse *course, CompareFunc compare, const void *value)
{
    if (course->studentList == nullptr || course->studentList->pHeadStudent == nullptr)
        return;

    StudentNode *current = course->studentList->pHeadStudent;
    StudentNode *previous = nullptr;

    while (current != nullptr)
    {
        if (compare(current->data, value))
        {
            if (previous == nullptr)
            {
                course->studentList->pHeadStudent = current->pNextStudent;
            }
            else
            {
                previous->pNextStudent = current->pNextStudent;
            }

            delete current;
            course->studentList->numberOfStudents--;
            return;
        }

        previous = current;
        current = current->pNextStudent;
    }
}

void removeLastStudentFromCourse(nodeCourse *course)
{
    if (course->studentList == nullptr || course->studentList->pHeadStudent == nullptr)
        return;

    StudentNode *current = course->studentList->pHeadStudent;
    StudentNode *previous = nullptr;

    while (current->pNextStudent != nullptr)
    {
        previous = current;
        current = current->pNextStudent;
    }

    if (previous == nullptr)
    {
        course->studentList->pHeadStudent = nullptr;
    }
    else
    {
        previous->pNextStudent = nullptr;
    }

    delete current;
    course->studentList->numberOfStudents--;
}

//-----
bool compareCourseByName(const nodeCourse &course, const void *name)
{
    const string *courseName = static_cast<const string *>(name);
    return course.courseName == *courseName;
}

bool compareCourseByID(const nodeCourse &course, const void *id)
{
    const string *courseID = static_cast<const string *>(id);
    return course.id == *courseID;
}

void deleteStudentList(StudentList *studentList)
{
    while (studentList && studentList->pHeadStudent)
    {
        StudentNode *temp = studentList->pHeadStudent;
        studentList->pHeadStudent = studentList->pHeadStudent->pNextStudent;
        delete temp;
    }
    delete studentList;
}

void deleteScoreList(ListStudentScoreboardOfCourse *scoreList)
{
    while (scoreList && scoreList->head)
    {
        NodeStudentScoreboardOfCourse *temp = scoreList->head;
        scoreList->head = scoreList->head->next;
        delete temp;
    }
    delete scoreList;
}

void deleteCourse(nodeCourse *&head, CompareCourseFunc compare, const void *value)
{
    if (head == nullptr)
        return;

    nodeCourse *current = head;
    nodeCourse *previous = nullptr;

    while (current != nullptr)
    {
        if (compare(*current, value))
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            deleteStudentList(current->studentList);
            deleteScoreList(current->scoreList);

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void exportStudentListFromCourseToCSVFile(string fileName, nodeCourse *course)
{
    ofstream fileOut;
    fileOut.open(fileName);
    if (!fileOut.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }

    fileOut << "STT, MSSV, Ho, Ten" << endl;
    StudentNode *current = course->studentList->pHeadStudent;
    for (int num = 1; num <= course->studentList->numberOfStudents; num++)
    {
        fileOut << num << ", ";
        fileOut << current->data.studentID << ", ";
        fileOut << current->data.fullName.lastName << ", ";
        fileOut << current->data.fullName.firstName << endl;
        current = current->pNextStudent;
    }
    fileOut.flush();
    fileOut.close();
}

ListStudentScoreboardOfCourse *createListStudentScoreboardOfCourse()
{
    ListStudentScoreboardOfCourse *list = new ListStudentScoreboardOfCourse();
    if (!list)
    {
        cout << "Memory error while creating new scoreboard of course!" << endl;
        return nullptr;
    }
    list->head = nullptr;
    return list;
}

NodeStudentScoreboardOfCourse *createNodeStudentScoreboardOfCourse(StudentScoreboardOfCourse stuScore)
{
    NodeStudentScoreboardOfCourse *node1 = new NodeStudentScoreboardOfCourse();
    if (!node1)
    {
        cout << "Memory error while creating new node student scoreboard!";
        return nullptr;
    }
    node1->stuScoreboard = stuScore;
    node1->next = nullptr;
    return node1;
}
void addStudentScoreboardOfCourseIntoList(ListStudentScoreboardOfCourse *list, StudentScoreboardOfCourse stuScore)
{
    NodeStudentScoreboardOfCourse *node1 = createNodeStudentScoreboardOfCourse(stuScore);
    if (list->head == nullptr)
    {
        list->head = node1;
    }
    else
    {
        NodeStudentScoreboardOfCourse *current = list->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node1;
    }
}
void importCourseScoreboardFromCSVFile(string fileName, nodeCourse *course)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }
    string line;
    getline(fileIn, line, '\n');

    string idString, lastName, firstName, otherMarkString, midtermMarkString, finalMarkString, totalMarkString;
    FullName fullName;

    // tạo một danh sách liên kết bảng điểm mới
    ListStudentScoreboardOfCourse *stuScoreList = createListStudentScoreboardOfCourse();

    while (!fileIn.eof())
    {
        getline(fileIn, line, ',');

        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

        getline(fileIn, otherMarkString, ',');
        double otherMark = stod(otherMarkString);

        getline(fileIn, midtermMarkString, ',');
        double midtermMark = stod(midtermMarkString);

        getline(fileIn, finalMarkString, ',');
        double finalMark = stod(finalMarkString);

        getline(fileIn, totalMarkString, '\n');
        double totalMark = stod(totalMarkString);

        StudentScoreboardOfCourse stuScore = {id, fullName, otherMark, midtermMark, finalMark, totalMark};
        addStudentScoreboardOfCourseIntoList(stuScoreList, stuScore);
    }

    course->scoreList = stuScoreList;
    fileIn.close();
}

void viewCourseScoreboard(nodeCourse *course)
{
    cout << "Course name:" << course->courseName << endl;
    cout << "Class: " << course->className << endl;
    cout << "SOCREBOARD" << endl;
    cout << "No - Student ID - Last name - First name - Other mark - Midterm mark - Final nark - Total mark" << endl;

    NodeStudentScoreboardOfCourse *current = course->scoreList->head;
    int num = 1;
    while (current != nullptr)
    {
        cout << fixed << setprecision(3) << num << current->stuScoreboard.studentID << "  " << current->stuScoreboard.fullName.lastName << " "
             << fixed << setprecision(8) << current->stuScoreboard.fullName.lastName << " " << current->stuScoreboard.otherscore << " "
             << current->stuScoreboard.midscore << " " << current->stuScoreboard.finalscore << " " << current->stuScoreboard.totalscore;
        cout << endl;
        current = current->next;
    }
}

// viet ham theo tung hoc ki
//  void viewClassScoreboard(string &claName, string &schYear, int &semester, listYear *year)
//  {
//      cout << "Choose school year: ";
//      getline(cin, claName);
//      cout << "Choose school year: ";
//      getline(cin, schYear);
//      cout << "Choose semester: ";
//      cin >> semester;
//      schoolYear *current = year->pHead;
//      while (current != nullptr)
//      {
//          if ((stoi(schYear.substr(0, 4)) == current->beginYear) && stoi(schYear.substr(5, 4)) == current->lastYear)
//          {
//              if (semester == current->listSem)
//          }
//      }
//  }

double calculateGPAInSemester(Student stu1, listCourse *course)
{
    double sum = 0;
    int credits = 0;
    nodeCourse *crsCur = course->head;
    while (crsCur != nullptr)
    {
        NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
        while (stuScrCur != nullptr)
        {
            if (stuScrCur->stuScoreboard.studentID == stu1.studentID)
            {
                sum += crsCur->numberOfCredits * stuScrCur->stuScoreboard.totalscore;
                credits += crsCur->numberOfCredits;
                break;
            }
            stuScrCur = stuScrCur->next;
        }
        crsCur = crsCur->next;
    }

    return sum / credits;
}

void viewClassScoreboard(Class *cla1, listCourse *course)
{
    StudentNode *stuCur = cla1->pHeadStudent;
    int num = 1;
    while (stuCur != nullptr)
    {
        cout << num << " " << stuCur->data.studentID << " " << stuCur->data.fullName.lastName
             << " " << stuCur->data.fullName.firstName << " " << endl;
        cout << "GPA in semester: " << calculateGPAInSemester(stuCur->data, course);
        nodeCourse *crsCur = course->head;
        while (crsCur != nullptr)
        {
            NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
            while (stuScrCur != nullptr)
            {
                if (stuScrCur->stuScoreboard.studentID == stuCur->data.studentID)
                {
                    cout << "Course ID: " << crsCur->id << endl;
                    cout << "Course name: " << crsCur->courseName << endl;
                    cout << "Final mark: " << stuScrCur->stuScoreboard.finalscore << endl;
                    cout << "Total score (GPA): " << stuScrCur->stuScoreboard.totalscore << endl;
                    cout << endl;
                    break;
                }
                stuScrCur = stuScrCur->next;
            }
            crsCur = crsCur->next;
        }
        num++;
        cout << endl
             << endl;
        stuCur = stuCur->pNextStudent;
    }
}

void viewStudentScoreboard(Student stu1, listCourse *course)
{
    nodeCourse *crsCur = course->head;
    cout << "GPA in semester: " << calculateGPAInSemester(stu1, course);
    while (crsCur != nullptr)
    {
        NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
        while (stuScrCur != nullptr)
        {
            if (stuScrCur->stuScoreboard.studentID == stu1.studentID)
            {
                cout << "Course ID: " << crsCur->id << endl;
                cout << "Course name: " << crsCur->courseName << endl;
                cout << "Final mark: " << stuScrCur->stuScoreboard.finalscore << endl;
                cout << "Total score (GPA): " << stuScrCur->stuScoreboard.totalscore << endl;
                cout << endl;
                break;
            }
            stuScrCur = stuScrCur->next;
        }
        crsCur = crsCur->next;
    }
}
