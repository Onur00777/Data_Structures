#include <stdio.h>

typedef float Triangle[3];

int main(){
    Triangle abc = { 1.5, 2.5, 3.0 };

    printf("A = %.2f\n", abc[0]);
    printf("B = %.2f\n", abc[1]);
    printf("C = %.2f\n", abc[2]);

    printf("ANY Triangle: %zu bytes\n", sizeof(Triangle));
    return 0;
}