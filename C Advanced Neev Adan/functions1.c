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
//void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents) {
//	char* buffer[maxlinesize];
//	char* buffer2[maxlinesize];
//	FILE* text = fopen(fileName, "r");
//
//	int number_of_students = 0;
//
//	fgets(buffer, maxlinesize, text);
//	while (buffer != NULL) {
//		printf("%s \n", buffer);
//		number_of_students++;
//		
//		// Stop processing data after coming to end of file.
//		strcpy(buffer2, buffer);
//		fgets(buffer, maxlinesize, text);
//		if (!strcmp(buffer2, buffer))
//			break;
//	}
//	fclose(text);
//	printf("Students: %d", number_of_students);
//}
void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents) {
	
	// Everything related to filesystem
	FILE* file = fopen(fileName, "r"); // "r" is for reading file only
	char* buffer[maxlinesize];
	
	// Counting number of students
	int students_num = 0;

	while (fgets(buffer, maxlinesize, file))
		students_num++;
	*numberOfStudents = students_num;
	
	fseek(file, 1, SEEK_SET);
	// Counting how many courses for each student
	//int temp_courses[10];
	int* temp_courses = (int*)malloc(sizeof(int) * students_num);
	
	for (int i = 0; i < students_num; i ++) {
		if (fgets(buffer, maxlinesize, file) == NULL) exit(33);
	
		temp_courses[i] = countPipes(buffer, maxlinesize);
	}
	*coursesPerStudent = temp_courses;
	fclose(file);
}
int strtiktok(const char* line, char** pointers2address) {
	const char pipe = '|', comma = ',';
	char* buffer = line;
	int i = 0;

	while (*buffer) {
		if (*buffer == pipe || *buffer == comma) {
			pointers2address[i] = buffer++;
			i++;
			printf("%c", *(buffer + 1));
		}
		buffer++;
	}
	return i;
}
//char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents) {
//	int* numberOfCourses;
//	int students;
//
//	countStudentsAndCourses(fileName, &numberOfCourses, &students);
//	char*** studentsArray = (char***)malloc(students * sizeof(char**));
//
//	FILE* file = fopen(fileName, "r"); // "r" is for reading file only
//	char** buffer = (char**)malloc(sizeof(char*) * students);;
//	char buffer2[maxlinesize];
//
//	for (int i = 0; i < students; i++) {
//		if (fgets(buffer2, maxlinesize, file) == NULL) exit(34);
//
//		*(buffer + i) = (char*)malloc(sizeof(char) * (strlen(buffer2) + 2));
//		strcpy(*(buffer + i), buffer2);
//		*(buffer + strlen(buffer2) - 1) = '\0';
//
//	}
//	fclose(file);
//	char* line = *(buffer + 5);
//
//	strtiktok(line, *(studentsArray + 0));
//	
//}
char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents) {

	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents);
	const int* const courses = *coursesPerStudent;
	const int students = *numberOfStudents;

	// 1 Allocation
	char*** block = (char***)malloc(sizeof(char**) * students);

	// 2 Allocation
	for (int i = 0; i < students; i++) {
		block[i] = (char**)malloc(sizeof(char*) * (2 * (courses[i]) + 1));
	}

	FILE* file = fopen(fileName, "r");
	char line[maxlinesize];

	while (fgets(line, maxlinesize, file)) {
		int i = 0, j = 0, k = 0;
		char* buffer = (char*)malloc(sizeof(char) * maxlinesize);
		strcpy(buffer, line);
		strcat(buffer, "|");
		
		while (*buffer) {
			if (j == courses[i]) break;
			
			strtok(buffer, "|");
			block[i][k] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(block[i][k++], buffer);
			printf("%s\n", buffer);
			buffer += strlen(buffer) + 1;

			strtok(buffer, ",");
			block[i][k] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(block[i][k++], buffer);
			buffer += strlen(buffer) + 1;
			
			j++;
		}
		i++;
		/*for (int d = 0; d < j; d++) {
			printf("%s\n", block[i - 1][d]);
		}*/
		/*while (line[i]) {
			strtok(line, ",");

			printf("%s", line);
			i += strlen(line) + 1;
		}*/
	}

	fclose(file);
	return block;
}
void ffdgd() {
	//pointers[j] = buffer;
		//j++;

		////strcpy(buffer2, buffer);

		//if (strtok(buffer, ",") == NULL) {
		//	buffer += strlen(buffer) + 1;
		//	break;
		//}
		//pointers[j] = buffer + strlen(buffer) + 1;
		//printf("%s\n", (pointers[j - 1]));
		//j++;

		//buffer += strlen(buffer) + 1;
		//printf("%s\n", (pointers[j - 1]));
		//free(buffer);

	//strcpy(buffer, line);
	//int i = 0, j = 0;

	//*(block[j++]) = line;
	//while (buffer[i] != '\0' && buffer[i] != '\n') {
	//	if (buffer[i] == '|' || buffer[i] == ',') {
	//		buffer[i] = '\0';
	//		*(block)[j++] = buffer + i + 1;
	//	}
	//	i++;

	//	// First Allocation
	///*char*** block = (char**)malloc(*numberOfStudents * sizeof(char**));*/
	//	char** block[20];

	//	// Child Allocation
	//	for (int i = 0; i < *numberOfStudents; i++) {
	//		block[i] = (char**)malloc(sizeof(char*));
	//		*(block[i]) = (char*)malloc((*coursesPerStudent)[i] * 2 * sizeof(char));
	//	}
}