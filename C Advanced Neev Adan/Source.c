#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlinesize 1023

int main() {
	char* buffer[maxlinesize];
	FILE* text = fopen("studentList.txt", "r");
	
	//fgets(buffer, maxlinesize, text);
	/*while (buffer != NULL) {
		fgets(buffer, maxlinesize, text);
		printf("%s\n", buffer);
		printf("%d\n", countPipes(buffer, maxlinesize));
	}*/
	
	int i = 0;
	int* test1 = &i; int** test2 = &test1;
	countStudentsAndCourses("studentList.txt", test2, test1);
	fclose(text);
	return 0;
}