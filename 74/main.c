#include <stdio.h>
#include <stdlib.h>



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
