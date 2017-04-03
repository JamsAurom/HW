//
// Created by maksi on 3/24/2017.
//

#ifndef SAPER_CONST_H
#define SAPER_CONST_H


#include <windows.h>

#define SAP_WIDTH 20            //Ширина поля
#define SAP_HEIGHT 20           //Высота поля
#define SAP_TOP 15      //Отступ сверху
#define SAP_LEFT 15         //Отступ слева

extern int x_main, y_main;

extern int x_size, y_size;

extern int **array_field;
extern bool **array_visited;
extern int **array_window_butten;

extern int GEN_BUMB;

//typedef struct cell
//{
//    int visite;
//    int bumb;
//} cell_all;

#endif //SAPER_CONST_H
