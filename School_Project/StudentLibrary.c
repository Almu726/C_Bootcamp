#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "StudentLibrary.h"


void If_Student(int role, char name[30]) {
        
    while (role == 1){
        printf("\nWelcome to Sky's Student Hub!\nPlease enter your name: ");
        fgets(name, 30, stdin);
    }
    
    if (fgets(name,30,stdin) != NULL){
        printf("\nHello & Welcome %s!\n", name);
    
            
    }
            
}

void Add_Student_Record(){

    char subject1[60] = "Student Subject 1: ";
    char subject2[60] = "Student Subject 2: ";
    char subject3[60] = "Student Subject 3: ";

    
    printf("Enter Subject 1 Name: ");
    fgets(subject1, 60, stdin);
        
        

    printf("Enter Subject 2 Name: ");
    fgets(subject2, 60, stdin);
        
        

    printf("Enter Subject 3 Name: ");
    fgets(subject2, 60, stdin);
     

    FILE* fptr;
    fptr = fopen("StudentRecords.txt", "w");
    fputs(subject1, fptr);
    fputs("\n", fptr);
    fputs(subject2, fptr);
    fputs("\n", fptr);
    fputs(subject3, fptr);



    


    
}


