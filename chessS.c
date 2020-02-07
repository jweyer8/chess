
#include <stdio.h>
int main(){
char *board[8][8];


char pawn = 'p';
char rook = 'r';
char bishop = 'b';
char knight = 'n';
char king = 'k';
char queen = 'q';
char space = ' ';

char *white[16];
char *black[16];

for(int i=0; i<8; i++){
    printf("\n");
    for(int j=0; j<8; j++){
        printf("[ ]");
    }
}

return 0;
}



