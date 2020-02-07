//////////////////////////////////////////////////////////////////////////
// By: Jared Weyer                                                      //
//                                                                      //
// for my project I tryed to create a platform that will alow two       //
// people to play chess aginst eachother I was unable to finish         //
// all the code for what moves each piece can undertake which           //
// is all under the header file chessM.h                                //
//                                                                      //
// IMPLEMENTED TOPICS:                                                  //
// string -> line: main 368                                            //
// 2d array -> line: main 194                                          //
// file I/O -> line: main 650 function createfile                       //
// command line arguments -> line: 109                                  //
// pass by refernce -> I pass arrays into alot of the functions         // 
// structures -> line: chessM.h 7                                       //
// Linked Lists -> line: main 500 function inputVal                     //
// sorting -> don't really have this implemented                        //
// stack/queue -> line: main 518 function inputVal
// custom header file -> chessM.h inList.h inList2.h        
//                                                                      //
// in the begining of the program I include three local header files    //
// chessM.h inludes the logic that describes valid moves input by users //
// inList.h takes the first two arguments that the user inputs as a     //
// string and attaches that input to one of the 64 memory address       //
// atached to the 8 by 8 board. this first input represents the place   //
// on the board with the piece you want to move.                        //
// inList2.h takes the last two arguments from user input. this input   //
// should tell which spot on the board the user wants to move and the   //
// file should attach this spot with the memory address on the board    //
//                                                                      //
// I then define some terminal emulator esape sequences that correspond //
// with differnt color text in the terminal. the user can choose his    //
// prefered colors with comand line arguments                           //
//                                                                      //
// I then have some functions that inlude a game start display and      //
// an option to see the  directions on how to use the program           //
//                                                                      //
// fucntion validMove describes what to do when a given move is valid   //
//                                                                      //
// function inputVal does some initial input checking it also uses      //
// a linked list which conains the user input and uses a lifo analysis  //
// to validate the input (hopefully you can count this as my req for    //
// using a stack data stucture)                                         //
//                                                                      //
// function playerpiece validates that the requested piece to be moved  //
// acutally belong to that player                                       //
//                                                                      //
// function player finds which player a piece belongs to                //
//                                                                      //
// function getcolor changes the terminal emulator txt color based on   //
// who a piece belongs to                                               //
//                                                                      //
// function createfile creates a file and inputs the users names so that//
// they can be accessed later in the program                            //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chessM.h"
#include "inList.h"
#include "inList2.h"


#define CR "\x1b[31;1m"
#define CG "\x1b[32;1m"
#define CY "\x1b[33;1m"
#define CB "\x1b[34;1m"
#define CM "\x1b[35;1m"
#define CC "\x1b[36;1m"
#define CW "\x1b[37;1m"
#define BC1 "\x1b[48;5;251m"
#define BC2 "\x1b[48;5;236m"
#define CRESET "\x1b[0m"

int display();
void directions();
int inputVal(char input[5]);
void getcolor(int i,int pcolor2, int pcolor);
int player(char *white[16],char *black[16],char *boardspace);
int playerpiece(char **newboardptr,char *white[16], char *black[16]);
void createfile();

void validMove(char input[5], char *board[8][8],char *white[17], char *black[17], char **newboardptr, char **newboardptr2){
   char *tmp;

   //find space on board that the pointer referers to (this is the space that refers piece that the user wants to move). then make this space point to a blank
   for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
         if((void*)&board[i][j] == (void*)newboardptr){
            tmp = *newboardptr;
            board[i][j] = white[16];
         }
      }
   }

   //find the space of the board where the user wants to move to and make this space point to the piece character refered to by the previous pointer
   for(int a=0; a<8; a++){
      for(int b=0; b<8; b++){
         if((void*)&board[a][b] == (void*)newboardptr2){
            board[a][b] = tmp;
         }
      }
   }

return;
}

