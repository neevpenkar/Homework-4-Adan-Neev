#define _CRT_SECURE_NO_WARNINGS
/*#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>*/ //uncomment this block to check for heap memory allocation leaks.
// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct StudentCourseGrade
{
	char courseName[35];
	int grade;
}StudentCourseGrade;

typedef struct Student
{
	char name[35];
	StudentCourseGrade* grades; //dynamic array of courses
	int numberOfCourses;
}Student;


//Part A
void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
int countPipes(const char* lineBuffer, int maxCount);
char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents);
void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor);
void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents);

//Part B
Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents);
void writeToBinFile(const char* fileName, Student* students, int numberOfStudents);
Student* readFromBinFile(const char* fileName);

int main()
{
	//Part A
	int* coursesPerStudent = NULL;
	int numberOfStudents = 0;
	char*** students = makeStudentArrayFromFile("studentList.txt", &coursesPerStudent, &numberOfStudents);
	factorGivenCourse(students, coursesPerStudent, numberOfStudents, "Advanced Topics in C", +5);
	printStudentArray(students, coursesPerStudent, numberOfStudents);
	//studentsToFile(students, coursesPerStudent, numberOfStudents); //this frees all memory. Part B fails if this line runs. uncomment for testing (and comment out Part B)
	
	//Part B
	Student* transformedStudents = transformStudentArray(students, coursesPerStudent, numberOfStudents);
	writeToBinFile("students.bin", transformedStudents, numberOfStudents);
	Student* testReadStudents = readFromBinFile("students.bin");

	//add code to free all arrays of struct Student


	/*_CrtDumpMemoryLeaks();*/ //uncomment this block to check for heap memory allocation leaks.
	// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

	return 0;
}

void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
{
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

	for (int i = 0; i < students_num; i++) {
		if (fgets(buffer, maxlinesize, file) == NULL) exit(33);

		temp_courses[i] = countPipes(buffer, maxlinesize);
	}
	*coursesPerStudent = temp_courses;
	fclose(file);
}

int countPipes(const char* lineBuffer, int maxCount)
{
	int counter = 0;
	if (lineBuffer == null)return -1;
	for (int i = 0; i < maxCount; i++) {
		if (lineBuffer[i] == '|')
			Counter++;
	}
	return counter;
}

char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
{
	char** pointers[20];

	FILE* file = fopen(fileName, "r");
	char line[maxlinesize];

	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents);

	while (fgets(line, maxlinesize, file)) {

		char* buffer = (char*)malloc(maxlinesize * 1);
		char* buffer2 = (char*)malloc(maxlinesize * 1);
		int courses = countPipes(line, maxlinesize), j = 0;
		strcpy(buffer, line);

		for (int i = 0; i <= courses; i++) {
			strtok(buffer, "|");
			pointers[j] = buffer;
			j++;

			int temp = strlen(buffer);
			strtok(buffer, ",");
			pointers[j] = buffer + strlen(buffer) + 1;
			j++;
			buffer += temp + 1;
		}
		printf("%s\n", pointers[j - 1]);
	}


	fclose(file);
}

void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor)
{
	if (students != NULL && numberOfStudents > 0 && factor >= -20 && factor <= 20) {
		for (int i = 0; i < numberOfStudents; i++) {
			for (int j = 1; j < coursesPerStudent[i] * 2; j += 2)
				if (strcmp(courseName, students[i][j]) == 0) {
					int grade = atoi(students[i][j + 1]);
					grade += factor;
					if (grade > 100)
						grade = 100;
					else if (grade < 0)
						grade = 0;
					char grade_ascii[20];
					_itoa(grade, grade_ascii, 10);
					free(students[i][j + 1]);
					students[i][j + 1] = (char*)malloc(strlen(grade_ascii) * sizeof(char) + 1);
					strcpy(students[i][j + 1], grade_ascii);
					break;
				}
		}
	}
}

void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		printf("name: %s\n*********\n", students[i][0]);
		for (int j = 1; j <= 2 * coursesPerStudent[i]; j += 2)
		{
			printf("course: %s\n", students[i][j]);
			printf("grade: %s\n", students[i][j + 1]);
		}
		printf("\n");
	}
}

void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents)
{
	if (students != NULL) {
		FILE* fi = fopen("studentList.txt", "w");
		for (int i = 0; i < numberOfStudents; i++)
		{

		}
		for (int i = 0; i < numberOfStudents; i++)
		{
			free(*students);
		}
		free(students);
		free(coursesPerStudent);
}
void writeToBinFile(const char* fileName, Student* students, int numberOfStudents)
{
	if (fileName != NULL && students != NULL) {
		FILE* fi = fopen(fileName, "wb");
		fwrite(&numberOfStudents, sizeof(numberOfStudents), 1, fi);
		for (int i = 0; i < numberOfStudents; i++) {
			fwrite(students[i].name, 35, 1, fi);
			fwrite(&students[i].numberOfCourses, sizeof(int), 1, fi);
			fwrite(students[i].grades, sizeof(StudentCourseGrade), students[i].numberOfCourses, fi);
		}
		fclose(fi);
	}
}

Student* readFromBinFile(const char* fileName)
{
	if (fileName != NULL) {
		FILE* fi = fopen(fileName, "rb");
		int numberofstudents;
		fread(&numberofstudents, sizeof(numberofstudents), 1, fi);
		Student* st = (Student*)malloc(numberofstudents * sizeof(Student));
		for (int i = 0; i < numberofstudents; i++) {
			fread(st[i].name, 35, 1, fi);
			fread(&st[i].numberOfCourses, sizeof(int), 1, fi);
			st[i].grades = (StudentCourseGrade*)malloc(st[i].numberOfCourses * sizeof(StudentCourseGrade));
			fread(st[i].grades, sizeof(StudentCourseGrade), st[i].numberOfCourses, fi);
		}
		fclose(fi);
		return st;
	}
	else
		return NULL;
}

Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents)
{
	if (student != null) {
		student* s = (students*)calloc(1, , numberOfStudents * sizeof(students));
		for (int i = 0; i < numberOfStudents; i++)
		{
			strcpy(s[i].name, student[i][0]);
			s[i].numberOfStudents = coursesPerStudent[i];
			s[i].grades = (StudentCourseGrade*)malloc(coursesPerStudent[i] * sizeOf(StudentCourseGrade));
			int k = 0;
			for (int j = 1; j < coursesPerStudent[i] * 2; j += 2) {
				strcpy(st[i].grades[k].courseName, students[i][j]);
				st[i].grades[k].grade = atoi(students[i][j + 1]);
				k++;
			}
		}
		return s;
	}
	return NULL;
}
void free(students* st, int num)
{
	if (st == null)
	{
		for (int i = 0; i < num; i++)
			free(st->grades);
	}
	free(st);
}