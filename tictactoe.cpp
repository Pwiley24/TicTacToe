#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//function declarations:
void runGame();
void printGrid(char board[4][7]);

int main(){
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

 

  runGame();

}

/*
 *This function will run until someone wins
 */
void runGame(){
  bool playing = true;
  const char X_TURN = 'X';
  const char Y_TURN = 'O';
  char turn = 'X';
  char input[3];
  
  while(playing){ 
   cout << "Player " << turn << ", what's your move?" << endl; 
   cin.get(input, 3);
   if(input[0] >= 49 ||
      input[0] <= 51){ //first letter typed is a number b/w 1-3
    if(input[1] >= 97 ||
       input[1] <= 99){ //second letter is a letter b/w a-c
      cout << "IT WORKED" << endl;
    }
   }
   if(turn == 'X'){
     turn = 'O';
   }else {
     turn = 'X';
   }
   input //WORK HERE> Reset input please

   
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


//Basic Idea for Tic Tac Toe:

// create a 4x4 grid
//  123
//a
//b
//c

//within a while game is playing = true
  //let a user choose a spot
  //check if valid (equals a blank space)
  //if x's turn place an x otherwise place an o
  //check for x wins/y wins/ties
  //switch to other's turn

//to check for x wins/ y wins (two functions: one for x checks, one for y)
  //go through all spots:
    //if winning spots are ocupied return (x or y) winner depending on which function is performing 
