#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "StudentLibrary.h"
#include "TeacherLibrary.h"

int main(){
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
        if (role == 1) {
            If_Student(role, name);
            sleep(2);
            Add_Student_Record();
            
            
        }

        else if (role == 2) {
            If_Teacher(role, name);
            sleep(2);
            Add_Teacher_Record();
            
        }

        else {
            printf("\nPlease enter a valid option from 1 or 2");
            sleep(2);
            system("clear");
        }
    
}
}