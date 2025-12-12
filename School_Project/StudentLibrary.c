#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "StudentLibrary.h"


void If_Student(int role, char name[30]) {
        
    if (role == 1){
        printf("\nWelcome to Sky's Student Hub!\nPlease enter your name: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
        if (fgets(name,30,stdin) != NULL){
            name[strcspn(name, "\n")] = 0; 
            printf("\nHello & Welcome %s!\n", name);
            sleep(1);
        
                
        }
            
}

void Add_Student_Record(Student *s){

    char subject1[60];
    char subject2[60];
    char subject3[60];

    
    printf("Enter Subject 1 Name: ");
    fgets(subject1, sizeof(subject1), stdin);
    subject1[strcspn(subject1, "\n")] = '\0';
        
        

    printf("Enter Subject 2 Name: ");
    fgets(subject2, sizeof(subject2), stdin);
    subject2[strcspn(subject2, "\n")] = '\0';
        
        

    printf("Enter Subject 3 Name: ");
    fgets(subject3, sizeof(subject3), stdin);
    subject3[strcspn(subject3, "\n")] = '\0';
    printf("\nSubjects successfully entered.");
     

    FILE* fptr;
    fptr = fopen("StudentRecords.txt", "a");
    if (fptr != NULL) {
        fprintf(fptr, "Student Subject 1: %s\n", subject1);
        fprintf(fptr, "Student Subject 2: %s\n", subject2);
        fprintf(fptr, "Student Subject 3: %s\n", subject3);
        fclose(fptr);
    } else {
        printf("Error opening file!\n");

    }
}

int Load_Student_From_File(Student *s, FILE *fp) {


    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fp) == NULL) return 0;
    sscanf(buffer, "Student Subject 1: %29[^\n]", s->subjects[0]);

    if (fgets(buffer, sizeof(buffer), fp) == NULL) return 0;
    sscanf(buffer, "Student Subject 2: %29[^\n]", s->subjects[1]);

    if (fgets(buffer, sizeof(buffer), fp) == NULL) return 0;
    sscanf(buffer, "Student Subject 3: %29[^\n]", s->subjects[2]);


    for (int i = 0; i < 3; i++) s->grades[i] = 0;

    return 1;
}

void View_Grades(const Student *s) {
    printf("Grades for %s:\n", s->name);
    for (int i = 0; i < 3; i++) {
        printf("  %s: %d\n", s->subjects[i], s->grades[i]);
    }
}
  




