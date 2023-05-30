#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 5
#define NUM_THREADS 5

int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
int result[ARRAY_SIZE] = {0};

void *add_arrays(void *arg) {
    int thread_id = *(int*) arg;
    int start = thread_id * ARRAY_SIZE / NUM_THREADS;
    int end = (thread_id + 1) * ARRAY_SIZE / NUM_THREADS;

    for (int i = start; i < end; i++) {
        result[i] = array1[i] + array2[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, add_arrays, (void*) &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Resultant Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
