#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "StudentLibrary.h"
#include "TeacherLibrary.h"

int main(){
    int role;
    char name[30];
    Student s;
    Teacher t;

    while (1) {
        printf("\n---------------------------------------------\n");
        printf("Are you a Student (1), \nOr a Teacher (2) : ");
    

        if (scanf(" %d", &role) != 1) {
            printf("scanf failed\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
            

    }
        if (role == 1) {
            If_Student(role, name);
            sleep(1);
            Add_Student_Record(&s);

            int choice;
            while (1) {
                printf("\n--- Student Menu ---\n");
                printf("1. View Grades\n");
                printf("2. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                    View_Grades(&s);
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
            Add_Teacher_Record(&t);
            int choice;
            while (1) {
                printf("\n--- Teacher Menu ---\n");
                printf("1. Enter Grade for Student\n");
                printf("2. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                    char subject[30];
                    int grade;

                    printf("Enter subject to grade: ");
                    fgets(subject, sizeof(subject), stdin);
                    subject[strcspn(subject, "\n")] = '\0';

                    printf("Enter grade: ");
                    scanf("%d", &grade);
                    getchar();

                    Enter_Grade(&s, subject, grade);
                } else if (choice == 2) {
                    break;
                } else {
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
           