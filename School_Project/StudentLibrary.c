#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "StudentLibrary.h"

Student *student_head = NULL;

// this entire function might be unneccessary and it doesnt work or do anything anyways
void If_Student(int role, char bame[30]) {
    if (role == 1) {
        char name[30];

        printf("\nWelcome to Sky's Student Hub!\nPlease enter your name: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("\nHello & Welcome %s!\n", name);
        sleep(1);
    }
}

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