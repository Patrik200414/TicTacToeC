#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void writeOutBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                printf("|%c|", board[i][j]);
            } else{
                printf("%c|", board[i][j]);
            }
        }
        printf("\n");
    }
}

int isCharBetween(char c, char lower, char upper) {
    // both inclusive
    return c <= upper && c >= lower;
}

int parseCoordinates(char coordinates[2]) {
    return (coordinates[0] - 'a') * 3 + coordinates[1] - '1';
}

int validateCoordinates(char coordinates[2], char board[3][3]) {
    if (!isCharBetween(coordinates[0], 'a', 'c') || !isCharBetween(coordinates[1], '1', '3')) {
        return -1;
    } 
    
    int arrayIndex = parseCoordinates(coordinates);

    if(board[arrayIndex / 3][arrayIndex % 3] != ' '){
        return -2;
    }
    // TODO: check if square is free
    return arrayIndex;
}

int readUserInput(char board[3][3]) {
    char coordinates[2];
    int result;
    while (1) {
        printf("Please provide the coordinates of your next move! ");
        // space at the beginning is necessary, otherwise it will be fed by the line feed
        scanf(" %c%c", coordinates, coordinates + 1);
        result = validateCoordinates(coordinates, board);
        if (result == -1) {
            printf("Invalid coordinates! Valid coordinates range from a1 to c3\n");
        } else if (result == -2) {
            // TODO: use -2 for not empty square
            printf("Invalid coordinates! An element already exists in this square!\n");
        } else {
            return result;
        }
    }
}

void runGame(char board[3][3]){
    bool isGameFinished = false;
    bool isXTurn = true; 

     while (!isGameFinished)
     {
        writeOutBoard(board);
        int input = readUserInput(board);
        if(isXTurn){
            board[input / 3][input % 3] = 'x';
            isXTurn = false;
        } else{
            board[input / 3][input % 3] = 'o';
            isXTurn = true;
        }
     }
     
}

int main(){
    char board [3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    runGame(board);

    writeOutBoard(board);
    /* // some code for testing the new functionality
    int input = readUserInput(board);
    board[input / 3][input % 3] = 'x';
    writeOutBoard(board);
    char* c = board;
    input = readUserInput(board);
    *(c + input) = 'x';
    writeOutBoard(board); */
    return 0;
}