#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    fptr = fopen("Santas' Secrets.txt", "w");

    if (fptr == NULL){
        printf("Error opening file!\n");
        return 1;
    }
    return 0;
}