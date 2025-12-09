#include <stdio.h>
#include "TeacherLibrary.h"
#include <string.h>



void If_Teacher(int role, char name[30]) { 

    while (role == 2){
        printf("\nWelcome to Sky's Teacher Hub!\nPlease enter your name: ");
        fgets(name, 30, stdin);
        break;
    }
    if (fgets(name,30,stdin) != NULL){
        printf("\nHello and welcome %s\n", name);
    }
            
}
      
   

