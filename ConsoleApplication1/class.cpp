#include "class.h"

void viewProfileWhenViewingScoreboard(listYear year, int studentID)
{
    schoolYear *curYear = year.pHead;
    while (curYear != nullptr)
    {
        Class *curClass = curYear->listClass.pHeadClass;
        while (curClass != nullptr)
        {
            StudentNode *curStu = curClass->pHeadStudent;
            while (curStu != nullptr)
            {
                if (curStu->data.studentID == studentID)
                {
                    cout << "Student ID: " << curStu->data.studentID << endl;
                    cout << "Full name: " << curStu->data.fullName.lastName << " " << curStu->data.fullName.firstName << endl;
                    cout << "Class name: " << curStu->data.className << endl;
                    return;
                }
                curStu = curStu->pNextStudent;
            }
            curClass = curClass->pNextClass;
        }
        curYear = curYear->next;
    }
}

void viewStudentScoreboard2(listYear yearList, int studentID, schoolYear *year, nodeSemester *sem)
{
    schoolYear *curYear = yearList.pHead;
    int no = 1;
    cout << "Scoreboard:" << endl;
    cout << "School year: " << year->beginYear << "-" << year->lastYear << endl;
    cout << "Semester: " << sem->name << endl;
    cout << "GPA: " << calculateGPAInSemester(studentID, sem->listCour);
    cout << endl;
    cout << left << setw(5) << "No" << setw(35) << "Course name" << setw(15) << "Final mark" << setw(15) << "Total mark" << endl;

    while (curYear != nullptr)
    {
        if (curYear->beginYear == year->beginYear && curYear->lastYear == year->lastYear)
        {
            nodeSemester *curSem = curYear->listSem.head;
            while (curSem != nullptr)
            {
                if (curSem->name == sem->name)
                {
                    nodeCourse *curCourse = curSem->listCour.head;
                    while (curCourse != nullptr)
                    {
                        NodeStudentScoreboardOfCourse *curStuScore = curCourse->scoreList->head;
                        while (curStuScore != nullptr)
                        {
                            if (curStuScore->stuScoreboard.studentID == studentID)
                            {
                                string yearname = to_string(curYear->beginYear) + "-" + to_string(curYear->lastYear);
                                cout << left << setw(5) << no << setw(35) << curCourse->courseName << setw(15) << curStuScore->stuScoreboard.finalscore << setw(15) << curStuScore->stuScoreboard.totalscore << endl;
                                no++;
                                break;
                            }
                            curStuScore = curStuScore->next;
                        }
                        curCourse = curCourse->next;
                    }
                    break;
                }
                curSem = curSem->next;
            }
            break;
        }
        curYear = curYear->next;
    }
}
void viewStudentScoreboard2(listYear yearList, int studentID)
{
    schoolYear *curYear = yearList.pHead;
    int no = 1;
    cout << left << setw(5) << "No" << setw(15) << "School year" << setw(10) << "Semester" << setw(35) << "Course name" << setw(15) << "Final mark" << setw(15) << "Total mark" << endl;

    while (curYear != nullptr)
    {

        nodeSemester *curSem = curYear->listSem.head;
        while (curSem != nullptr)
        {
            nodeCourse *curCourse = curSem->listCour.head;
            while (curCourse != nullptr)
            {
                NodeStudentScoreboardOfCourse *curStuScore = curCourse->scoreList->head;
                while (curStuScore != nullptr)
                {
                    if (curStuScore->stuScoreboard.studentID == studentID)
                    {
                        string yearname = to_string(curYear->beginYear) + "-" + to_string(curYear->lastYear);
                        cout << left << setw(5) << no << setw(15) << yearname << setw(10) << curSem->name << setw(35) << curCourse->courseName << setw(15) << curStuScore->stuScoreboard.finalscore << setw(15) << curStuScore->stuScoreboard.totalscore << endl;
                        no++;
                        break;
                    }
                    curStuScore = curStuScore->next;
                }
                curCourse = curCourse->next;
            }
            curSem = curSem->next;
        }
        curYear = curYear->next;
    }
}

