/*
   n pancakes with different sizes are given. They are stacked on top of each other.
   We insert a spatula under the top k pancakes and flip them all over.
   Goal: sort them so the smallest pancake is on top and the biggest one is at the bottom.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flip(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void pancakeSort(int arr[], int size) {
    for (int end = size; end > 1; end--) {
        int maxIndex = 0;

        for (int i = 1; i < end; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        if (maxIndex != end - 1) {
            flip(arr, maxIndex + 1);
            flip(arr, end);
        }
    }
}

int main() {
    int n;

    printf("Enter pancake number: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid pancake number.\n");
        return 1;
    }

    int pancakes[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        pancakes[i] = i + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = pancakes[i];
        pancakes[i] = pancakes[j];
        pancakes[j] = temp;
    }

    printf("Randomly placed pancake sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", pancakes[i]);
    }
    printf("\n\n");

    pancakeSort(pancakes, n);

    printf("Sorted pancake sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", pancakes[i]);
    }
    printf("\n");

    return 0;
}
// O(n^2) 
