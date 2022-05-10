#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlinesize 1023

int main() {
	//fgets(buffer, maxlinesize, text);
	/*while (buffer != NULL) {
		fgets(buffer, maxlinesize, text);
		printf("%s\n", buffer);
		printf("%d\n", countPipes(buffer, maxlinesize));
	}*/
	
	int number_of_students = 0;
	int* courses_per_student = NULL;

	countStudentsAndCourses("studentList.txt", &courses_per_student, &number_of_students);
	return 0;
}