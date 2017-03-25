//
// Created by maksi on 3/24/2017.
//

#ifndef SAPER_CONST_MAIN_H
#define SAPER_CONST_MAIN_H

#include <windows.h>

#define SAP_WIDTH 20            //Ширина поля
#define SAP_HEIGHT 20           //Высота поля
#define SAP_TOP 15      //Отступ сверху
#define SAP_LEFT 15         //Отступ слева

int x_main, y_main;

int x_size, y_size;

bool **array_field;
bool **array_visited;
HWND **array_window_butten;

#endif //SAPER_CONST_MAIN_H
