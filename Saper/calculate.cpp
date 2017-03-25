//
// Created by maksi on 3/14/2017.
//

#include <iostream>
#include "const.h"

int adjacentMines(int x, int y);

// Flood Fill empty elements
void Bypassing_cover(int x, int y) {
    // Coordinates in Range?
        if (x >= 0 && y >= 0 && x < x_main && y < y_main) {
        // visited already?
            if (array_visited[x][y])
                return;

//            // uncover element
//            elements[x, y].loadTexture(adjacentMines(x, y));

            // close to a mine? then no more work needed here
            if (adjacentMines(x, y) > 0)
                return;

            // set visited flag
            array_visited[x][y] = true;

            // recursion
            Bypassing_cover(x-1, y);
            Bypassing_cover(x+1, y);
            Bypassing_cover(x, y-1);
            Bypassing_cover(x, y+1);
        }
}

int adjacentMines(int x, int y)
{
    if (array_field) return -1;
    else{
        int rez=0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j <2 ; ++j) {
                if (x+i >= 0 && y+j >= 0 && x+i < x_main && y+j < y_main)
                    if (array_field[x+i][y+j]) rez++;
            }
        }
        return rez;
    }
}