void updateStudentResultOfCourse(nodeCourse *&course, nodeSemester *curSemester, schoolYear *curYear)
{
    int studentID;
    cout << "Input student ID to update result: ";
    cin >> studentID;
    NodeStudentScoreboardOfCourse *curStu = course->scoreList->head;
    while (curStu != nullptr)
    {
        if (curStu->stuScoreboard.studentID == studentID)
        {
            cout << "Update result: " << endl;
            cout << "Full name: " << curStu->stuScoreboard.fullName.lastName << " " << curStu->stuScoreboard.fullName.firstName << endl;
            cout << "Other mark: ";
            cin >> curStu->stuScoreboard.otherscore;
            cout << "Midterm mark: ";
            cin >> curStu->stuScoreboard.midscore;
            cout << "Final mark: ";
            cin >> curStu->stuScoreboard.finalscore;
            cout << "Total mark: ";
            cin >> curStu->stuScoreboard.totalscore;
            cout << endl;
            break;
        }
        curStu = curStu->next;
    }
    if (curStu == nullptr)
    {
        cout << "Not found student ID: " << studentID << endl;
    }
    else
    {
        ofstream fout;
        string year = to_string(curYear->beginYear) + "-" + to_string(curYear->lastYear);
        string nameSemester = to_string(curSemester->name);
        string path = "listYear/" + year + "/" + nameSemester + "/" + course->courseName + "/scoreboard.txt";
        fout.open(path);
        NodeStudentScoreboardOfCourse *p = course->scoreList->head;
        while (p != NULL)
        {
            fout << p->stuScoreboard.studentID << endl;
            fout << p->stuScoreboard.fullName.lastName << " " << p->stuScoreboard.fullName.firstName << endl;
            fout << p->stuScoreboard.otherscore << " " << p->stuScoreboard.midscore << " " << p->stuScoreboard.finalscore << " " << p->stuScoreboard.totalscore << endl;
            p = p->next;
        }
        fout.close();
    }
}
void viewClassListBasicInfo(ClassList claList)
{
    cout << endl
         << endl
         << endl
         << endl;
    Class *cur = claList.pHeadClass;
    cout << "Basic class list infomation:" << endl;
    cout << "Number of classes: " << claList.numberOfClasses << endl;
    cout << left << setw(15) << "Class name" << setw(15) << "Number of students" << endl;
    while (cur != nullptr)
    {

        cout << left << setw(15) << cur->className << setw(15) << cur->numberOfStudents << endl;
        cur = cur->pNextClass;
    }
    cout << endl
         << endl
         << endl
         << endl;
}

void viewAllStudentsOfClassInfo(Class *cla)
{
    cout << endl
         << endl
         << endl
         << endl;
    int no = 1;
    StudentNode *cur = cla->pHeadStudent;
    cout << "Students infomation in class " << cla->className << endl;
    cout << left << setw(5) << "No" << setw(15) << "Student ID" << setw(30) << "Full name" << setw(8) << "Gender" << setw(18) << "Date of birth" << setw(10) << "Social ID" << endl;
    while (cur != nullptr)
    {
        string fullname = cur->data.fullName.lastName + " " + cur->data.fullName.firstName;
        string dob = to_string(cur->data.dateOfBirth.day) + "/" + to_string(cur->data.dateOfBirth.month) + "/" + to_string(cur->data.dateOfBirth.year);
        cout << left << setw(5) << no << setw(15) << cur->data.studentID << setw(30) << fullname << setw(8) << cur->data.gender << setw(18) << dob << setw(10) << cur->data.socialID << endl;
        no++;
        cur = cur->pNextStudent;
    }
    cout << endl
         << endl
         << endl
         << endl;
}
void viewProfile(listYear year, int studentID)
{
    schoolYear *curYear = year.pHead;
    while (curYear != nullptr)
    {
        Class *curClass = curYear->listClass.pHeadClass;
        while (curClass != nullptr)
        {
            StudentNode *curStu = curClass->pHeadStudent;
            while (curStu != nullptr)
            {
                if (curStu->data.studentID == studentID)
                {
                    cout << "Profile:" << endl;
                    cout << "Student ID: " << curStu->data.studentID << endl;
                    cout << "Full name: " << curStu->data.fullName.lastName << " " << curStu->data.fullName.firstName << endl;
                    cout << "Gender: " << curStu->data.gender << endl;
                    cout << "Date of birth: " << curStu->data.dateOfBirth.day << "/" << curStu->data.dateOfBirth.month << "/" << curStu->data.dateOfBirth.year << endl;
                    cout << "Social ID: " << curStu->data.socialID << endl;
                    cout << "Class name: " << curStu->data.className << endl;
                    return;
                }
                curStu = curStu->pNextStudent;
            }
            curClass = curClass->pNextClass;
        }
        curYear = curYear->next;
    }
}
void appendNewStudentsOfClassToCurrentClass(Class *&source, Class *&newClass)
{
    StudentNode *curStudent = source->pHeadStudent;
    if (curStudent == nullptr)
    {
        source->pHeadStudent = newClass->pHeadStudent;
        source->numberOfStudents = newClass->numberOfStudents;
    }
    else
    {
        while (curStudent->pNextStudent != nullptr)
        {
            curStudent = curStudent->pNextStudent;
        }
        curStudent->pNextStudent = newClass->pHeadStudent;
        source->numberOfStudents += newClass->numberOfStudents;
    }
}
void writeStudentListEnrollCourseToTxtFile(nodeCourse *course, nodeSemester *curSemester, schoolYear *curYear)
{
    string year = changeIntToStringYear2(curYear->beginYear, curYear->lastYear);
    string nameSemester = to_string(curSemester->name);
    string nameTxt = "listYear/" + year + "/" + nameSemester + "/" + course->courseName + "/listStudent";
    writeListStudentInCourse2(course->studentList, nameTxt);
}

