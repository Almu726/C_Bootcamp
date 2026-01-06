#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "StudentLibrary.h"

const char* subjectNames[] = {
    "English", "Maths", "History", "Geography", "Science"
};

Student *student_head = NULL;

void Add_Student_Record(Student **head) {
    int count, subj, grade;
    Student *new_student = malloc(sizeof(Student));
    if (!new_student) return;

    printf("Enter student name: ");
    fgets(new_student->name, sizeof(new_student->name), stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0';

    printf("How many subjects does %s study? ", new_student->name);
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter Subject %d: ", i + 1);
        scanf("%d", &subj)
        
        printf("Enter Grade (1-9): ");
        int grade;
        scanf("%d", &grade);

        
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

void Find_Students_By_Subject(const char *subject) {
    Student *curr = student_head;
    printf("Students studying %s:\n", subject);
    while (curr) {
        for (int j = 0; j < 3; j++) {
            if (strcmp(curr->subjects[j], subject) == 0) {
                printf("  %s\n", curr->name);
                break;
            }
        }
        curr = curr->next;
    }
}