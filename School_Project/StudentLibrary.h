#ifndef STUDENT_LIBRARY_H
#define STUDENT_LIBRARY_H

typedef struct Student {
    char name[30];
    char subjects[3][30];
    int grades[3];
    struct Student *next;  
} Student;

extern Student *student_head;  

void Add_Student_Record(Student **head);
void View_Grades(const Student *s);
void Find_Students_By_Subject(const char *subject);

#endif