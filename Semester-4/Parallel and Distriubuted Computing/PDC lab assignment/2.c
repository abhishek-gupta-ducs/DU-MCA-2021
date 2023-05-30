#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 20

void quicksort(int *arr, int left, int right);
int partition(int *arr, int left, int right);

int main() {
    int arr[SIZE];
    int i;
    double start, end;
    
    // Initialize the array with random values
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }
    
    // Perform parallel quicksort
    start = omp_get_wtime();
    #pragma omp parallel
    {
        printf("Number of threads: %d\n", omp_get_num_threads());
        #pragma omp single
        quicksort(arr, 0, SIZE-1);
    }
    end = omp_get_wtime();
    
    // Print the sorted array and the time taken
    printf("Time taken: %f seconds\n", end - start);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void quicksort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(arr, left, right);
    #pragma omp task
    quicksort(arr, left, pivot-1);
    #pragma omp task
    quicksort(arr, pivot+1, right);
    #pragma omp taskwait
}

int partition(int *arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && arr[i] <= pivot) {
            i++;
        }
        while (j >= left+1 && arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    return j;
}