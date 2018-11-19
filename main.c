
//适配VS: 项目->属性->配置属性->C/C++->预编译头->不使用预编译头。
#define _CRT_SECURE_NO_DEPRECATE

#include "LinkList.c"

#include <stdio.h>
#include <string.h>
typedef struct Student {
	char name[30];
	int number;
	int age;

} Student;

Student* newStudent(const char* name, int number, int age) {
	Student* student = New(Student);
	strcpy(student->name, name);
	student->number = number;
	student->age = age;
	return student;
}

int printList(int pos, DATA_TYPE item) {
	Student* stu = (Student*)item;
	printf("[%d] : name=%s ,number= %d,age=%d \n", pos, stu->name, stu->number, stu->age);
	return 0;
}

int nameComparetor(DATA_TYPE item1, DATA_TYPE item2) {
	Student* stu1 = (Student*)item1;
	Student* stu2 = (Student*)item2;
	return strcmp(stu1->name, stu2->name);
}

int ageComparetor(DATA_TYPE item1, DATA_TYPE item2) {
	Student* stu1 = (Student*)item1;
	Student* stu2 = (Student*)item2;
	return stu1->age - stu2->age;
}


int main() {



	LinkList* students = NULL;
	students = createList();

	pushBack(students, newStudent("name0", 17192, 11));
	pushBack(students, newStudent("name1", 17195, 18));
	pushBack(students, newStudent("name2", 17190, 15));
	pushBack(students, newStudent("name3", 17155, 16));
	pushBack(students, newStudent("name3", 17188, 16));
	pushBack(students, newStudent("abc", 17146, 17));
	pushBack(students, newStudent("bcd", 17123, 19));
	pushBack(students, newStudent("fcd", 17143, 19));
	pushBack(students, newStudent("cde", 17157, 16));

	seekList(students, printList);

	printf("sort by name\n");
	sortList(students, nameComparetor);
	seekList(students, printList);

	printf("sort by age\n");
	sortList(students, ageComparetor);
	seekList(students, printList);

	printf("\n");


	system("pause");

	return 0;
}