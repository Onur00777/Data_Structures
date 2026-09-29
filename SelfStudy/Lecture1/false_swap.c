/*
x ve y değerleri isteneildiği gibi swap olmayacak çünkü 
passed by value oldular ve sadece fonk. içinde değiştiler. Asıl değerleri swap olamadı. 
*/

#include <stdio.h>

static void swap(int x, int y){
    int temp;
    temp = x; x = y; y = temp;
}

int main(){
    int x=60; int y=32;
    swap(x, y);
    printf("x = %d, y = %d", x, y);
    return 0;
}