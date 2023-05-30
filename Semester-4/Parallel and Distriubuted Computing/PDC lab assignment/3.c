#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define SEED 35791246

int main(int argc, char **argv) {
    int niter = atoi(argv[1]);
    int count = 0;
    double x, y;
    double pi;

    srand(SEED);

    #pragma omp parallel for private(x, y) reduction(+:count)
    for (int i = 0; i < niter; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            count++;
        }
    }

    pi = 4.0 * count / niter;

    printf("Estimated value of pi: %f\n", pi);

    return 0;
}
