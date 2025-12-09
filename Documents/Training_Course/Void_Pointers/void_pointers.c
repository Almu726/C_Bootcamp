#include <stdio.h>

int main(){
    int a = 5;
    int b = 15;

    //setting a void pointer to refer to the memory address of int a
    void *p1 = &a;
    printf("Pointer 1 - Memory Address: %p\n, Value: %d\n", p1, *(int*)p1);

    //%p is a call to a pointer method
    //*(int*)p1 references the pointer as an int and thus gives the value its holding (typecasted)

    p1 = &b;
    printf("Pointer 1 - Memory Address: %p\n, Value: %d\n", p1, *(int*)p1);

    return 0;
}   
