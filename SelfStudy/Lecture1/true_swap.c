/*
x ve y değerleri swap olacak çünkü fonk. içine memory'deki adresleri verilmiş olacak. 
*/

#include <stdio.h>

static void swap(int* const x, int* const y){
    int temp;
    temp = *x; *x = *y; *y = temp; //direkt orijinal değer değişir. 
}

int main(){
    int x=60; int y=32;
    swap(&x, &y);
    printf("x = %d, y = %d", x, y);
    return 0;
}