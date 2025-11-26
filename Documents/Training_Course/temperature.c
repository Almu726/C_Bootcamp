#include <stdio.h>

int celcius_to_farenheight(int celcius) {
    return celcius * 1.8 + 32; 
}

int celcius_to_kelvin(int celcius) {
    return celcius + 273;
}

int main() {
    int celcius = 27;

    int farenheight = celcius_to_farenheight(celcius);
    int kelvin = celcius_to_kelvin(celcius);

    char buffer[60];
    snprintf(buffer, sizeof(buffer), "%d°C is %d°F and %dK", celcius, farenheight, kelvin);
    printf("%s\n", buffer);
        return 0;
}