int main(int argc, char const *argv[]){
   if(argc !=3){
        printf("Usage: %s color1 color2\n",argv[0]);
        printf("color options:\n");
        printf("for RED enter r \n");
        printf("for GREEN enter g\n");
        printf("for YELLOW enter y\n");
        printf("for BLUE enter b\n");
        printf("for MAGENTA enter m\n");
        printf("for CYAN enter c\n");
        exit(EXIT_FAILURE);
   }
   else{

   int pcolor1;
   int pcolor2;
   int get;
   //display start game 
   get = display();

   //open and write to a file that stores the names of the players
   FILE *fptr = NULL;
   char name1[10];
   char name2[10];
   createfile();
   fptr = fopen("names.txt","r");
   if(fptr == NULL){
      exit(EXIT_SUCCESS);
   }
   else{
      fscanf(fptr, "%s", name1);
      fscanf(fptr, "%s", name2);
      fclose(fptr);
      remove("names.txt");
   }

   
   if(*argv[1] == 'r'){
      pcolor1 = 1;
   }
   else if(*argv[1] == 'g'){
      pcolor1 = 2;
   }
   else if(*argv[1] == 'y'){
      pcolor1 = 3;
   }
   else if(*argv[1] == 'b'){
      pcolor1 = 4;
   }
   else if(*argv[1] == 'm'){
      pcolor1 = 5;
   }
   else if(*argv[1] == 'c'){
      pcolor1 = 6;
   }
   else{
      pcolor1 = 0;
   }


   //tell play player two what color they are
   if(*argv[2] == 'r'){
      pcolor2 = 1;
   }
   else if(*argv[2] == 'g'){
      pcolor2 = 2;
   }
   else if(*argv[2] == 'y'){
      pcolor2 = 3;
   }
   else if(*argv[2] == 'b'){
      pcolor2 = 4;
   }
   else if(*argv[2] == 'm'){
      pcolor2 = 5;
   }
   else if(*argv[2] == 'c'){
      pcolor2 = 6;
   }
   else{
      pcolor2 = 0;
   }


   // create 2d array of char pointer which will point to the chars associated with differnt pieces
   char *board[8][8];
   char junk[50];

   //white pieces
   char rook1w = 'r';
   char rook2w = 'r';
   char bishop1w = 'b';
   char bishop2w = 'b';
   char knight1w = 'n';
   char knight2w = 'n';
   char kingw = 'k';
   char queenw = 'q';
   char pawn1w = 'p';
   char pawn2w = 'p';
   char pawn3w = 'p';
   char pawn4w = 'p';
   char pawn5w = 'p';
   char pawn6w = 'p';
   char pawn7w = 'p';
   char pawn8w = 'p';
   char space = ' ';

   // array of player twos pieces 
   char *white[17] = {&rook1w,&knight1w,&bishop1w,&queenw,&kingw,&bishop2w,&knight2w,&rook2w,&pawn1w,&pawn2w,&pawn3w,&pawn4w,&pawn5w,&pawn6w,&pawn7w,&pawn8w,&space};

   //black pieces
   char rook1b = 'r';
   char rook2b = 'r';
   char bishop1b = 'b';
   char bishop2b = 'b';
   char knight1b = 'n';
   char knight2b = 'n';
   char kingb = 'k';
   char queenb = 'q';
   char pawn1b = 'p';
   char pawn2b = 'p';
   char pawn3b = 'p';
   char pawn4b = 'p';
   char pawn5b = 'p';
   char pawn6b = 'p';
   char pawn7b = 'p';
   char pawn8b = 'p';

   //array of player ones pieces
   char *black[17] = {&rook1b,&knight1b,&bishop1b,&queenb,&kingb,&bishop2b,&knight2b,&rook2b,&pawn1b,&pawn2b,&pawn3b,&pawn4b,&pawn5b,&pawn6b,&pawn7b,&pawn8b,&space};



   //display directions if user wants
   if(get == 2){
      directions();
      get = display();
   }
   printf("\x1b[2J");
   printf("\x1b[f");
   //printf("\x1b[8;15;30t");

      //displaying board to user and initializing the initial board array
      int count = 8;

      printf("\n");
      printf("    a ");
      printf(" b ");
      printf(" c ");
      printf(" d ");
      printf(" e ");
      printf(" f ");
      printf(" g ");
      printf(" h ");
      printf("\n");

      for(int i= 0; i<8; i++){
         printf(CRESET);
         printf("\n");
         printf("%i  ", count);
         for(int j=0; j<8; j++){
            if(i == 0){
               board[i][j] = black[j];
            }
            else if(i == 1){
               board[i][j] = black[j + 8];
            }
            else if(i == 6){
               board[i][j] = white[j + 8];
            }
            else if(i == 7){
               board[i][j] = white[j];
            }
            else{
               board[i][j] = white[16];
            }

            if(i % 2 == 0 && j % 2 == 0){
               printf(BC1);
            }
            else{
               printf(BC2);
            }
            if( i % 2 != 0 && j % 2 != 0){
               printf(BC1);
            }

            printf(" ");
            if(i<4){
               getcolor(1,pcolor2,pcolor1);
            }
            else{
               getcolor(2,pcolor2,pcolor1);
            }
            printf("%c",*board[i][j]);
            printf(" ");
            printf(CRESET);
         }
         count--;
      }
      printf("\n");  
      printf("\n");
     

   int first = 0;
   while(get == 1){
      //displayng board to user
      count = 8;
      if(first != 0){

         printf("\n");
         printf("    a ");
         printf(" b ");
         printf(" c ");
         printf(" d ");
         printf(" e ");
         printf(" f ");
         printf(" g ");
         printf(" h ");
         printf("\n");

         int p;
         for(int t= 0; t<8; t++){
            printf(CRESET);
            printf("\n");
            printf("%i  ", count);
            for(int u =0; u<8; u++){
               p = player(white,black,board[t][u]);

               if(t % 2 == 0 && u % 2 == 0){
                  printf(BC1);
               }
               else{
                  printf(BC2);
               }
               if( t % 2 != 0 && u % 2 != 0){
                  printf(BC1);
               }

               printf(" ");
               if(p == 1){
                  getcolor(1,pcolor2,pcolor1);
               }
               if(p == 2){
                  getcolor(2,pcolor2,pcolor1);
               }
               printf("%c",*board[t][u]);
               printf(" ");
               printf(CRESET);
            }
            count--;
         }
         printf("\n");  
         printf("\n");
      }
      first++;

      //double pointer which points to a board adress which holds a pointer to a char
      char **newboardptr;
      char **newboardptr2;

      //char array to get input
      char input[5];
      int valid = 1;
      int w;
      if(first%2 == 0){
         getcolor(2,pcolor2,pcolor1);
         printf("%s's ", name2);
         printf(CRESET);
         printf("move:\n");
         w = 2;
      }
      else{
         getcolor(1,pcolor2,pcolor1);
         printf("%s's ", name1);
         printf(CRESET);
         printf("move:\n");
         w = 1;
      }

      //clear io stream
      fflush(stdin);

      //scan for user input/ what and where he wants to move
      scanf("%s",input);

      if(strlen(input) != 4){
         valid = -1;
      }

      //intitial input validity test
      if(valid != -1){
         valid = inputVal(input);
      }

      //transform user input of column and row to an actually pointer to board memory
      if(valid != -1){
         newboardptr = inlist(input, board);
         newboardptr2 = inlist2(input, board);

         //check that it is the players piece
         int pp;
         pp = playerpiece(newboardptr,white,black);
         if(pp == 1 && w == 2){
            valid = 2;
         }
         if(pp == 2 && w == 1){
            valid = 2;
         }
      }

      if(valid != 2 && valid !=-1){
         //check to see if this move is valid
         valid = moves(newboardptr, newboardptr2,board,w, black, white);
      }
    
      //based on validity of move display/do what is needed
      switch(valid){
         case 1:
            validMove(input,board,white,black,newboardptr,newboardptr2);
            break;
         case 0:
            printf("\nThis is an invalid move\n");
            printf("Try again\n");
            first--;
            break;
         case -1:
            printf("\nInvalid move entry\n");
            printf("Try again\n");
            first--;
            break;
         case 2:
            printf("\nThis is not your piece\n");
            printf("Try again\n");
            first--;
            break;
      }
   }
   }
   return 0;
}

