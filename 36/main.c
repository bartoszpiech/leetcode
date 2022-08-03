#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char board[][9], int boardSize, int* boardColSize){
    // check horizontal
    int hashmapbox[3][3][10] = { 0 };
    int hashmapvert[9][10] = { 0 };
    for (int i = 0; i < boardSize; i++) {
        int hashmap[10] = { 0 };
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            if (hashmap[board[i][j] - 48]++ > 0) {
                return false;
            }
            if (hashmapvert[j][board[i][j] - 48]++ > 0) {
                return false;
            }
            //printf("[%d][%d][%c]\n", (i) / 3, (j) / 3, board[i][j]);
            if (hashmapbox[i / 3][j / 3][board[i][j] - 48]++ > 0) {
                //printf("[%d][%d][%c]\n", (i + 1) / 3, (j + 1) / 3, board[i][j]);
                return false;
            }
        }
    }
    /*
    int hashmapbox[10] = { 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //int ind = (8 + 1) / 3;
            //printf("%d - %d %d \n", ind, i, j);
            if (board[i][j] == '.') {
                continue;
            }
            if (hashmapbox[board[i][j] - 48]++ > 0) {
                //printf("%d %d - %c\n", i, j, board[i][j]);
                return false;
            }
        }
    }
    */
    return true;
}


void print(char board[][9], int boardSize, int* boardColSize) {
    printf("{\n");
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}

int main() {
    int boardSize = 9;
    int boardColSize[] = { 9,9,9,9,9,9,9,9,9 };
    char board[][9] = {
     {'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}
    };

    print(board, boardSize, boardColSize);
    printf("%s\n", isValidSudoku(board, boardSize, boardColSize) ? "true" : "false");
    return 0;
}
