#ifndef TEACHER_LIBRARY_H
#define TEACHER_LIBRARY_H

#include <stdio.h>
#include "StudentLibrary.h"   

typedef struct {
    char name[30];
    char subject[30];      
} Teacher;

typedef struct {
    char student_name[30];
    char subject[30];
    int grade;
} GradeRecord;


void If_Teacher(int role, char name[30]);
void Add_Teacher_Record(Teacher *t);
void Enter_Grade(Student *s, const char *subject, int grade);

#endif