#include <stdio.h>
#include "FourInRow.h"
#define ROW 6
#define COL 7

#define true 1
#define false 0



void main() {
    
    
    
    char mat[ROW][COL]; 
    
    //Matrix initialization
    
    for(int i=0; i<ROW; i++){
        
        for(int j=0; j<COL; j++){
            
            mat[i][j] = ' ';
            
        }
        
    }
    
    
  playGame(mat);
}

void printBoard(char a[ROW][COL]){
    //Matrix printed
    
    
     for(int i=0; i<6; i++){
        
        for(int j=0; j<7; j++){
            
            if(j==0){
                printf("|");
            }
            
            if(a[i][j] == 'X' || a[i][j]=='O'){
                printf("%c",a[i][j]);
            }
            else{
                printf(" ");
            }
            
                printf("|");

        }
        
        printf("\n");
        
    }
    printf(" 1 2 3 4 5 6 7\n");
    
}

int checkWin(char a[ROW][COL], int row, int col, char y){
    
    //this function chack if there are 4 similar signs(O/X) in sequence
    
    int h=-1;
    int v=-1;
    int d=-1;
    
    
    //check row
    h = checkHor(a,row,col,y);
    
    //check column
    v = checkVer(a,row,col,y);
    
    //check diagonal
    d = checkDiag(a,row,col,y);
    
    
    if(h==1 || v==1 || d==1){
        //if one of the variables equal to '1' so one of the players win.
        
        return 1;
    }
    else{
        //else the function check if there is a draw.
        //the function count the number of full columns
        //if "tie"==7 so all the board is full, and the game ended in draw
        
        
        int tie = 0;
        
        for(int j=0; j<7; j++){
            
            //checl if the column is full
            if(a[0][j]=='X' || a[0][j]=='O'){
              tie++;  
            }
            
        }
        
        
        if(tie==7){
            return tie;
        }
        
        return 0;
    }
    
}

int checkHor(char a[ROW][COL], int row, int col, char y){
    
    //this function check if there 4 in row
    

    int counter = 0;
    
    for(int j=0; j<7; j++){

        if(a[row][j] == y){
            counter++;
            if(counter==4){
                return 1;
            }
        }
        else{
            if(counter>0){
                counter = 0;
            }
        }
        
        
    }
            return 0;
}

int checkVer(char a[ROW][COL], int row, int col, char y){
    
    //this function check if there 4 in column

    
    int counter = 0;
    
    for(int i=row; i<row+4; i++){
        
        if(a[i][col]==y){
            counter++;
        }
        
    }
    
    if(counter==4){
        return 1;
    }
    else{
        return 0;
    }
    
    
}

int checkDiag(char a[ROW][COL], int row, int col, char y){
    
        //this function check if there 4 in diagonal

    
    int counter = 1;
    
    for(int i=row-1,j=col+1;i>=0 && j<7;i--,j++) {
        
        //this loop count the num of the similar signs up and right from the point
        
            if(a[i][j]!=y){
                break;
            }
            counter++;
        }
        
    for(int i=row+1,j=col-1;i<6 && j>=0;i++,j--) {
        
        //this loop count the num of the similar signs down and left from the point

            if(a[i][j]!=y)
                break;
            counter++;
        }
        
        if(counter>=4){
            return 1;
        }
        
        counter = 1;
    
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) {
        
        //this loop count the num of the similar signs up and left from the point

        
            if(a[i][j]!=y){
                break;
            }
            counter++;
        }
        
    for(int i=row+1,j=col+1;i<6 && j<7;i++,j++) {
        
        //this loop count the num of the similar signs down and right from the point

            if(a[i][j]!=y)
                break;
            counter++;
        }
        
        if(counter>=4){
            return 1;
        }
        
    return 0;
    
    
}


