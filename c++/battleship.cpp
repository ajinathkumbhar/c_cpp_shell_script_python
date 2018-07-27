//  battleship1/main.cpp -- Version 1 of Battleship game.
//  Fred Swartz, 2003-11-25

// This first iteration runs, but needs lots of work.
// Here is a list of some important changes.  
// Choose one simple improvement and get that working
// before starting on the next iteration.  Most of these
// are small improvements, but its important to get this
// one-dimensional version running first, then extend it
// to two-dimensions, multiple ships, different size ships,
// . . .
// 
// FUNCTIONALITY
//  * The dropBomb() function doesn't do anything.
//  * The initialize() function doesn't randomly place ships.
//  * No end of game check (function to look for umbombed ship).
//  
// USER INTERFACE
//  * Verify user input has legal bombing coordinates.
//  * Print coordinates at bottom.
//  * Allow number without command to mean drop bomb.
//  * Not robust - crashes if bombing coordinate missing.
//
// INTERNAL                            
//  * Refactor - move command decoding out of main.
//  * Should be a developer command to display where ships are.
//
// LONGER RANGE (after previous improvements)
//  * Make it two-dimensional.
//  * Add multiple ships, and maybe multiple ship sizes.

//==================================================== includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include<stdio.h>
using namespace std;

//========================================= global declarations
// Damage enum defines possible values at each grid point.
enum Damage {WATER_UNBOMBED, WATER_BOMBED, 
                 SHIP_UNBOMBED , SHIP_BOMBED};

// The display array defines what to display for
//     each of the Damage enum values.  Changes to the
//     Damage enum require this to be changed also.
const char userDisplay[] = {'-', 'O', '-', 'X'};

const  int WIDTH = 10;   // Width of the grid.
Damage grid[WIDTH];      // Status of every grid cell.


//================================================== prototypes
void dropBomb(int xcoord);
void initGrid();
void displayGrid();


//======================================================== main
int main() {

        //-- Place ships on the grid.
        initGrid();
            displayGrid();
                
                char commandCode;
                    while (cin >> commandCode) {
                                switch (commandCode) {
                                                
                                                case 'q':           // quit
                                                                    exit(0);
                                                                                    break;
                                                                                                    
                                                                                                case 'b':           // bomb
                                                                                                    int column;
                                                                                                                    cin >> column;
                                                                                                                                    dropBomb(column);
                                                                                                                                                    displayGrid();
                                                                                                                                                                    break;
                                                                                                                                                                                    
                                                                                                                                                                                default:
                                                                                                                                                                                    cerr << "Bad input " << commandCode << endl;
                                                                                                                                                                                                    break;
                                                                                                                                                                                                            }
                                    }
                        
                        return 0;
}//end main


//======================================================= dropBomb
void dropBomb(int xcoord) {
        //-- Do nothing for now except print to show
        //   we got here.
        cout << "TRACE: bomb(" << xcoord << ")" << endl;
            
            return;
}


//======================================================= initGrid
// initGrid() places random ships on the grid.
void initGrid() {
        for (int col=0; col<WIDTH; col++) {
                    grid[col] = WATER_UNBOMBED;
                        }
            // Temporarily start with one ship, random later.
            grid[0] = SHIP_UNBOMBED;
                grid[1] = SHIP_UNBOMBED;
}


//==================================================== displayGrid
void displayGrid() {
        cout << endl;
            for (int col=0; col<WIDTH; col++) {
                        cout << " " << userDisplay[grid[col]];
                            }
                cout << endl;
}

