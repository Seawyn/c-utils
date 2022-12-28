#include <stdio.h>
#include <stdlib.h>

#define LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

void swap(float* a, float* b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(float arr[], int low, int high){
    float pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){ 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(float arr[], int low, int high){
    if (low >= high) return;

    int middle = partition(arr, low, high);
    
    quicksort(arr, low, middle - 1);
    quicksort(arr, middle + 1, high);
}

void print_array(float arr[], int len){
    for (int i = 0; i <= len; i++){
        printf("%f ", arr[i]);
    }

    printf("\n");
}

int main(void){
    float arr[] = {10, -3, 4, 7, 1, 20, -5, 5, 34, 1, 31, 2, -40, 59, -23, 47};
    int low = 0;
    int high = LENGTH(arr) - 1;

    printf("Unsorted array:\n");
    print_array(arr, high);

    quicksort(arr, low, high);
    
    printf("Sorted array:\n");
    print_array(arr, high);
    
    return 0;
}