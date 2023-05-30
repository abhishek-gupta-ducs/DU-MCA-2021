#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 3

// Matrices
int A[MATRIX_SIZE][MATRIX_SIZE];
int B[MATRIX_SIZE][MATRIX_SIZE];
int C[MATRIX_SIZE][MATRIX_SIZE];

// Thread arguments
struct thread_args {
    int row;
    int col;
};

// Function prototypes
void *init_matrix(void *arg);
void *calc_matrix(void *arg);

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Create threads
    pthread_t init_threads[MATRIX_SIZE * MATRIX_SIZE];
    pthread_t calc_threads[MATRIX_SIZE * MATRIX_SIZE];
    
    // Initialize A and B matrices with random values
    struct thread_args init_args[MATRIX_SIZE * MATRIX_SIZE];
    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            // Set thread arguments
            init_args[i * MATRIX_SIZE + j].row = i;
            init_args[i * MATRIX_SIZE + j].col = j;
            
            // Create thread
            pthread_create(&init_threads[i * MATRIX_SIZE + j], NULL, init_matrix, &init_args[i * MATRIX_SIZE + j]);
        }
    }
    
    // Wait for initialization threads to finish
    for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        pthread_join(init_threads[i], NULL);
    }
    
    // Calculate C matrix using threads
    struct thread_args calc_args[MATRIX_SIZE * MATRIX_SIZE];
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            // Set thread arguments
            calc_args[i * MATRIX_SIZE + j].row = i;
            calc_args[i * MATRIX_SIZE + j].col = j;
            
            // Create thread
            pthread_create(&calc_threads[i * MATRIX_SIZE + j], NULL, calc_matrix, &calc_args[i * MATRIX_SIZE + j]);
        }
    }
    
    // Wait for calculation threads to finish
    for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        pthread_join(calc_threads[i], NULL);
    }
    
    // Print matrices A, B, and C
    printf("Matrix A:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix B:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix C:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

// Thread function for initializing matrix elements
void *init_matrix(void *arg) {
    struct thread_args *args = (struct thread_args *) arg;
    int row = args->row;
    int col = args->col;
    A[row][col] = rand() % 10;
    B[row][col] = rand() % 10;
    pthread_exit(NULL);
}

// Thread function for calculating matrix elements
void *calc_matrix(void *arg) {
    struct thread_args *args = (struct thread_args *) arg;
    int row = args->row;
    int col = args->col;
    int k;
    C[row][col] = 0;
    for (k = 0; k < MATRIX_SIZE; k++) {
        C[row][col] += A[row][k] * B[k][col];
    }
    pthread_exit(NULL);
}