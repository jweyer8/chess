#include <stdio.h>

int invalidKing(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]);

//typedef funtion which will have the same input and output for every differnt associated piece
typedef int (*move)(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]);

//create struct which include a function and its validity
struct Pmoves{
    move m;
    int valid;
};
typedef struct Pmoves pmoves;

//create valid moves for pawn
int pawnMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int moveNum;
    char **tmp = NULL;
    tmp = newboardptr;

    if(w == 1){
         tmp = (tmp) + 8 * (sizeof(char));
    }
    if(w == 2){
        tmp = tmp - 8 * (sizeof(char));
    }

    char tmpchar = **tmp;
    moveNum = newboardptr - newboardptr2;
    
    if(w == 1){
        moveNum *= -1;
    }

    for(int j=0; j<8; j++){
        if((int*)board[1][j] == (int*)*newboardptr && moveNum == 16 && **newboardptr2 == ' ' && tmpchar == ' '){
            v = 1;
        }
        if((int*)board[6][j] == (int*)*newboardptr && moveNum == 16 && **newboardptr2 == ' ' && tmpchar == ' '){
            v = 1;
        }
    }

    if(moveNum == 8 && **newboardptr2 == ' '){
        v = 1;
    }

    if(moveNum == 7 && **newboardptr2 != ' '){
        for(int i=0; i<16; i++){
            if((int*)white[i] == (int*)*newboardptr2){
                *white[i] = ' ';
            }
            if((int*)black[i] == (int*)*newboardptr2){
                *black[i] = ' ';
            }
        }
        v = 1;
    }

    if(moveNum == 9 && **newboardptr2 != ' '){
        v = 1;
    }

return v;       
}

//create valid moves for rook
int rookMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int pos = 0;
    int moveNum;
    char **tmp = NULL;
    tmp = newboardptr;

    moveNum = newboardptr - newboardptr2;

    if(w == 1){
        moveNum *= -1;
        pos = 1;
    }

    if(moveNum % 8 == 0){
        v = 1;
        for(int i=1; i<(moveNum/8); i++){
            if(pos == 1){
                tmp = (tmp) + (i*8) * sizeof(char);
                if(**tmp != ' '){
                    v = 0;
                }
            }
            else{
                tmp = (tmp) - (i*8) * sizeof(char);
                if(**tmp != ' '){
                    v = 0;
                }
            }
        tmp = newboardptr;
        }
    }

    tmp = newboardptr;

    if(moveNum < 8 && moveNum > -8){
        v = 1;
        for(int j=1;j<moveNum; j++){
            if(pos == 1){
                tmp = (tmp) + j * (sizeof(char));
                if(**tmp != ' '){
                    v = 0;
                }
            }
            else{
                tmp = (tmp) - j * (sizeof(char));
                 if(**tmp != ' '){
                    v = 0;
                }
            }
        tmp = newboardptr;
        }
    } 

    for(int k=0; k<16; k++){
            if((int*)white[k] == (int*)*newboardptr2 && w == 2 && *white[k] != ' '){
                v = 0;
            }
            if((int*)black[k] == (int*)*newboardptr2 && w == 1 && *black[k] != ' '){
                v = 0;
            }
        }

return v;     
}

//create valid moves for bishop
int bishopMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int nrow,nrow2,ncol,ncol2,rowdif,coldif,colneg, rowneg;
    colneg = 1;
    rowneg = 1;
  
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(&board[i][j] == newboardptr){
                nrow = i;
                ncol = j;
            }
            if(&board[i][j] == newboardptr2){
                nrow2 = i;
                ncol2 = j;
            }
        }
    }

    rowdif = nrow - nrow2;
    coldif = ncol - ncol2;

    if(rowdif < 0){
        rowdif *= -1;
        rowneg = 0;
    }
    if(coldif < 0){
        coldif *= -1;
        colneg = 0;
    }

    if(rowdif - coldif == 0){
        v = 1;
        for(int k=1; k<rowdif; k++){
            if(colneg == 1 && rowneg == 1){
                if(*board[nrow2 + k][ncol2 + k] != ' '){
                    v = 0;
                }
            }
            else if (colneg == 1 && rowneg == 0){
                 if(*board[nrow2 - k][ncol2 + k] != ' '){
                    v = 0;
                }
            }
            else if (colneg == 0 && rowneg == 0){
                 if(*board[nrow2 - k][ncol2 - k] != ' '){
                    v = 0;
                }
            }
            else{
                 if(*board[nrow2 + k][ncol2 - k] != ' '){
                    v = 0;
                }
            }
        }
    }

    for(int l=0; l<16; l++){
        if((int*)white[l] == (int*)*newboardptr2 && w == 2 && *white[l] != ' '){
            v = 0;
        }
        if((int*)black[l] == (int*)*newboardptr2 && w == 1 && *black[l] != ' '){
            v = 0;
        }
    }


return v;       
}
//create valid moves for knight
int knightMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int moveNum;

    moveNum = newboardptr - newboardptr2;

    if(moveNum == 17 || moveNum == 15 || moveNum == -15 || moveNum == -17){
        v = 1;
    }
    if(moveNum == 10 || moveNum == 6 || moveNum == -6 || moveNum == -10){
        v = 1;
    }

     for(int l=0; l<16; l++){
        if((int*)white[l] == (int*)*newboardptr2 && w == 2 && *white[l] != ' '){
            v = 0;
        }
        if((int*)black[l] == (int*)*newboardptr2 && w == 1 && *black[l] != ' '){
            v = 0;
        }
    }
    
