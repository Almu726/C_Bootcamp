#include <stdio.h>
//EXCERCISE 2
int main(){
    int first = 313;
    int second = 85;

    void *pfirst = &first;
    void *psecond = &second;

    printf("Original Memory of pfirst: %p\n, Value: %d\n", pfirst, *(int*)pfirst);
    printf("Original Memory of psecond: %p\n, Value: %d\n", psecond, *(int*)psecond);

    int void_printers(void *pfirst, void *psecond);{
        int temp = *(int*)pfirst;        // reads value at pfirst
        *(int*)pfirst = *(int*)psecond;  // copies value from psecond into pfirst
        *(int*)psecond = temp;           // copy temp into psecond
}

        printf("Memory of pfirst: %p\n, Value: %d\n", pfirst, *(int*)pfirst);
        printf("Memory of psecond: %p\n, Value: %d\n", psecond, *(int*)psecond);
        return 0;
    }

    
