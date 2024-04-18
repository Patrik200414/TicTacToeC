#include <stdio.h>
#include <stdlib.h>

int main(){
    char board [3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    writeOutBoard(board);
    return 0;
}

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
