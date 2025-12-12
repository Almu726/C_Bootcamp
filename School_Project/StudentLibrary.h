#ifndef STUDENT_LIBRARY_H
#define STUDENT_LIBRARY_H

#include <stdio.h>


typedef struct {
    char name[30];
    char subjects[3][30];  
    int grades[3];         
} Student;


void If_Student(int role, char name[30]);
void Add_Student_Record(Student *s);
int Load_Student_From_File(Student *s, FILE *fp);
void View_Grades(const Student *s);
#endif