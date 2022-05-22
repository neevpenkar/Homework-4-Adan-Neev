#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlinesize 1023

int main() {
	/*char string[] = "Sivan|Advanced Topics in C,100|Algorithms,84";
	char* ptrs[10];
	strtiktok(string, ptrs);*/
	
	int number_of_students = 0;
	int* courses_per_student = NULL;

	makeStudentArrayFromFile("studentList.txt", &courses_per_student, &number_of_students);
	return 0;
}