//function for dispaying start game
int display(){
   int get = 0;
   char junk[50];
   while(get == 0){
      printf("+-------------------------------+\n");
      printf("|            *CHESS*            |\n");
      printf("|                               |\n");
      printf("|       press one to play       |\n");
      printf("|                               |\n");
      printf("|  press two to get directions  |\n");
      printf("|                               |\n");
      printf("+-------------------------------+\n");
      scanf("%i",&get);
      if(get == 1 || get == 2 ){
        return get;
      }
      else{
          printf("invalid input\n");
          printf("Try agin:\n");
          get = 0;
          scanf("%s",junk);
      }
   }
}

//function for displaying directions
void directions(){
   printf("\n");
   printf("+-------------------------------+\n");
   printf("|           DIRECTIONS          |\n");
   printf("+-------------------------------+\n");
   printf("|         Piece Symbols         |\n");
   printf("|                               |\n");
   printf("| - rook = r                    |\n");
   printf("| - knight = n                  |\n");
   printf("| - bishop = b                  |\n");
   printf("| - king = k                    |\n");
   printf("| - queen = q                   |\n");
   printf("| - pawn = p                    |\n");
   printf("|                               |\n");
   printf("+-------------------------------+\n");
   printf("|            Moving             |\n");
   printf("|                               |\n");
   printf("| *Enter the coordinates of     |\n");
   printf("|  the piece you would like to  |\n");
   printf("|  move followed by the         |\n");
   printf("|  coordinate of the postion    |\n");
   printf("|  you want to move to          |\n");
   printf("|                               |\n");
   printf("+-------------------------------+\n");
   printf("|        Moving Example         |\n");
   printf("|                               |\n");
   printf("| *Enter  a7a6                  |\n");
   printf("|                               |\n");
   printf("| *This will move the pawn at   |\n");
   printf("|  a7 to a6                     |\n");
   printf("|                               |\n");
   printf("+-------------------------------+\n");
   return;
}

