#include <stdio.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (r * c != matSize * *matColSize) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    int **resultMatrix = malloc(sizeof(int *) * r);
    int *retColSize = malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        resultMatrix[i] = malloc(sizeof(int) * c);
        retColSize[i] = c;
    }
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            int ind = i * matColSize[i] + j;
            int indr = ind / c;
            int indc = ind % c;
            printf("$$%d - %d %d$$\n", ind, indr, indc);
            resultMatrix[indr][indc] = mat[i][j];
        }
    }
    *returnSize = r;
    *returnColumnSizes = retColSize;
    return resultMatrix;
}

void print(int **mat, int matSize, int* matColSize) {
    printf("{\n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

int main() {
    int rows = 2;
    int cols[] = { 2,2 };
    int **matrix = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(int) * cols[i]);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            matrix[i][j] = i * rows + j + 1;
        }
    }
    print(matrix, rows, cols);
    int retsize;
    int *retcolsize;
    int **matrix_converted = matrixReshape(matrix, rows, cols, 4, 1, &retsize, &retcolsize);
    printf("## %d %d ##\n", retsize, retcolsize[0]);
    print(matrix_converted, retsize, retcolsize);
    return 0;
}
