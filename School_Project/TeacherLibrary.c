#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "TeacherLibrary.h"



void If_Teacher(int role, char name[30]) { 

    while (role == 2){
        printf("\nWelcome to Sky's Teacher Hub!\nPlease enter your name: ");
        fgets(name, 30, stdin);
        break;
    }
    if (fgets(name,30,stdin) != NULL){
        printf("\nHello & Welcome %s!\n", name);
        sleep(1);

    }
}
            
void Add_Teacher_Record(){
    char Teacher_Subject[60] = "Teacher Subject: ";
    printf("Enter Subject you teach: ");
    scanf("%s", Teacher_Subject);


    FILE *fptr;
    fptr = fopen("TeacherRecords.txt", "w");
    fputs(Teacher_Subject, fptr);

}



  


      
   