void writeListStudentInCourse2(StudentList *slist, string name)
{
    StudentNode *p = slist->pHeadStudent;
    name = name + ".txt";
    ofstream fout;
    fout.open(name);
    while (p != NULL)
    {
        fout << p->data.fullName.firstName << " ";
        fout << p->data.fullName.lastName << endl;
        fout << p->data.studentID << endl;
        fout << p->data.className << endl;
        fout << p->data.dateOfBirth.day << " " << p->data.dateOfBirth.month << " " << p->data.dateOfBirth.year << endl;
        fout << p->data.gender << endl;
        fout << p->data.socialID << endl;
        p = p->pNextStudent;
    }
    fout.close();
}
void appendNewStudentListToCurrentStudentList(StudentList *&source, StudentList *&current)
{
    if (!source)
    {
        source = new StudentList();
    }
    StudentNode *curSource = source->pHeadStudent;
    if (curSource == nullptr)
    {
        source->pHeadStudent = current->pHeadStudent;
        source->numberOfStudents = current->numberOfStudents;
    }
    else
    {
        while (curSource->pNextStudent != nullptr)
        {
            curSource = curSource->pNextStudent;
        }
        curSource->pNextStudent = current->pHeadStudent;
        source->numberOfStudents = source->numberOfStudents + current->numberOfStudents;
    }
}
string changeIntToStringYear2(int begin, int end)
{
    string beginN = to_string(begin);
    string endN = to_string(end);
    string year = beginN + "-" + endN;
    return year;
}
void readClassAll(listYear &ls)
{
    schoolYear *curYear = ls.pHead;
    while (curYear != nullptr)
    {
        curYear->listClass = noPointerCreateClassList(0);
        string beginN = to_string(curYear->beginYear);
        string lastN = to_string(curYear->lastYear);
        string nameFolder = "listYear/" + beginN + "-" + lastN + "/listClass.txt";
        ifstream fileIn(nameFolder);
        string className;
        int numberOfStudents;
        string temp;
        fileIn >> temp;
        while (fileIn >> className)
        {
            fileIn >> numberOfStudents;
            string nameFolder2 = "listYear/" + beginN + "-" + lastN + "/listClass/" + className + ".csv";
            Class *newClass = readStudentsOfClassFromCSVFile(nameFolder2, className);
            noPointerAddClassIntoClassList(curYear->listClass, newClass);
        }
        fileIn.close();
        curYear = curYear->next;
    }
}

void createEmptyClassCSVFile(schoolYear *year, string className)
{
    string nameFolder;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    nameFolder = "listYear/" + beginN + "-" + lastN + "/listClass";
    ofstream oFile;
    // hien folde de up len git
    string fileName;
    fileName = nameFolder + "/" + className + ".csv";
    oFile.open(fileName);
    oFile.close();
}

