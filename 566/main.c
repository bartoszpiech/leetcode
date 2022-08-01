#include <stdio.h>
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (r * c != matSize * *matColSize) {
        return mat;
    }
    int **resultMatrix = malloc(sizeof(int *) * r);
    *returnColumnSizes = malloc(sizeof(int));
    *returnSize = r;
    **returnColumnSizes = c;
    //printf("%d %dsss\n", *returnSize, **returnColumnSizes);
    for (int i = 0; i < r; i++) {
        resultMatrix[i] = malloc(sizeof(int) * c);
    }
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            int ind = i * matSize + j;
            //printf("ind: %d - ", ind);

            int indc = ind / r;
            int indr = ind - indc;
            //printf("%d %d\n", indr, indc);
            resultMatrix[indr][indc] = mat[i][j];
        }
    }
    return resultMatrix;

}

void print(int **mat, int matSize, int* matColSize) {
    printf("{\n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

int main() {

    int rows = 2;
    int cols = 2;
    int *colsp = &cols;
    int **matrix = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(int) * cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * rows + j + 1;
        }
    }
    print(matrix, rows, colsp);
    int retsize;
    int *retcolsize;
    int **matrix_converted = matrixReshape(matrix, rows, colsp, 1,4, &retsize, &retcolsize);
    print(matrix_converted, retsize, retcolsize);
    return 0;
}
