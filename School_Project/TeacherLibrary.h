#ifndef TEACHER_LIBRARY_H
#define TEACHER_LIBRARY_H

#include "StudentLibrary.h"

typedef struct Teacher {
    char name[30];
    char subject[30];
    struct Teacher *next;  
} Teacher;

extern Teacher *teacher_head; 

void If_Teacher(int role, char name[30]);
void Add_Teacher_Record(Teacher **head);
void Enter_Grade(Student *s, const char *subject, int grade);
void Find_Teacher_By_Subject(const char *subject);

#endif