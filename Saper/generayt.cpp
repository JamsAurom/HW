//
// Created by maksi on 3/14/2017.
//

#include <iostream>
#include <cstdlib>
#include "const.h"

bool random_bool();

void gener(int x, int y, int bump);

void generayt_mine(int x, int y)
{
    switch(x)
    {
        case 10:
        {
            gener(x, y, 10);
            break;
        }
        case 20:
        {
            gener(x, y, 20);
            break;
        }
        case 30:
        {
            gener(x, y, 30);
            break;
        }
        case 40:
        {
            gener(x, y, 50);
            break;
        }
    }
}

void gener(int x, int y, int bump)
{
    /*int g_bump=0;
    do
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (g_bump<bump && *(*(array_field+i)+j)!=1)
                {
                    if (rand() %100<=Probability_of_generation) {
                        *(*(array_field + i) + j) = 1;
                        g_bump++;
                    }
                }
            }
        }
    while ((g_bump<bump));*/
    int i, j, g_bump=0;

    do
    {
        i = rand () %x;
        j = rand () %y;
        if (*(*(array_field+i)+j)== 0){
            *(*(array_field + i) + j) = 1;
            g_bump++;
        }
    }
    while ((g_bump<bump));
}

//bool random_bool()
//{
//    bool rez;
//    int randomith;
//    randomith = rand() %2;
//    if (randomith==1) rez = true; else rez = false;
//    return rez;
//}