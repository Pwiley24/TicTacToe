//This program allows two users to play tic tac toe against each other.
//Author: Paige Wiley
//Date: 10-03-2022

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//function declarations:
void runGame(char gameboard[4][7], int &xWins, int &oWins);
void printGrid(char board[4][7]);
void inputOnGrid(char position[3], char player, char gameboard[4][7]);
int convertToBoard(char letter);
bool checkWin(char turn, char board[4][7]);
bool checkTie(char board[4][7]);

int main(){
  bool playing = true;
  int oWins = 0;
  int xWins = 0;
    
   while(playing){
     char yn = ' ';
     //Grid setup:
     char grid[4][7];
     for(int y = 1; y <= 4; y++){
       for(int x = 1; x <= 7; x++){
         grid[y][x] = ' ';
       }
     }
     grid[1][3] = '1';
     grid[1][5] = '2';
     grid[1][7] = '3';
     grid[2][1] = 'a';
     grid[3][1] = 'b';
     grid[4][1] = 'c';

     printGrid(grid);

    
     runGame(grid, xWins, oWins);
     cout << "O wins: " << oWins << endl;
     cout << "X wins: " << xWins << endl;
     cout << "Play another round? y/n" << endl;
     cin >> yn;
     cin.ignore(10, '\n');
     if(yn == 'n'){
       playing = false;
     }
   }

 }

 /*
  *This function will run until someone wins
  */
void runGame(char gameboard[4][7], int &xWin, int &oWin){
   bool round = true;
   const char X_TURN = 'X';
   const char Y_TURN = 'O';
   char turn = 'X';
   
   while(round){
    char input[3];
    cout << "Player " << turn << ", what's your move?" << endl; 
    cin.get(input, 3);
    cin.ignore(10, '\n');
    cout << "input: " << input << endl;
    if(input[0] >= 49 &&
       input[0] <= 51){ //first letter typed is a number b/w 1-3
     if(input[1] >= 97 &&
       input[1] <= 99){ //second letter is a letter b/w a-c

       if(gameboard[convertToBoard(input[1])][convertToBoard(input[0])] == ' '){ //spot isn't already taken

 	//place x or o on grid
 	inputOnGrid(input, turn, gameboard);

 	if (checkWin(turn, gameboard)){
 	  cout << "Player " << turn << " won!" << endl;
 	  if(turn == 'X'){
 	    xWin++;
 	  }else {
 	    oWin++;
 	  }
 	  round = false;
 	}
 	if(checkTie(gameboard)){
	  cout << "It's a tie!" << endl;
	  round = false;
	}

 	printGrid(gameboard);

 	//change the players turn:
 	if(turn == 'X'){
 	  turn = 'O';
 	}else {
 	  turn = 'X';
 	}
	
       }else {
 	cout << "This spot is already taken." << endl;
       }

       }else {
        cout << "Please input a valid row letter." << endl;
     }
    }else {
      cout << "Please input a valid column number." << endl;
    }
   }
  
 }



 /*
  * Function will convert the chars to the corresponding positions on the board with regards to the index of the gameboard's char array.
  *It will take in a char value and convert it to the corresponding board number.
  */
   int convertToBoard(char letter){
     int num = 0;
     if(letter == 'a'){
       num = 2;
     }else if(letter == 'b'){
       num = 3;
     }else if(letter == 'c'){
       num = 4;
     }else if(letter == '1'){
       num = 3;
     }else if(letter == '2'){
       num = 5;
     }else if(letter == '3'){
       num = 7;
     }
     return num;
   }


 /*
  *This function will assign X or O to the spot the user wants to place their X or O to.
  *It will take in the input value, the turn, and the board.
  */
 void inputOnGrid(char position[3], char player, char gameboard[4][7]){
   int row = 0;
   int column = 0;
   row = convertToBoard(position[1]);
   column = convertToBoard(position[0]);
  
   for(int y = 1; y <= 4; y++){
     for(int x = 1; x <= 7; x++){
       if(y == row &&
 	 x == column &&
 	 gameboard[row][column] == ' '){ //find the position where the X or O goes
 	gameboard[y][x] = player;

       }	
      
     }
   }
 }

 /*
  * This function will print the values of the grid to the console
  */
 void printGrid(char board[4][7]){
   for(int y = 1; y <= 4; y++){
     for(int x = 1; x <= 7; x++){
       cout << board[y][x];
      }
     cout << endl;
   }
 }


/*
 *Function will check for ties after a player makes a move.
 *It will take in the board.
 */
bool checkTie(char board[4][7]){
  int filled = 0;
  for(int y = 1; y <= 4; y++){
    for(int x = 1; x <= 7; x++){
      if(board[y][x] == 'X' ||
	 board[y][x] == 'O'){
	filled++;
      }
    }
  }
  if(filled >=9){ //all spots are filled
    return true;
  }
  return false;
}


 /*
  *Function will check for wins after a player makes a move.
  *It will take in the player whose turn it is.
  */
 bool checkWin(char player, char board[4][7]){
   if(board[2][3] == player &&
      board[2][5] == player &&
      board[2][7] == player){ //across top
     return true;
   }else if(board[3][3] == player &&
      board[3][5] == player &&
      board[3][7] == player){ //across middle
     return true;
   }else if(board[4][3] == player &&
      board[4][5] == player &&
      board[4][7] == player){ //across bottom
     return true;
   }else if(board[2][3] == player &&
      board[3][3] == player &&
      board[4][3] == player){ //down left
     return true;
   }else if(board[2][5] == player &&
      board[3][5] == player &&
      board[4][5] == player){ //down middle
     return true;
   }else if(board[2][7] == player &&
      board[3][7] == player &&
      board[4][7] == player){ //down right
     return true;
   }else if(board[2][3] == player &&
      board[3][5] == player &&
      board[4][7] == player){ //diagonal left to right
     return true;
   }
  else if(board[4][1] == player &&
     board[3][5] == player &&
     board[2][7] == player){ //diagonal right to left
    return true;
  }
  return false;
}



