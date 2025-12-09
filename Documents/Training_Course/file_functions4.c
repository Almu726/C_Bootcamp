#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fptr;
    fptr = fopen("Santas' Secrets.txt", "r");

    fseek(fptr, 0, SEEK_END);
    printf("%ld", ftell(fptr));

    return 0;

}