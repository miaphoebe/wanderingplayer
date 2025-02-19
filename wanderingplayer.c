/* Homework 3: wanderingplayer.c
 * Author: Mia Hoffmann Kamrat
 * Acknowledgments: Starter for printgrid, validmoveexists, and stuck from Prof. Eikmeier
 * Follows the path of an NPC over a 10x10 2D array. */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Prints the current grid that has r rows and c columns.
void printgrid(int r, int c, char grid[r][c]) {
  // Goes through each row of the grid using the counter i.
  for (int i = 0; i < r; i++) {
    // Goes through each column of the grid using the counter j.
    for (int j = 0; j < c; j++) {
      // Prints the character at the current (i, j) position.
      printf("%c ", grid[i][j]);
    }
    printf("\n"); // Newline after each row.
  }
  printf("\n"); // Additional newline after the grid is fully printed.
}


// Checks if moving left is a viable option (the current position is not
// all the way left and the spot to the left has not already been occupied).
bool left(int r, int c, char grid[r][c], int currentrow, int currentcol){
  if(currentcol > 0 && grid[currentrow][currentcol - 1] == '.'){
    return true;
  }
  return false;
}

// Checks if moving right is a viable option (the current position is not
// all the way to the right and the spot to the right has not already been occupied).
bool right(int r, int c, char grid[r][c], int currentrow, int currentcol){
  if(currentcol < c - 1 && grid[currentrow][currentcol + 1] == '.'){
    return true;
  }
  return false;
}

// Checks if moving up is a viable option (the current position is not
// all the way at the top of the grid  and the spot above has not already been occupied).
bool up(int r, int c, char grid[r][c], int currentrow, int currentcol){
  if(currentrow > 0 && grid[currentrow - 1][currentcol] == '.'){
    return true;
  }
  return false;
}

// Checks if moving down is a viable option (the current position is not
// all the way at the bottom of the grid  and the spot below has not already been occupied).
bool down(int r, int c, char grid[r][c], int currentrow, int currentcol){
  if(currentrow < r - 1 && grid[currentrow + 1][currentcol] == '.'){
    return true;
  }
  return false;
}


// Checks if there are any valid moves left (left, right, up, or down).
bool validmoveexists(int r, int c, char grid[r][c], int currentrow, int currentcol) {
  if(left(r, c, grid, currentrow, currentcol) ||
     right(r, c, grid, currentrow, currentcol) ||
     up(r, c, grid, currentrow, currentcol) ||
     down(r, c, grid, currentrow, currentcol)){
    return true;
  }
  return false;
}


int main() {

  srand(time(NULL)); // Initializes random number generation.

  char grid[10][10]; // Creates the 10x10 grid.

  // Sets each (i, j) coordinate to '.' to start.
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      grid[i][j] = '.';
    }
  }

  // Chooses a random start position (currentrow, currentcol) in the grid.
  int currentrow = rand() % 10;
  int currentcol = rand() % 10;
  char c = 'A'; // Puts an 'A' in the initial position.
  grid[currentrow][currentcol] = c;

  // Prints the initial grid with 'A' in its random position.
  printgrid(10, 10, grid); 
  c++; // Sets c to the next char ('B').

  // Boolean to determine if there are no more valid moves.
  bool stuck = false;

  
  // Adds new NPC positions in the grid while there are valid moves and more letters
  // in the alphabet to go through.
  while (!stuck && c <= 'Z') {
    
    // Selects a random direction (0=left, 1=right, 2=up, 3=down).
    int direction = rand() % 4;

    // Moves in the randomly selected direction if possible.
    switch (direction) {
      
    case 0: // If direction=0, moves left one if possible and puts the next char c in that position. 
      if(left(10, 10, grid, currentrow, currentcol)){
        currentcol--; 
        grid[currentrow][currentcol] = c++;
        // Prints the grid with the new position.
        printgrid(10, 10, grid);
      }
      break;
      
    case 1: // If direction=1, moves right one if possible and puts the next char c in that position.
      if(right(10, 10, grid, currentrow, currentcol)){
        currentcol++;
        grid[currentrow][currentcol] = c++;
        // Prints the grid with the new position.
        printgrid(10, 10, grid);
      }
      break;
      
    case 2: // If direction=2, moves up one if possible and puts the next char c in that position.
      if(up(10, 10, grid, currentrow, currentcol)){
        currentrow--;
        grid[currentrow][currentcol] = c++;
        // Prints the grid with the new position.
        printgrid(10, 10, grid);
      }
      break;
      
    case 3: // If direction=3, moves down one if possible and puts the next char c in that position.
      if(down(10, 10, grid, currentrow, currentcol)){
        currentrow++;
        grid[currentrow][currentcol] = c++;
        // Prints the grid with the new position. 
        printgrid(10, 10, grid);
      }
      break;
    }
    
    // Checks if there are any valid moves left after each run through the loop.
    if (!validmoveexists(10, 10, grid, currentrow, currentcol)) {
      stuck = true;
    }
  }
  
  return 0;
}



