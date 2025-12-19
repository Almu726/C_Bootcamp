#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "StudentLibrary.h"
#include "TeacherLibrary.h"

// gcc MainMenu.c StudentLibrary.c TeacherLibrary.c -o School_Project_Program

int main() {
    int role;
    char name[30];

    while (1) {
        printf("\n---------------------------------------------\n");
        printf("Are you a Student (1), \nOr a Teacher (2) : ");

        if (scanf(" %d", &role) != 1) {
            printf("scanf failed\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        getchar();

        if (role == 1) {
            // Name is uninitialised so not needed, role is already checked for so not needed?
            If_Student(role, name);
           
            Add_Student_Record(&student_head);

            int choice;
            while (1) {
                printf("\n--- Student Menu ---\n");
                printf("1. View Grades\n");
                printf("2. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                   
                    View_Grades(student_head);
                } else if (choice == 2) {
                    break;
                } else {
                    printf("Invalid choice.\n");
                }
            }
            break;
        }

        else if (role == 2) {
            If_Teacher(role, name);
            sleep(1);

           
            Add_Teacher_Record(&teacher_head);

            int choice;
            while (1) {
                printf("\n--- Teacher Menu ---\n");
                printf("1. Enter Grade for Student\n");
                printf("2. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                    if (student_head == NULL) {
                        printf("No students available yet.\n");
                        continue;
                    }

                 
                    int index = 1;
                    Student *curr = student_head;
                    printf("\nList of Students:\n");
                    while (curr) {
                        printf("%d. %s\n", index, curr->name);
                        curr = curr->next;
                        index++;
                    }

                    int student_index;
                    printf("Select student number: ");
                    scanf("%d", &student_index);
                    getchar();

                    curr = student_head;
                    index = 1;
                    while (curr && index < student_index) {
                        curr = curr->next;
                        index++;
                    }

                    if (!curr) {
                        printf("Invalid student selection.\n");
                        continue;
                    }

                    printf("\nSubjects for %s:\n", curr->name);
                    for (int i = 0; i < 3; i++) {
                        printf("%d. %s (Current grade: %d)\n", i + 1,
                               curr->subjects[i], curr->grades[i]);
                    }

                    int subject_index, grade;
                    printf("Select subject number: ");
                    scanf("%d", &subject_index);
                    getchar();

                    if (subject_index < 1 || subject_index > 3) {
                        printf("Invalid subject selection.\n");
                        continue;
                    }

                    printf("Enter grade: ");
                    scanf("%d", &grade);
                    getchar();

                    curr->grades[subject_index - 1] = grade;
                    printf("Grade updated: %s - %s = %d\n",
                           curr->name,
                           curr->subjects[subject_index - 1],
                           grade);
                }
                else if (choice == 2) {
                    break;
                }
                else {
                    printf("Invalid choice.\n");
                }
            }
            break;
        }

        else {
            printf("\nPlease enter a valid option from 1 or 2");
            sleep(2);
            system("clear");
            continue;
        }
    }
}