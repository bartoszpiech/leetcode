#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][4], int matrixSize, int* matrixColSize, int target){
    // search row
    int lind = 0, rind = matrixSize;
    int ind;
    if (target > matrix[matrixSize - 1][matrixColSize[matrixSize - 1] - 1] ||
        target < matrix[0][0]) {
        return false;
    }
    while (lind <= rind) {
        int mid = lind + (rind - lind) / 2;
        printf("%d - %d %d\n", mid, lind, rind);
        printf("%d %d ---\n", matrix[mid][0], matrix[mid][matrixColSize[mid] - 1]);
        if (matrix[mid][0] <= target && matrix[mid][matrixColSize[mid] - 1] >= target) {
            ind = mid;
            break;
        }
        else if (matrix[mid][0] > target) {
            rind = mid;
        }
        else if (matrix[mid][0] < target) {
            lind = mid;
        } else {
            ind = -1;
            break;
        }
    }
    // search inside the row
    printf("%d -- row", ind);
}

void print(int mat[][4], int matSize, int* matColSize) {
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
    int matrix[3][4] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int matrixSize = 3;
    int matrixColSize[] = { 4, 4, 4, 4 };
    int target = 8;
    print(matrix, matrixSize, matrixColSize);
    searchMatrix(matrix, matrixSize, matrixColSize, target);
    return 0;
}
