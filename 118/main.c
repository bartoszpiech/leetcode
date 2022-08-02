#include <stdio.h>
#include <stdlib.h>



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **triangle = malloc(sizeof(int * ) * numRows);
    int *retColSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        triangle[i] = malloc(sizeof(int) * (i + 1));
        retColSizes[i] = i + 1;
    }
    // fill edges with 1's
    for (int i = 0; i < numRows; i++) {
        triangle[i][0] = 1;
        triangle[i][retColSizes[i] - 1] = 1;
    }
    // fill insides
    for (int i = 0; i < numRows; i++) {
        for (int j = 1; j < retColSizes[i] - 1; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i-1][j];
        }
    }
    *returnSize = numRows;
    *returnColumnSizes = retColSizes;
    return triangle;
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
    int rows = 6;
    int retsize;
    int *retcolsize;
    int **triangle = generate(rows, &retsize, &retcolsize);
    //printf("## %d %d ##\n", retsize, retcolsize[0]);
    print(triangle, retsize, retcolsize);
    return 0;
}
