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
    int studentNum = 0;
    string line;
    getline(fileIn, newClass->className, '\n');
    getline(fileIn, line, '\n');
    while (getline(fileIn, line))
    {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
    }
    fileIn.close();
}