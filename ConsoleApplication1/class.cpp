#include "class.h"

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