#include <stdio.h>

void falsedoubler(int x, int y){
    x*=2;
    y*=2;
}

void truedoubler(int* x, int* y){
    *x*=2;
    *y*=2;
}

int main(){
    int x = 40, y = 60;
    falsedoubler(x, y);
    printf("x = %d, y = %d", x, y);

    truedoubler(&x, &y); 
    printf("x = %d, y = %d", x, y);


    return 0;
}