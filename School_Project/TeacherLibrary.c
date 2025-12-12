#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "TeacherLibrary.h"
#include "StudentLibrary.h"



void If_Teacher(int role, char name[30]) { 

    if (role == 2){
        printf("\nWelcome to Sky's Teacher Hub!\nPlease enter your name: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
        if (fgets(name,30,stdin) != NULL){
            name[strcspn(name, "\n")] = 0;
            printf("\nHello & Welcome %s!\n", name);
            sleep(1);

        }
}
            
void Add_Teacher_Record(Teacher *t){
    char subject[40];
    printf("Enter Subject you teach: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0';
    printf("\nSubject successfully entered.");

    char Teacher_Subject[60];
    snprintf(Teacher_Subject, sizeof(Teacher_Subject), "Teacher Subject: %s", subject);


    FILE *fptr;
    fptr = fopen("TeacherRecords.txt", "a");
    if (fptr != NULL) {
        fputs(Teacher_Subject, fptr);
        fputs("\n", fptr);
        fclose(fptr);
    } else {
        printf("Error opening file!\n");
        
    }
}   

void Enter_Grade(Student *s, const char *subject, int grade) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(s->subjects[i], subject) == 0) {
            s->grades[i] = grade;

            GradeRecord gr;
            strcpy(gr.student_name, s->name);
            strcpy(gr.subject, subject);
            gr.grade = grade;

            FILE *fp = fopen("Grades.dat", "ab");
            if (fp) {
                fwrite(&gr, sizeof(GradeRecord), 1, fp);
                fclose(fp);
            }
            return;
        }
    }
}


    



  


      
   