//function for initial check of input validity 
int inputVal(char input[5]){
   int valid = 1;

   struct Node
   {
      char data;
      struct Node *next;
   };
   typedef struct Node node;


   //turn string into a linked list
   node *front = NULL;
   node *tmp = NULL;

   for(int i=0; i<strlen(input); i++){
      node *new = malloc(sizeof(node));
      new->data = input[i];
      new->next = NULL;
      if(front == NULL){
         front = tmp = new;
      }
      else{
         tmp->next = new;
         tmp = new;
      }
   }

//look at data in linked list in LIFO fashion or stack
tmp = front;
for(int j=0; j<strlen(input); j++){
   switch(j){
      case 0:
         if(tmp->data == 'a' || tmp->data == 'b' ||tmp->data == 'c' ||tmp->data == 'd' ||tmp->data == 'e' ||tmp->data == 'f' || tmp->data == 'g' ||tmp->data == 'h'){
            break;
         }
         else{
            return -1;
         }
      case 1:
         if(tmp->data == '1' ||tmp->data == '2' ||tmp->data == '3' ||tmp->data == '4' ||tmp->data == '5' || tmp->data == '6' ||tmp->data == '7' || tmp->data == '8'){
            break;
         }
         else{
            return -1;
         }
      case 2:
         if(tmp->data == 'a' || tmp->data == 'b' ||tmp->data == 'c' ||tmp->data == 'd' ||tmp->data == 'e' ||tmp->data == 'f' || tmp->data == 'g' ||tmp->data == 'h'){
             break;
         }
         else{
            return -1;
         }
      case 3:
         if(tmp->data == '1' ||tmp->data == '2' ||tmp->data == '3' ||tmp->data == '4' ||tmp->data == '5' || tmp->data == '6' ||tmp->data == '7' || tmp->data == '8'){
             break;
         }
         else{
            return -1;
         }
   }
   tmp = tmp->next;
}
return valid;
}


//fucntion for getting player color
void getcolor(int i, int pcolor2, int pcolor1){

   if(i ==1){
      switch(pcolor1){
               case 0:
                  printf(CW);
                  break;
               case 1:
                  printf(CR);
                  break;
               case 2:
                  printf(CG);
                  break;
               case 3:
                  printf(CY);
                  break;
               case 4:
                  printf(CB);
                  break;
               case 5:
                  printf(CM);
                  break;
               case 6:
                  printf(CC);
                  break;
            }

   }
   else if(i == 2){
      switch(pcolor2){
                  case 0:
                     printf(CW);
                     break;
                  case 1:
                     printf(CR);
                     break;
                  case 2:
                     printf(CG);
                     break;
                  case 3:
                     printf(CY);
                     break;
                  case 4:
                     printf(CB);
                     break;
                  case 5:
                     printf(CM);
                     break;
                  case 6:
                     printf(CC);
                     break;
               }

   }
   return;
}

//function for determining what what player owns a certain piece
int player(char *white[16],char *black[16],char *boardspace){
   int p;
   //black == player 1
   //white == player 2 
   for(int k=0; k<16; k++){
      if(boardspace == white[k]){
         p = 2;
      }
      if(boardspace == black[k]){
         p = 1;
      }
   }

   return p;
}

int playerpiece(char **newboardptr,char *white[16], char *black[16]){
   int pp;
   for(int k=0; k<16; k++){
      if((int*)*newboardptr == (int*)black[k]){
         pp = 1;
      }
      if((int*)*newboardptr == (int*)white[k]){
         pp = 2;
      }
   }

return pp;
}

//function that creates a file to store user names
void createfile(){
   char name1[100];
   char name2[100];

   FILE *fptr = NULL;
   int check = 0;


   printf("Enter your user name player one:\n");
   scanf("%s", name1);

   printf("Enter your user name player two:\n");
   scanf("%s", name2);
   

   fptr = fopen("names.txt","w");
   if(fptr == NULL){
      printf("File could not be opened\n");
      exit(EXIT_SUCCESS);
   }
   else{
      fprintf(fptr, "%s", name1);
      fprintf(fptr,"\n");
      fprintf(fptr, "%s", name2);
   }
   fclose(fptr);

   return;
}
