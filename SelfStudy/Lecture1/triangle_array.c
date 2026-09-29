/*
sizeof kaç byte yer kapladığını verir. Her float 4 byte'tır.
*/

#include <stdio.h>

int main(){
    float triangle[] = { 2.0, 1.5, 3.5 }; //float'lardan oluşan array

    printf("A = %f\n", triangle[0]);
    printf("B = %f\n", triangle[1]);
    printf("C = %f\n", triangle[2]);

    printf("ABC takes %zu bytes of space.\n", sizeof(triangle)); //sizeof için %zu

    //-----------------------------------------------------------------------------

    int eleman_sayisi = sizeof(triangle) / sizeof(triangle[0]);

    for(int i = 0; i<eleman_sayisi; i++){
        triangle[i]*=2;
    }
    printf("ABC STILL takes %zu bytes of space.\n", sizeof(triangle)); //sizeof için %zu

    return 0;
}