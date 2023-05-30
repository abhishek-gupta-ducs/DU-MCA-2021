#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int size, rank, message;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        message = 17;
        MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent message %d to process 1.\n", message);
    } else if (rank == 1) {
        MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received message %d from process 0.\n", message);
    }
    MPI_Finalize();
    return 0;
}
