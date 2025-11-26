#include <stdio.h>

int main() {
    int num = 13;
    int num_2 = 73;

    int sum = num + num_2;

    char buffer[50]; //array of char created to declare strings
    snprintf(buffer, sizeof(buffer), "The %s is %d + %d = %d","equation", num, num_2, sum); //"d" representing int

    printf("%s\n", buffer);
    return 0;

}