void writeClassIntoCSVFile(schoolYear *year, Class *class1)
{
    string fileName;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    fileName = "listYear/" + beginN + "-" + lastN + "/listClass/" + class1->className + ".csv";
    ofstream fileOut(fileName);
    if (!fileOut.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }

    fileOut << "No, Student ID, Last name, First name, Gender, Date of Birth, Social ID" << endl;
    // fileOut << class1->numberOfStudents << endl;

    StudentNode *current = class1->pHeadStudent;
    int no = 1;
    while (current != nullptr)
    {
        fileOut << no << ",";
        no++;
        fileOut << current->data.studentID << ",";
        fileOut << current->data.fullName.lastName << ",";
        fileOut << current->data.fullName.firstName << ",";
        fileOut << current->data.gender << ",";
        fileOut << current->data.dateOfBirth.day << "/";
        fileOut << current->data.dateOfBirth.month << "/";
        fileOut << current->data.dateOfBirth.year << ",";
        fileOut << current->data.socialID << endl;
        current = current->pNextStudent;
    }
    fileOut.flush();
    fileOut.close();
}

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

ClassList noPointerCreateClassList(int numberOfClasses)
{
    ClassList claList1;
    claList1.numberOfClasses = numberOfClasses;
    claList1.pHeadClass = nullptr;
    return claList1;
}
StudentList noPointerCreateStudentList(int numberOfStudents1)
{
    StudentList stuList;
    stuList.numberOfStudents = numberOfStudents1;
    stuList.pHeadStudent = nullptr;
    return stuList;
}
void addStudentIntoClass(Class *&class1, Student stu1)
{
    StudentNode *stuNode = createStudentNode(stu1);
    if (class1->pHeadStudent == nullptr)
    {
        class1->pHeadStudent = stuNode;
        class1->numberOfStudents++;
        return;
    }
    else
    {
        StudentNode *temp = class1->pHeadStudent;
        while (temp->pNextStudent != nullptr)
        {
            temp = temp->pNextStudent;
        }
        temp->pNextStudent = stuNode;
        class1->numberOfStudents++;
    }
}

void addStudentIntoStudentList(StudentList *&studentList, Student stu1)
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
void addClassIntoClassList(ClassList *&claList1, Class *class1)
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

    while (getline(fileIn, line, ','))
    {
        if (fileIn.eof())
        {
            break;
        }
        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

        getline(fileIn, gender, ',');

        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);

        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);

        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);

        getline(fileIn, socialIDString, '\n');

        int socialID = stoi(socialIDString);

        Student stu1 = createStudent(className, id, fullName, gender, dateOfBirth, socialID);
        addStudentIntoClass(class1, stu1);
    }
    fileIn.close();
    return class1;
}

Class *readStudentsOfClassFromCSVFile(string fileName, string className)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening file\"" << fileName << "\"" << endl;
        return nullptr;
    }

    Class *class1 = createClass(className, 0);

    string idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (getline(fileIn, line, ','))
    {
        if (fileIn.eof())
        {
            break;
        }
        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

        getline(fileIn, gender, ',');

        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);

        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);

        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);

        getline(fileIn, socialIDString, '\n');

        int socialID = stoi(socialIDString);

        Student stu1 = createStudent(className, id, fullName, gender, dateOfBirth, socialID);
        addStudentIntoClass(class1, stu1);
    }
    fileIn.close();
    return class1;
}

void readStudentsOfClassFromCSVFile(string fileName, Class *&class1)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening file\"" << fileName << "\"" << endl;
        return;
    }

    // lấy tên lớp học từ tên file CSV
    size_t lastDot = fileName.find_last_of(".");
    string className = fileName.substr(0, lastDot);

    class1 = createClass(className, 0);

    string idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (getline(fileIn, line, ','))
    {
        if (fileIn.eof())
        {
            break;
        }
        getline(fileIn, idString, ',');
        int id = stoi(idString);

        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;

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
    }
    fileIn.close();
}

