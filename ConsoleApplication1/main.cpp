#include "teacher.h"
#include "student.h"
int main()
{
	listYear p = creatListYear();
	addHeadNewSchoolYear(p);
	inputClassToAddSchoolYear(p);
	inputInformationSemesterAndAddSchoolYear(p);
	inputInformationToAddCourse(p);
}