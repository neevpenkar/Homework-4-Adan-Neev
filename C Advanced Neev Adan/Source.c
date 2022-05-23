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

	char*** bloke = makeStudentArrayFromFile("studentList.txt", &courses_per_student, &number_of_students);
	for (int i = 0; i < number_of_students; i++) {
		for (int j = 0; j < courses_per_student[i]; j++) {
			printf("%s\n", bloke[i][j]);
		}
	}
	return 0;
}