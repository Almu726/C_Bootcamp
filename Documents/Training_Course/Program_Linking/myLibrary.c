#include <stdio.h>
#include "myLibrary.h"

int main(void) {
    int x;
    int b = 5;


    int equation_1(int x);{
        for (x = 0; x < 10; x++) {
            return 8 * x + 12;
        }
    }



    int equation_2(int x);{
        x = 2 * x * x + 4 * x + 6;
        return x;
    }


    
    int equation_3(int x, int b);{
        for (x = 0; x < b; x++) {
            return 3 * x + 7 * b;
        }
    }



    int equation_4(int x, int b);{
        return x * x + b * b;
    }



    int equation_5(int x, int b);{
        for (x = 0; x <= b; x++)
    return x + x - b;
    }
}