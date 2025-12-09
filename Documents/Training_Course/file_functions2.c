#include <stdio.h>
#include <stdlib.h>    

int main(){
    FILE *fptr;
    char contents[] = "Secret 1: Santa is on the naughty list";

    
    fptr = fopen("Santas' Secrets.txt", "w");
    if (fptr == NULL) 
        printf("The file is not opened.");
    else{
        printf("The file is now opened.\n");
        fputs(contents, fptr);
        fputs("\n", fptr);

       fclose(fptr);
    printf("Contents successfuly written into file\n");

    
}
    return 0;
}