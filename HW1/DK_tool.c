//
// Created by maksi on 2/24/2017.
//

#include <dshow.h>
#include "stdio.h"
#include "dk_tool.h"
#include "malloc.h"
#include "stdlib.h"

DK_coor *CreateCoor(int Size_c)
{
    DK_coor *Triangle = (DK_coor *) malloc(sizeof(DK_coor));
    if(NULL != Triangle)
    {
        Triangle->x_coor = (DK_coor *)malloc(sizeof(DK_coor));
        bzero(Triangle->x_coor, Size_c * sizeof(DK_coor));
        
        
    }
    
    return Triangle;
}


float tru_scan()
{
    float a;
    int t;
    do
    {
        t=scanf("%f",&a);
        fflush(stdin);
        if(t!=1) printf("%s","Invalid input. Try again.\n");
    }
    while(t!=1);
    return a;
}

int* import()
{
    
        printf("Please enter dot A (-100000,000; 100000,000)");
        **NumberPoint = tru_scan();
        *(*NumberPoint) = tru_scan();
        printf("Please enter dot B (-100000,000; 100000,000)");
        **(NumberPoint + 1) = tru_scan();
        *(*NumberPoint + 1) = tru_scan();
        printf("Please enter dot C (-100000,000; 100000,000)");
        **(NumberPoint + 2) = tru_scan();
        *(*NumberPoint + 2) = tru_scan();
    return ;
}

