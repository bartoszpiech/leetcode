#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][4], int matrixSize, int* matrixColSize, int target){
    int colSize = matrixColSize[0]; // assume that colSize is const for every row
    int lind = 0;
    int rind = matrixSize * colSize;    // convert indexes to 1d array
    printf("%d -- %d\n", lind, rind);
    int ind;
    while (lind < rind) {
        int mid = lind + (rind - lind) / 2;
        int r = mid / colSize;  // convert to 2d array
        int c = mid % colSize;
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            rind = mid;
        } else {
            lind = mid + 1;
        }
    }
    return false;
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
    printf("%s\n", searchMatrix(matrix, matrixSize, matrixColSize, target) ? "true" : "false");
    return 0;
}
