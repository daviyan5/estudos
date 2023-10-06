#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        printf("Chave=%d\ni=%d\n",key,i);
        j = i - 1;
        printArray(arr,n);
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr,n);
    }
}
void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 8, 13, 15, 12, 6, 0, 24, 3, 38 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}