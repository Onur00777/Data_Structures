#include <stdio.h>

void doubleSides(float* const pabc){
    pabc[0]*=2.00;
    pabc[1]*=2.00;
    pabc[2]*=2.00;
    printf("%zu\n", sizeof(pabc)); // pointer 8 byte döndürür.

}

int main(){
    float abc[] = { 1.5, 2.0, 2.5 };
    printf("%zu\n", sizeof(abc)); //3 adet float içerdiği için 12 basar.
    doubleSides(abc);
    return 0;
}