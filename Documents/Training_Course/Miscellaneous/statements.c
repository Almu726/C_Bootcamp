#include <stdio.h>
int main() {
    int A = 0;
    int B = 0;
    int i = 0;
   

    while (i < 20){
            
    
        if (B % 2 == 0){
            printf("The even number B is currently %d\n", B);
        }

        if (A % 2 != 0){
            printf("The odd number A is currently %d\n", A);
        }

        B = B + 7;
        A = A + 3; 
        i++;
    }
}