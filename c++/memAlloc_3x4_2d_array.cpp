#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>

#define H_PIXEL 2
#define V_PIXEL 2

using namespace std;

struct pixel {
    int x;
    int y;
    int color;
};

typedef struct pixel t_pixel;

/*
   Allocate memory for 2d array where 
   each element is memory address which
   type of t_pixel

    0       1       2       3
  +------------------------------
0 | 23      99      56      88  |
  -------------------------------
1 | 33      97      12      99  |
  -------------------------------
2 | 20      34      23      01  |
  -------------------------------

 
Ans>>>>
hint: 
- Declare array which  size is number of rows
    t_pixel * rowArray[V_PIXEL];
- Alloc memory for each row and fill col element values 
- Assign a address to first element of rowArray
- and so on .... 
 
 Means a rowArray is holding addresses of array's.
 */

int main(int argc, char * argv[]){
    int x,y,color;
    t_pixel * col;
    t_pixel * rowArray[V_PIXEL];
    
    int doMore = 0;
    int fillCol = 0;
    while (doMore < V_PIXEL) {
        fillCol=0;
        col = new t_pixel[H_PIXEL];
        if ( col == NULL ) {
            cout << " failed alloc mem for col" << endl;
            return EXIT_FAILURE;
        }
        while (fillCol < H_PIXEL) {
            cout << "Filling : col["<< fillCol << "]" << endl;
            cin >> x >> y >> color ;
            col[fillCol].x = x;
            col[fillCol].y = y;
            col[fillCol].color = color;
            fillCol++;
        }
        rowArray[doMore++] = col;    
        col = NULL;
    }

    for(int r=0; r < V_PIXEL; r++) {
        for(int c=0; c < H_PIXEL; c++) {
            x = rowArray[r][c].x;
            y = rowArray[r][c].y;
            color = rowArray[r][c].color;
            cout << setw(4) << x ;
            cout << setw(4) << y ;
            cout << setw(4) << color ;
            cout << endl; 
        }
        delete[] rowArray[r];
      }
        
    return EXIT_SUCCESS;
}
