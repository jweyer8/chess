
//this does the exact same thing as inList.h however it takes the last two arguments of the user input string
//instead of the first two. these represent where on the board the user would like to move
//refere to inList.h for more documentation
char **inlist2(char input[5], char *board[8][8]){
    char c2;
    int r2;
    char **boardptr2;

    c2 = input[2];
    r2 = input[3] - '0';

    if(c2 == 'a'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][0];
                break;
            case 7:
                boardptr2 = &board[1][0];
                break;
            case 6:
                boardptr2 = &board[2][0];
                break;
            case 5:
                boardptr2 = &board[3][0];
                break;
            case 4:
                boardptr2 = &board[4][0];
                break;
            case 3:
                boardptr2 = &board[5][0];
                break;
            case 2:
                boardptr2 = &board[6][0];
                break;
            case 1:
                boardptr2 = &board[7][0];
                break;
        }
    }

    else if(c2 == 'b'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][1];
                break;
            case 7:
                boardptr2 = &board[1][1];
                break;
            case 6:
                boardptr2 = &board[2][1];
                break;
            case 5:
                boardptr2 = &board[3][1];
                break;
            case 4:
                boardptr2 = &board[4][1];
                break;
            case 3:
                boardptr2 = &board[5][1];
                break;
            case 2:
                boardptr2 = &board[6][1];
                break;
            case 1:
                boardptr2 = &board[7][1];
                break;
        }
    }

    else if(c2 == 'c'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][2];
                break;
            case 7:
                boardptr2 = &board[1][2];
                break;
            case 6:
                boardptr2 = &board[2][2];
                break;
            case 5:
                boardptr2 = &board[3][2];
                break;
            case 4:
                boardptr2 = &board[4][2];
                break;
            case 3:
                boardptr2 = &board[5][2];
                break;
            case 2:
                boardptr2 = &board[6][2];
                break;
            case 1:
                boardptr2 = &board[7][2];
                break;
        }
    }

  else if(c2 == 'd'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][3];
                break;
            case 7:
                boardptr2 = &board[1][3];
                break;
            case 6:
                boardptr2 = &board[2][3];
                break;
            case 5:
                boardptr2 = &board[3][3];
                break;
            case 4:
                boardptr2 = &board[4][3];
                break;
            case 3:
                boardptr2 = &board[5][3];
                break;
            case 2:
                boardptr2 = &board[6][3];
                break;
            case 1:
                boardptr2 = &board[7][3];
                break;
        }
    }

    else if(c2 == 'e'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][4];
                break;
            case 7:
                boardptr2 = &board[1][4];
                break;
            case 6:
                boardptr2 = &board[2][4];
                break;
            case 5:
                boardptr2 = &board[3][4];
                break;
            case 4:
                boardptr2 = &board[4][4];
                break;
            case 3:
                boardptr2 = &board[5][4];
                break;
            case 2:
                boardptr2 = &board[6][4];
                break;
            case 1:
                boardptr2 = &board[7][4];
                break;
        }
    }

    else if(c2 == 'f'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][5];
                break;
            case 7:
                boardptr2 = &board[1][5];
                break;
            case 6:
                boardptr2 = &board[2][5];
                break;
            case 5:
                boardptr2 = &board[3][5];
                break;
            case 4:
                boardptr2 = &board[4][5];
                break;
            case 3:
                boardptr2 = &board[5][5];
                break;
            case 2:
                boardptr2 = &board[6][5];
                break;
            case 1:
                boardptr2 = &board[7][5];
                break;
        }
    }

    else if(c2 == 'g'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][6];
                break;
            case 7:
                boardptr2 = &board[1][6];
                break;
            case 6:
                boardptr2 = &board[2][6];
                break;
            case 5:
                boardptr2 = &board[3][6];
                break;
            case 4:
                boardptr2 = &board[4][6];
                break;
            case 3:
                boardptr2 = &board[5][6];
                break;
            case 2:
                boardptr2 = &board[6][6];
                break;
            case 1:
                boardptr2 = &board[7][6];
                break;
        }
    }

    else if(c2 == 'h'){
        switch(r2){
            case 8:
                boardptr2 = &board[0][7];
                break;
            case 7:
                boardptr2 = &board[1][7];
                break;
            case 6:
                boardptr2 = &board[2][7];
                break;
            case 5:
                boardptr2 = &board[3][7];
                break;
            case 4:
                boardptr2 = &board[4][7];
                break;
            case 3:
                boardptr2 = &board[5][7];
                break;
            case 2:
                boardptr2 = &board[6][7];
                break;
            case 1:
                boardptr2 = &board[7][7];
                break;
        }
    }
    return boardptr2;
}