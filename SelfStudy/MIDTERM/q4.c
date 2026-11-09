/*Q4) [10 pts] Write the C code for a recursive function which determines the length of the
longest sublist composed of contiguous identical elements for a given integer array. As an
example, for the array int a[] = {5,7,8,8,8,8,3,3,1}, the function will return 4, since it has four
“8”s as a sequence. You can decide on the function parameters and how the function is called
first. What is the big-oh complexity of the function?*/

#include <stdio.h>
int length_of_the_longest_sublist(int a[], int n){
    int current_count = 1;
    int max_count = 1;
    int number = a[0];
    for (int i = 1; i<n; i++){
        if(a[i] == number){
            current_count++;
        }else{
            number = a[i];
            
        }
        if(current_count > max_count){
            max_count = current_count;
        }

    }
    return max_count;
}

int main(){
    int a[5] = {1, 2, 2, 2, 7};
    int number = length_of_the_longest_sublist(a, 5);
    printf("%d", number);
    return 0;
}