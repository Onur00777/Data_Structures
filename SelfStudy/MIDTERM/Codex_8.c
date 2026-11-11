/*Q8) [15 pts] — Recursion & Arrays
Write a recursive C function with the following signature:
int count_peaks(int arr[], int n);


The function counts the number of peak elements in an integer array.
An element is considered a peak if its value is strictly greater than both its immediate neighbors.
The first and last elements of the array cannot be peaks.
You must use recursion. Loops and additional arrays are not allowed.*/
int count_helper(int arr[], int n, int i){
    if(i>=n-1){
        return 0;
    }
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        return 1+count_helper(arr, n, i+1);
    }else{
        return count_helper(arr, n, i+1);
    }
}
int count_peaks(int arr[], int n){
    int i = 1;
    return count_helper(arr, n, i);
}
