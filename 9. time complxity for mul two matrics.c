#include <stdio.h>
#include <time.h>

#define SIZE 100 
void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int m, int n, int p) {
    int i, j, k;

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int m, n, p, i, j;
    clock_t start, end;
    double cpu_time_used;

    m = SIZE;
    n = SIZE;
    p = SIZE;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    start = clock();
    multiplyMatrices(A, B, C, m, n, p);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %lf seconds\n", cpu_time_used);

    return 0;
}