void noPointerAddClassIntoClassList(ClassList &claList1, Class *class1)
{
    if (claList1.pHeadClass == nullptr)
    {
        claList1.pHeadClass = class1;
        claList1.numberOfClasses++;
        return;
    }
    else
    {
        Class *temp = claList1.pHeadClass;
        while (temp->pNextClass != nullptr)
        {
            temp = temp->pNextClass;
        }
        temp->pNextClass = class1;
        claList1.numberOfClasses++;
    }
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
    string idString, firstName, lastName, gender, dayOfDOB, monthOfDOB, yearOfDOB, socialIDString, className;
    FullName fullName;
    Date dateOfBirth;

    // xuống dòng đầu tiên
    string line;
    getline(fileIn, line, '\n');

    while (getline(fileIn, line, ','))
    {
        if (fileIn.eof())
        {
            break;
        }
        getline(fileIn, idString, ',');
        int id = stoi(idString);
        getline(fileIn, className, ',');
        getline(fileIn, lastName, ',');
        fullName.lastName = lastName;

        getline(fileIn, firstName, ',');
        fullName.firstName = firstName;
        getline(fileIn, gender, ',');

        getline(fileIn, dayOfDOB, '/');
        dateOfBirth.day = stoi(dayOfDOB);

        getline(fileIn, monthOfDOB, '/');
        dateOfBirth.month = stoi(monthOfDOB);

        getline(fileIn, yearOfDOB, ',');
        dateOfBirth.year = stoi(yearOfDOB);

        getline(fileIn, socialIDString, '\n');

        int socialID = stoi(socialIDString);
        Student stu1 = createStudent(className, id, fullName, gender, dateOfBirth, socialID);
        addStudentIntoStudentList(stuList, stu1);
        stuList->numberOfStudents++;
    }
    fileIn.close();
    return stuList;
}