void playGame(char a[ROW][COL]){
    
    
    //this array keeps in every place the last column, in lastCol[lastCounter]
    int lastCol[43];
    //index of lastCol
    int lastCounter = 0;
    
    //if undo>0 we can undo the last move
    int undo = 0;
    
        printf("Welcome!\n");
        printBoard(a);

        double col = -1;
        int col2;
        int row;
        int gameOver = 0;
        int cWin = -1;
    
   while(gameOver==0){
      
        printf("Player X, please enter a column number (or 0 to undo):");
        scanf("%lf",&col);
        
        
        
        //the next lines check if the input is char, and prevent infinity loop
        char ch;

        while( ( ch = getchar() ) != '\n' && ch != EOF );
        
        if(col==0 && lastCounter==0){
            printf("Board is empty - can't undo!\n");
            col = -1;
        }
      
      while(col>7 || col<0){
          
          //check if input>7 or input<0
        
        printf("Invalid input, the number must be between 1 to 7:");
        scanf("%lf",&col);
        
        
        //the next lines check if the input is char, and prevent infinity loop
        char ch;

        while( ( ch = getchar() ) != '\n' && ch != EOF );
        
        if(col==0 && lastCounter==0){
            printf("Board is empty - can't undo!\n");
            col = -1;
        }

      }
      
      if(col==0){
          
          //undo the last move
          
          int ind = lastCol[lastCounter--];
          printf("%i\n",ind);

          for(int i=0; i<6; i++){
             if(a[i][ind]=='X' || a[i][ind]=='O'){
                 a[i][ind] = ' ';
                 undo = 1;
                 i = 6;
             }
          }
          
      }
      
      if(undo==0){
      
      col2 = (int)col;
       
        
        if(a[0][col2-1]=='X' || a[0][col2-1]=='O'){
            printf("Invalid input, this column is full. Please choose another one:\n");
            
            while(col==col2-1){
                scanf("%lf\n",&col);
                
                char ch;

                while( ( ch = getchar() ) != '\n' && ch != EOF );
                
            }
            
            
        }

      
      for(int j=5;j>=0;){
          
          //check which line to put the sign
          
          if(a[j][col2-1]=='X' || a[j][col2-1]=='O'){
            j--;
          }
          else{
            a[j][col2-1] = 'X';
            lastCol[++lastCounter] = col2-1;
            cWin = checkWin(a,j,col2-1,'X');

            
            if(cWin==1){
                printBoard(a);
                printf("Player X wins!\n");
                return;
            }
            
            else if(cWin==7){
                printBoard(a);
                printf("It's a tie!\n");
                return;
            }
            
            j = -1;
          }
      }
      
      }
      
      printBoard(a);
      
      //chack if the input is double(such as 1.5) 
      //if so the function print the board and close the game
      
       if(col-(int)col>0){
          printf("Invalid input, bye-bye!\n");
          gameOver = 1;
          return;
      }
      
      col = -1;
        
        printf("Player O, please enter a column number (or 0 to undo):");
        scanf("%lf",&col);
        
        //the next line check if the input is char, and prevent infinity loop
        while( ( ch = getchar() ) != '\n' && ch != EOF );
        
        if(col==0 && lastCounter==0){
            printf("Board is empty - can't undo!\n");
            col = -1;
        }
      
      while(col>7 || col<0){
        
        printf("Invalid input, the number must be between 1 to 7:");
        scanf("%lf",&col);
        
        
        //the next lines check if the input is char, and prevent infinity loop
        char ch;

        while( ( ch = getchar() ) != '\n' && ch != EOF );
        
        if(col==0 && lastCounter==0){
            printf("Board is empty - can't undo!\n");
            col = -1;
        }
      }
      
      undo = 0;
      
      if(col==0){
          
          int ind = lastCol[lastCounter--];
          printf("%i\n",ind);

          for(int i=0; i<6; i++){
             if(a[i][ind]=='X' || a[i][ind]=='O'){
                 a[i][ind] = ' ';
                 undo = 1;
                 i = 6;
             }
          }
          
      }
      
      if(col-(int)col>0){
          printf("Invalid input, bye-bye!\n");
          gameOver = 1;
      }
      
      if(undo==0){
      
      col2 = (int)col;
      

      if(a[0][col2-1]=='X' || a[0][col2-1]=='O'){
            printf("Invalid input, this column is full. Please choose another one:\n");
            
            while(col==col2-1){
            scanf("%lf\n",&col);
            
            char ch;

            while( ( ch = getchar() ) != '\n' && ch != EOF );
            
            }
            
        }
        
      
      for(int j=5;j>=0;){
          if(a[j][col2-1]=='X' || a[j][col2-1]=='O'){
            j--;
          }
          else{
            a[j][col2-1] = 'O';
            lastCol[++lastCounter] = col2-1;
            
            cWin = checkWin(a,j,col2-1,'O');
            
            if(cWin==1){
                printBoard(a);
                printf("Player O wins!\n");
                return;
            }
            
            else if(cWin==7){
                printBoard(a);
                printf("It's a tie!\n");
                return;
            }
            
            j = -1;
          }
          
          
      }
      
      }
      
        printBoard(a);
        if(col-(int)col>0){
          printf("Invalid input, bye-bye!\n");
          gameOver = 1;
          return;
      }

    col = -1;
    undo = 0;
       
   }
    
    
    
    
    
    
    
    
}
