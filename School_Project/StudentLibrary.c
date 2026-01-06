#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "StudentLibrary.h"

Student *student_head = NULL;


void Add_Student_Record(Student **head) {
    Student *new_student = malloc(sizeof(Student));
    if (!new_student) return;

    printf("Enter student name: ");
    fgets(new_student->name, sizeof(new_student->name), stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0';

    for (int i = 0; i < 3; i++) {
        printf("Enter subject %d: ", i + 1);
        fgets(new_student->subjects[i], sizeof(new_student->subjects[i]), stdin);
        new_student->subjects[i][strcspn(new_student->subjects[i], "\n")] = '\0';
        new_student->grades[i] = 0;
    }

    new_student->next = *head;
    *head = new_student;
}

void View_Grades(const Student *s) {
    printf("Grades for %s:\n", s->name);
    for (int i = 0; i < 3; i++) {
        printf("  %s: %d\n", s->subjects[i], s->grades[i]);
    }
}

void Find_Students_By_Subject(const char *subject) 
{
    Student *current = student_head;
    int found = 0;

    printf("\nStudents studying %s:\n", subject);

    while (current != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(current->subjects[i], subject) == 0)
            {
                printf("- %s\n", current->name);
                found = 1;
                break;  
            }
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No students found for this subject.\n");
    }
}
