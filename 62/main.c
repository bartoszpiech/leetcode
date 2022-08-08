#include <stdio.h>
#include <stdlib.h>

/*
 * pascal's triangle
 * 0    1   2   3   4   5   6   7   8
 * 1    1   1   1   1   1   1   1   1
 * 2    1   2   3   4   5   6   7
 * 3    1   3   6   10  15  21  28
 * 4    1   4   10  20  35  56  84
 * 5    1   5   15  35  70  126 210
 * 6    1   6   21  56  126
 * 7    1   7   28  84  210
 * 8    1
 * 9    1
 * 10   1
 */

// pascal's triangle generation
unsigned int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    unsigned int **triangle = malloc(sizeof(unsigned int * ) * numRows);
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

int uniquePaths(int m, int n){
    int min = m > n ? n : m;
    int row = m + n - 1;
    int size;
    int *colSizes;
    unsigned int **triangle = generate(row, &size, &colSizes);
    return triangle[row - 1][min - 1];
}

int main() {
    printf("%d\n", uniquePaths(3, 2));
    printf("%d\n", uniquePaths(4, 5));
    printf("%d\n", uniquePaths(7, 3));
    printf("%d\n", uniquePaths(10, 10));
    printf("%d\n", uniquePaths(20, 7));
    return 0;
}