return v;       
}
//create valid moves for king
int kingMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int moveNum;
    int pm;

    moveNum = newboardptr - newboardptr2;
    pm = moveNum % 8;

    if(moveNum == 1 || moveNum == -1 || moveNum == 9 || moveNum == -9 || moveNum == 7 || moveNum == -7 ){
        v = 1;
    }
    if(pm == 0){
        v = 1;
    }

     for(int l=0; l<16; l++){
        if((int*)white[l] == (int*)*newboardptr2 && w == 2 && *white[l] != ' '){
            v = 0;
        }
        if((int*)black[l] == (int*)*newboardptr2 && w == 1 && *black[l] != ' '){
            v = 0;
        }
    }

return v;       
}
//create vaild moves for queen
int queenMove(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    int v = 0;
    int pos = 0;
    int moveNum;
    char **tmp = NULL;
    tmp = newboardptr;

    moveNum = newboardptr - newboardptr2;

    if(w == 1){
        moveNum *= -1;
        pos = 1;
    }

    if(moveNum % 8 == 0){
        v = 1;
        for(int a=1; a<(moveNum/8); a++){
            if(pos == 1){
                tmp = (tmp) + (a*8) * sizeof(char);
                if(**tmp != ' '){
                    v = 0;
                }
            }
            else{
                tmp = (tmp) - (a*8) * sizeof(char);
                if(**tmp != ' '){
                    v = 0;
                }
            }
        tmp = newboardptr;
        }
    }

    tmp = newboardptr;

    if(moveNum < 8 && moveNum > -8){
        v = 1;
        for(int b=1;b<moveNum; b++){
            if(pos == 1){
                tmp = (tmp) + b * (sizeof(char));
                if(**tmp != ' '){
                    v = 0;
                }
            }
            else{
                tmp = (tmp) - b * (sizeof(char));
                 if(**tmp != ' '){
                    v = 0;
                }
            }
        tmp = newboardptr;
        }
    } 

    for(int c=0; c<16; c++){
            if((int*)white[c] == (int*)*newboardptr2 && w == 2 && *white[c] != ' '){
                v = 0;
            }
            if((int*)black[c] == (int*)*newboardptr2 && w == 1 && *black[c] != ' '){
                v = 0;
            }
        }


    //enable move diagnol
    int nrow,nrow2,ncol,ncol2,rowdif,coldif,colneg, rowneg;
    colneg = 1;
    rowneg = 1;
  
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(&board[i][j] == newboardptr){
                nrow = i;
                ncol = j;
            }
            if(&board[i][j] == newboardptr2){
                nrow2 = i;
                ncol2 = j;
            }
        }
    }

    rowdif = nrow - nrow2;
    coldif = ncol - ncol2;

    if(rowdif < 0){
        rowdif *= -1;
        rowneg = 0;
    }
    if(coldif < 0){
        coldif *= -1;
        colneg = 0;
    }

    if(rowdif - coldif == 0){
        v = 1;
        for(int k=1; k<rowdif; k++){
            if(colneg == 1 && rowneg == 1){
                if(*board[nrow2 + k][ncol2 + k] != ' '){
                    v = 0;
                }
            }
            else if (colneg == 1 && rowneg == 0){
                 if(*board[nrow2 - k][ncol2 + k] != ' '){
                    v = 0;
                }
            }
            else if (colneg == 0 && rowneg == 0){
                 if(*board[nrow2 - k][ncol2 - k] != ' '){
                    v = 0;
                }
            }
            else{
                 if(*board[nrow2 + k][ncol2 - k] != ' '){
                    v = 0;
                }
            }
        }
    }

    for(int l=0; l<16; l++){
        if((int*)white[l] == (int*)*newboardptr2 && w == 2 && *white[l] != ' '){
            v = 0;
        }
        if((int*)black[l] == (int*)*newboardptr2 && w == 1 && *black[l] != ' '){
            v = 0;
        }
    }
    

return v;       
}

 int moves(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){
    //dereferce douple pointer in order to see what char/piece it points to
    char rp = **newboardptr;

    //define instances of struct for differnt picies
    pmoves p;
    p.m = pawnMove;
    pmoves r;
    r.m = rookMove;
    pmoves b;
    b.m = bishopMove;
    pmoves n;
    n.m = knightMove;
    pmoves k;
    k.m = kingMove;
    pmoves q;
    q.m = queenMove;



    //call different functions based off derefernced db ptr
    if(rp == 'p'){
        p.valid = p.m(newboardptr, newboardptr2, board, w, black, white);
        return p.valid;
    }

    else if(rp == 'r'){
        r.valid = r.m(newboardptr, newboardptr2, board, w, black, white);
        return r.valid;
    }

    else if(rp == 'b'){
        b.valid = b.m(newboardptr, newboardptr2, board, w, black, white);
        return b.valid;
    }

    else if(rp == 'n'){
        n.valid = n.m(newboardptr, newboardptr2, board, w, black, white);
        return n.valid;
    }

    else if(rp == 'k'){
        k.valid = k.m(newboardptr, newboardptr2, board, w, black, white);
        return k.valid;
    }

    else if(rp == 'q'){
        q.valid = q.m(newboardptr, newboardptr2, board, w, black, white);
        return q.valid;
    }

    return -1;
}

//Function for checking whether the move exposes the king for kill
int invalidKing(char **newboardptr, char **newboardptr2, char *board[8][8], int w, char *black[16], char *white[16]){


}