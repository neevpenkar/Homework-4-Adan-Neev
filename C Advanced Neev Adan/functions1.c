#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlinesize 1023

int countPipes(const char* lineBuffer, int maxCount) {
	char pip = '|', *buffer = lineBuffer; 
	int count = 0;
	if (lineBuffer == NULL) return -1;
	if (maxCount <= 0) return 0;

	while (*buffer != '\0' && (buffer - lineBuffer) != maxCount) {
		if (*buffer == pip) count++;
		buffer++;
	}
	return count;
}
void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents) {
	char* buffer[maxlinesize];
	char* buffer2[maxlinesize];
	FILE* text = fopen(fileName, "r");

	int number_of_students = 0;

	fgets(buffer, maxlinesize, text);
	while (buffer != NULL) {
		printf("%s \n", buffer);
		number_of_students++;
		
		// Stop processing data after coming to end of file.
		strcpy(buffer2, buffer);
		fgets(buffer, maxlinesize, text);
		if (!strcmp(buffer2, buffer))
			break;
	}
	fclose(text);
	printf("Students: %d", number_of_students);
}