void removeStudentFromCourseByID(nodeCourse *course, int studentID)
{
    StudentNode *prev = nullptr;
    StudentNode *cur = course->studentList->pHeadStudent;
    while (cur != nullptr)
    {
        if (cur->data.studentID == studentID)
        {
            if (prev == nullptr)
            {
                course->studentList->pHeadStudent = course->studentList->pHeadStudent->pNextStudent;
            }
            else
            {
                prev->pNextStudent = cur->pNextStudent;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->pNextStudent;
    }
}
void removeCourseByID(listCourse &course, int courseID)
{
    nodeCourse *prev = nullptr;
    nodeCourse *cur = course.head;
    while (cur != nullptr)
    {
        if (stoi(cur->id) == courseID)
        {
            if (prev == nullptr)
            {
                course.head = course.head->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
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

void exportStudentListFromCourseToCSVFile(string fileName, nodeCourse *course)
{
    ofstream fileOut;
    fileOut.open(fileName);
    if (!fileOut.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }

    fileOut << "No, Student ID, Class name, Ho, Ten" << endl;
    StudentNode *current = course->studentList->pHeadStudent;
    int num = 1;
    while (current != nullptr)
    {
        fileOut << num << ", ";
        num++;
        fileOut << current->data.studentID << ",";
        fileOut << current->data.className << ",";
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
void importCourseScoreboardFromCSVFile(string fileName, nodeCourse *&course, schoolYear *curYear, nodeSemester *curSemester)
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

    while (getline(fileIn, line, ','))
    {
        if (fileIn.eof())
        {
            break;
        }
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

    // Ghi vào file txt
    ofstream fout;
    string year = to_string(curYear->beginYear) + "-" + to_string(curYear->lastYear);
    string nameSemester = to_string(curSemester->name);
    string path = "listYear/" + year + "/" + nameSemester + "/" + course->courseName + "/scoreboard.txt";
    fout.open(path);
    NodeStudentScoreboardOfCourse *p = stuScoreList->head;
    while (p != NULL)
    {
        fout << p->stuScoreboard.studentID << endl;
        fout << p->stuScoreboard.fullName.lastName << " " << p->stuScoreboard.fullName.firstName << endl;
        fout << p->stuScoreboard.otherscore << " " << p->stuScoreboard.midscore << " " << p->stuScoreboard.finalscore << " " << p->stuScoreboard.totalscore << endl;
        p = p->next;
    }
    fout.close();
}

void viewCourseScoreboard(nodeCourse *course)
{
    cout << endl
         << endl
         << endl;
    cout << "Course name:" << course->courseName << endl;
    cout << "Class: " << course->className << endl;
    cout << "SOCREBOARD" << endl;
    cout << left << setw(5) << "No" << setw(15) << "Student ID" << setw(30) << "Full name" << setw(15) << "Other mark" << setw(15) << "Midter mark" << setw(15) << "Final mark" << setw(15) << "Total mark" << endl;

    NodeStudentScoreboardOfCourse *current = course->scoreList->head;
    int num = 1;
    while (current != nullptr)
    {
        string fullname = current->stuScoreboard.fullName.lastName + " " + current->stuScoreboard.fullName.firstName;
        cout << left << setw(5) << num << setw(15) << current->stuScoreboard.studentID << setw(30) << fullname << setw(15) << current->stuScoreboard.otherscore << setw(15) << current->stuScoreboard.midscore << setw(15) << current->stuScoreboard.finalscore << setw(15) << current->stuScoreboard.totalscore << endl;
        num++;
        current = current->next;
    }
    cout << endl
         << endl
         << endl;
}

double calculateGPAInSemester(Student stu1, listCourse courseList)
{
    double sum = 0;
    int credits = 0;
    nodeCourse *crsCur = courseList.head;
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

double calculateGPAInSemester(int studentID, listCourse courseList)
{
    double sum = 0;
    int credits = 0;
    nodeCourse *crsCur = courseList.head;
    while (crsCur != nullptr)
    {
        NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
        while (stuScrCur != nullptr)
        {
            if (stuScrCur->stuScoreboard.studentID == studentID)
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

void viewClassScoreboard(Class *cla1, listCourse courseList)
{
    cout << endl
         << endl
         << endl
         << endl;
    StudentNode *stuCur = cla1->pHeadStudent;
    int num = 1;
    while (stuCur != nullptr)
    {
        cout << num << " " << stuCur->data.studentID << " " << stuCur->data.fullName.lastName
             << " " << stuCur->data.fullName.firstName << " " << endl;
        cout << "GPA in semester: " << calculateGPAInSemester(stuCur->data, courseList) << endl;
        cout << "List of courses" << endl;
        cout << left << setw(5) << "No " << setw(15) << "Course ID" << setw(35) << "Course name" << setw(15) << "Final mark" << setw(15) << "Total mark" << endl;
        nodeCourse *crsCur = courseList.head;
        while (crsCur != nullptr)
        {
            int num2 = 1;
            NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
            while (stuScrCur != nullptr)
            {
                if (stuScrCur->stuScoreboard.studentID == stuCur->data.studentID)
                {
                    cout << left << setw(5) << num2 << setw(15) << crsCur->id;
                    num2++;
                    cout << setw(35) << crsCur->courseName;
                    cout << setw(15) << stuScrCur->stuScoreboard.finalscore;
                    cout << setw(15) << stuScrCur->stuScoreboard.totalscore;
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
    cout << endl
         << endl
         << endl
         << endl;
}

void viewStudentScoreboard(Student stu1, listCourse courseList)
{
    nodeCourse *crsCur = courseList.head;
    cout << "Student ID: " << stu1.studentID << endl;
    cout << "Full name: " << stu1.fullName.lastName << " " << stu1.fullName.firstName << endl;
    cout << "GPA in semester: " << calculateGPAInSemester(stu1, courseList) << endl;
    cout << "List of courses:" << endl;
    cout << left << setw(5) << "No" << setw(10) << "Course ID" << setw(35) << "Course name" << setw(15) << "Final mark" << setw(15) << "Total mark" << endl;
    int no = 1;
    while (crsCur != nullptr)
    {
        NodeStudentScoreboardOfCourse *stuScrCur = crsCur->scoreList->head;
        while (stuScrCur != nullptr)
        {
            if (stuScrCur->stuScoreboard.studentID == stu1.studentID)
            {
                cout << left << setw(5) << no;
                no++;
                cout << setw(10) << crsCur->id;
                cout << setw(35) << crsCur->courseName;
                cout << setw(15) << stuScrCur->stuScoreboard.finalscore;
                cout << setw(15) << stuScrCur->stuScoreboard.totalscore << endl;
                break;
            }
            stuScrCur = stuScrCur->next;
        }
        crsCur = crsCur->next;
    }
}
void writeBasicClassListInfoIntoFile(schoolYear *year)
{
    string fileName;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    fileName = "listYear/" + beginN + "-" + lastN + "/listClass.txt";
    ofstream fileOut(fileName);
    if (!fileOut.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }

    fileOut << year->listClass.numberOfClasses << endl;

    Class *current = year->listClass.pHeadClass;
    while (current != nullptr)
    {
        fileOut << current->className << endl;
        fileOut << current->numberOfStudents << endl;
        current = current->pNextClass;
    }
    fileOut.flush();
    fileOut.close();
}

void noPointerWriteBasicClassListInfoIntoFile(schoolYear *year, ClassList claList)
{
    string fileName;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    fileName = "listYear/" + beginN + "-" + lastN + "/listClass.txt";
    ofstream fileOut(fileName);
    if (!fileOut.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return;
    }

    fileOut << claList.numberOfClasses << endl;

    Class *current = claList.pHeadClass;
    while (current != nullptr)
    {
        fileOut << current->className << endl;
        fileOut << current->numberOfStudents << endl;
        current = current->pNextClass;
    }
    fileOut.flush();
    fileOut.close();
}
//
ClassList *readBasicClassListInfoToFile(schoolYear *year)
{
    string fileName;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    fileName = "listYear/" + beginN + "-" + lastN + "/listClass.txt";
    ifstream fileIn(fileName);
    if (!fileIn.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return nullptr;
    }
    int claNum;
    fileIn >> claNum;
    ClassList *claList = createClassList(claNum);
    while (!fileIn.eof())
    {
        Class *cur = new Class;
        fileIn >> cur->className >> cur->numberOfStudents;
        addClassIntoClassList(claList, cur);
    }
    fileIn.close();
    return claList;
}

ClassList noPointerReadBasicClassListInfoToFile(schoolYear *year)
{
    string fileName;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    fileName = "listYear/" + beginN + "-" + lastN + "/listClass.txt";
    ifstream fileIn(fileName);
    ClassList claList;
    if (!fileIn.is_open())
    {
        cout << "Error while opening " << fileName << endl;
        return claList;
    }
    int claNum;
    fileIn >> claNum;
    claList = noPointerCreateClassList(claNum);
    while (!fileIn.eof())
    {
        Class *cur = new Class;
        fileIn >> cur->className >> cur->numberOfStudents;
        noPointerAddClassIntoClassList(claList, cur);
    }
    fileIn.close();
    return claList;
}

// moi khi tao nam hoc moi deu phai co ham nay luon.
void createClassListFolder(schoolYear *year)
{

    string nameFolder;
    string beginN = to_string(year->beginYear);
    string lastN = to_string(year->lastYear);
    nameFolder = "listYear/" + beginN + "-" + lastN + "/listClass";
    const char *nameChar = nameFolder.c_str();
    _mkdir(nameChar);
    ofstream oFile;
    // hien folde de up len git
    string gitFile;
    gitFile = nameFolder + "/" + "gitFile.txt";
    oFile.open(gitFile);
    oFile.close();
}

Student inputStudentInformation()
{
    Student info;
    cout << "Input student ID: ";
    cin >> info.studentID;
    cin.ignore();
    cout << "Input firstname: ";
    getline(cin, info.fullName.firstName);
    cout << "Input lastname: ";
    getline(cin, info.fullName.lastName);
    cout << "Input gender: ";
    getline(cin, info.gender);
    cout << "Input date of birth: " << endl;
    cout << "Day: ";
    cin >> info.dateOfBirth.day;
    cout << "Month: ";
    cin >> info.dateOfBirth.month;
    cout << "Year: ";
    cin >> info.dateOfBirth.year;
    cout << "Input social ID: ";
    cin >> info.socialID;
    return info;
}

//---
string extractFileName(const string &filePath)
{
    size_t dotPosition = filePath.find('.');
    if (dotPosition != string::npos)
    {
        return filePath.substr(0, dotPosition);
    }
    return filePath;
}