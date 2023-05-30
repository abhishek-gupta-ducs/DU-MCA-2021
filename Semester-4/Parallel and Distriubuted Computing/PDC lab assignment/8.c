#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int main(int argc, char** argv) {
    int comm_size, rank;
    char str[MAX_STRING_SIZE];
    int str_len;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("Enter a string to be reversed:\n");
        fgets(str, MAX_STRING_SIZE, stdin);

        // remove the newline character from the end of the string
        str[strcspn(str, "\n")] = 0;

        str_len = strlen(str);
        MPI_Send(&str_len, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(str, str_len, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        
        MPI_Status status;
        MPI_Recv(&str_len, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(str, str_len, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        str[str_len] = '\0';
        
        // reverse the string
        int i, j;
        char temp;
        for (i = 0, j = str_len - 1; i < str_len / 2; i++, j--) {
            temp = str[i];
            str[i] = str[j];1
            str[j] = temp;
        }
        printf("Reversed String : %s\n",str);
        MPI_Send(str, str_len, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
