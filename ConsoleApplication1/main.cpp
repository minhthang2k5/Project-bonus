#include "teacher.h"
#include "student.h"
int main()
{
	Student_List l;
	init(l);
	signUp(l);
	signUp(l);
	printList(l);
	system("pause");
	return 0;
}