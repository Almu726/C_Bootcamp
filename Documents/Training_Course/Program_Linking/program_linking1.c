#include <stdio.h>
#include "program_linking.h"



int main(void) {
    int x = 10;
    int result = calculation(x);

    char buffer[60];
    snprintf(buffer, sizeof(buffer), "The result of 14x -15 is %d\n", result);
    printf("%s", buffer);
    return 0;
}