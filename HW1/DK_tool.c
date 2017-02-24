//
// Created by maksi on 2/24/2017.
//

#include <dshow.h>
#include "stdio.h"
#include "dk_tool.h"
#include "malloc.h"

DK_coor *CreateCoor(int Size_c)
{
    DK_coor *Triangle = (DK_coor *) malloc(sizeof(DK_coor));

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
    float **NumberPoint;
    (*NumberPoint) = (float*)malloc(3* sizeof(float));
    NumberPoint = (float*)malloc(2* sizeof(float));
    if (NULL != NumberPoint) {
        printf("Please enter dot A (-100000,000; 100000,000)");
        **NumberPoint = tru_scan();
        *(*NumberPoint) = tru_scan();
        printf("Please enter dot B (-100000,000; 100000,000)");
        **(NumberPoint + 1) = tru_scan();
        *(*NumberPoint + 1) = tru_scan();
        printf("Please enter dot C (-100000,000; 100000,000)");
        **(NumberPoint + 2) = tru_scan();
        *(*NumberPoint + 2) = tru_scan();
    }
    return NumberPoint;
}

int addDK_coor(DK_coor *Trin, int *NumPoint, float x_point, float y_point)
{
    int Result=0;

    if (NULL != Trin && NULL != NumPoint)
    {
        DK_coor *Tringl = &(Trin ->x_coor);
        Tringl->x_coor = x_point;


    }
}
