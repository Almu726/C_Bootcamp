#include <stdio.h>
#include "StudentLibrary.h"


void If_Student(int role, char name[30]) {
        
    while (role == 1){
        printf("\nWelcome to Sky's Student Hub!\nPlease enter your name: ");
        fgets(name, 30, stdin);
        break;
    }
    if (fgets(name,30,stdin) != NULL){
        printf("\nHello and welcome %s\n", name);
    }
            
}


