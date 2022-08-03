#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char board[][9], int boardSize, int* boardColSize){
    int hashmapbox[3][3][10] = { 0 };
    int hashmapvert[9][10] = { 0 };
    for (int i = 0; i < boardSize; i++) {
        int hashmap[10] = { 0 };
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            // check horizontal
            if (hashmap[board[i][j] - 48]++ > 0) {
                return false;
            }
            // check vertical
            if (hashmapvert[j][board[i][j] - 48]++ > 0) {
                return false;
            }
            // check boxes
            if (hashmapbox[i / 3][j / 3][board[i][j] - 48]++ > 0) {
                return false;
            }
        }
    }
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
