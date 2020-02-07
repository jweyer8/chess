//get string input which refers to a column and row and turn this into a double pointer which can be used later in program
char **inlist(char input[5], char *board[8][8]){
    //requested column 
    char c1;
    //requested row
    int r1;
    char **boardptr;
    
    c1 = input[0];

    //turn char to int
    r1 = input[1] - '0';


    //find what space(of the 64 possible) that the user is refering to... there is probably a much beter way to do this
    if(c1 == 'a'){
        switch(r1){
            case 8:
                boardptr = &board[0][0];
                break;
            case 7:
                boardptr = &board[1][0];
                break;
            case 6:
                boardptr = &board[2][0];
                break;
            case 5:
                boardptr = &board[3][0];
                break;
            case 4:
                boardptr = &board[4][0];
                break;
            case 3:
                boardptr = &board[5][0];
                break;
            case 2:
                boardptr = &board[6][0];
                break;
            case 1:
                boardptr = &board[7][0];
                break;
        }
    }

    else if(c1 == 'b'){
        switch(r1){
            case 8:
                boardptr = &board[0][1];
                break;
            case 7:
                boardptr = &board[1][1];
                break;
            case 6:
                boardptr = &board[2][1];
                break;
            case 5:
                boardptr = &board[3][1];
                break;
            case 4:
                boardptr = &board[4][1];
                break;
            case 3:
                boardptr = &board[5][1];
                break;
            case 2:
                boardptr = &board[6][1];
                break;
            case 1:
                boardptr = &board[7][1];
                break;
        }
    }

    else if(c1 == 'c'){
        switch(r1){
            case 8:
                boardptr = &board[0][2];
                break;
            case 7:
                boardptr = &board[1][2];
                break;
            case 6:
                boardptr = &board[2][2];
                break;
            case 5:
                boardptr = &board[3][2];
                break;
            case 4:
                boardptr = &board[4][2];
                break;
            case 3:
                boardptr = &board[5][2];
                break;
            case 2:
                boardptr = &board[6][2];
                break;
            case 1:
                boardptr = &board[7][2];
                break;
        }
    }

  else if(c1 == 'd'){
        switch(r1){
            case 8:
                boardptr = &board[0][3];
                break;
            case 7:
                boardptr = &board[1][3];
                break;
            case 6:
                boardptr = &board[2][3];
                break;
            case 5:
                boardptr = &board[3][3];
                break;
            case 4:
                boardptr = &board[4][3];
                break;
            case 3:
                boardptr = &board[5][3];
                break;
            case 2:
                boardptr = &board[6][3];
                break;
            case 1:
                boardptr = &board[7][3];
                break;
        }
    }

    else if(c1 == 'e'){
        switch(r1){
            case 8:
                boardptr = &board[0][4];
                break;
            case 7:
                boardptr = &board[1][4];
                break;
            case 6:
                boardptr = &board[2][4];
                break;
            case 5:
                boardptr = &board[3][4];
                break;
            case 4:
                boardptr = &board[4][4];
                break;
            case 3:
                boardptr = &board[5][4];
                break;
            case 2:
                boardptr = &board[6][4];
                break;
            case 1:
                boardptr = &board[7][4];
                break;
        }
    }

    else if(c1 == 'f'){
        switch(r1){
            case 8:
                boardptr = &board[0][5];
                break;
            case 7:
                boardptr = &board[1][5];
                break;
            case 6:
                boardptr = &board[2][5];
                break;
            case 5:
                boardptr = &board[3][5];
                break;
            case 4:
                boardptr = &board[4][5];
                break;
            case 3:
                boardptr = &board[5][5];
                break;
            case 2:
                boardptr = &board[6][5];
                break;
            case 1:
                boardptr = &board[7][5];
                break;
        }
    }

    else if(c1 == 'g'){
        switch(r1){
            case 8:
                boardptr = &board[0][6];
                break;
            case 7:
                boardptr = &board[1][6];
                break;
            case 6:
                boardptr = &board[2][6];
                break;
            case 5:
                boardptr = &board[3][6];
                break;
            case 4:
                boardptr = &board[4][6];
                break;
            case 3:
                boardptr = &board[5][6];
                break;
            case 2:
                boardptr = &board[6][6];
                break;
            case 1:
                boardptr = &board[7][6];
                break;
        }
    }

    else if(c1 == 'h'){
        switch(r1){
            case 8:
                boardptr = &board[0][7];
                break;
            case 7:
                boardptr = &board[1][7];
                break;
            case 6:
                boardptr = &board[2][7];
                break;
            case 5:
                boardptr = &board[3][7];
                break;
            case 4:
                boardptr = &board[4][7];
                break;
            case 3:
                boardptr = &board[5][7];
                break;
            case 2:
                boardptr = &board[6][7];
                break;
            case 1:
                boardptr = &board[7][7];
                break;
        }
    }

return boardptr;
}
