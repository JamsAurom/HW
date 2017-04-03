#include <windows.h>
#include <iostream>

#include "const_main.h"
#include "KreatWnd.h"
#include "calculate.h"
#include "generayt.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    MSG msg;
    x_main = 20;
    y_main = 20;

    x_size = 20*x_main+3*SAP_LEFT;
    y_size = 20*y_main+4*SAP_TOP+30;

    GEN_BUMB = 100;

//    FILE *File_icon = fopen("ICON.ico","r");

    KWnd mainWnd("Saper", hinstance, nCmdShow, WndProc, NULL, 400, 100, x_size, y_size);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lparam)
{
    int userReply;

    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            break;
        }

        //make bakgraund window
        case WM_CREATE:





            //array malloc memory
            char number_error_array[25];
            char number_error[3];
            array_field = (int * *)malloc(x_main*sizeof(int*));
            if (array_field==NULL) {MessageBox(hWnd,"Error memory 1","Notification",0); return 0;}
            for (int i = 0; i < x_main; ++i) {
                array_field[i] = (int *)malloc(y_main*sizeof(int));
                if (array_field[i]==NULL) {
                    itoa(i, number_error, 3);
                    strcat(number_error_array, "Number Error 1 : ");strcat(number_error_array, number_error);
                    MessageBox(hWnd,number_error_array,"Notification",0);
                    for (int j = 0; j < i; ++j) {
                        free(array_field[j]);
                    }
                    free(array_field);
                    return 0;
                }
            }

            std::cout << "11" << std::endl;

            array_visited = (bool * *)malloc(x_main*sizeof(bool*));
            if (array_visited==NULL) {MessageBox(hWnd,"Error memory 2","Notification",0);
                for (int j = 0; j < x_main; ++j) { free(array_field[j]);}
                free(array_field); return 0;}
            for (int i = 0; i < x_main; ++i) {
                array_visited[i] = (bool *)malloc(y_main*sizeof(bool));
                if (array_visited[i]==NULL) {
                    itoa(i, number_error, 3);
                    strcat(number_error_array, "Number Error 2 : ");strcat(number_error_array, number_error);
                    MessageBox(hWnd,number_error_array,"Notification",0);
                    for (int j = 0; j < i; ++j) {
                        free(array_visited[j]);
                    }
                    for (int j = 0; j < x_main; ++j) {
                        free(array_field[j]);
                    }
                    free(array_visited);
                    free(array_field);
                    return 0;
                }
            }

            array_window_butten = (int * *)malloc(x_main*sizeof(int*));
            if (array_window_butten==NULL) {
                MessageBox(hWnd,"Error memory 3","Notification",0);
                for (int j = 0; j < x_main; ++j) {
                    free(array_field[j]);
                    free(array_visited[j]);
                }
                free(array_field); free(array_visited);
                return 0;}
            for (int i = 0; i < x_main; ++i) {
                array_window_butten[i] = (int *)malloc(y_main*sizeof(int));
                if (array_window_butten[i]==NULL) {
                    itoa(i, number_error, 3);
                    strcat(number_error_array, "Number Error 3 : ");strcat(number_error_array, number_error);
                    MessageBox(hWnd,number_error_array,"Notification",0);
                    for (int j = 0; j < i; ++j) {
                        free(array_window_butten[j]);
                    }
                    for (int j = 0; j < x_main; ++j) {
                        free(array_field[j]);
                        free(array_visited[j]);
                    }
                    free(array_visited);
                    free(array_field);
                    free(array_window_butten);
                    return 0;
                }
            }


            //array visit save false visit
            for(int i=0; i<x_main; i++)
                for(int j=0; j<y_main; j++){
                    *(*(array_field + i) + j) = 0;
                    array_visited[i][j] = false;
                }

            //BACKGRAUND
            SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG) CreateSolidBrush(RGB(178, 178, 178)));

            //TIME

            HWND Time_Window;

            CreateWindowEx(0,"Time","",
                           WS_CHILD | WS_VISIBLE | BS_BITMAP, 0, 0, x_size, 30,
                           hWnd,(HMENU)(1212121212),NULL,0);

            Time_Window = GetDlgItem(hWnd, 1212121212);
            SetClassLong(Time_Window, GCL_HBRBACKGROUND, (LONG) CreateSolidBrush(RGB(142, 194, 255)));

            gener(x_main, y_main, GEN_BUMB);
            for (int k = 0; k < x_main; ++k) {
                for (int i = 0; i < y_main; ++i) {
                    std::cout << "(" << k << ";" << i << ") = " << array_field[k][i]<< std::endl;
                }
            }

            char str5[3];

            //BUTTEN
            HWND ioo;
            for(int x=0; x<x_main; x++)
                for(int y=0; y<y_main; y++){
                    itoa(y+x, str5, 10);
                    CreateWindowEx(0,"BUTTON", "",
                                   WS_CHILD | WS_VISIBLE | BS_TEXT| BS_PUSHBUTTON, SAP_LEFT+x*20,
                                   SAP_TOP+y*20+30,20,20, hWnd,(HMENU)(x+y*x_main+1),NULL,0);

                    array_window_butten[x][y] = x+y*x_main+1;
                }

            break;

        case WM_COMMAND:
            //Если это контрол
            if(lparam!=0){
                //Индентификатор кнопки - 1
                int id=(wParam & 0x0000ffff)-1;
                //Строки
                char str1[30],str2[30], str4[30],str3[70]="Press butten ";
                //id%SAP_WIDTH - находим X координату кнопки
                itoa(id%SAP_WIDTH,str1,10);
                //id%SAP_WIDTH - находим Y координату кнопки
                itoa(id/SAP_WIDTH,str2,10);

                int x_temp = id%SAP_WIDTH;
                int y_temp = id/SAP_WIDTH;

                strcat(str3,str1);
                strcat(str3," : ");
                strcat(str3,str2);
                strcat(str3," : ");
                int y = adjacentMines(id%SAP_WIDTH, id/SAP_WIDTH);
                itoa(y,str4,10);
                strcat(str3,str4);
                SetColorSpace((HDC)array_window_butten[id%SAP_WIDTH][id/SAP_WIDTH], (HCOLORSPACE)RGB(34, 99,244));

                int g;
                char gii[30];
                HWND ioo;
                ioo = GetDlgItem(hWnd,array_window_butten[x_temp][y_temp]);
                g = GetWindowText (
                        ioo,		// дескриптор окна или элемента управления с текстом
                        gii,		// адрес буфера для текста
                        30 		// максимальное число символов для копирования
                );

                std::cout << x_temp<<" : "<< y_temp << "  " << gii<< "\n" << std::endl;
                char STR[2]={"1"};
                SetWindowText(ioo,STR);

//                DestroyWindow(ioo);

                //MessageBox(hWnd,str3,"Notification",0);

                //Загружаем BITMAP из ресурсов и шлем сообщение BM_SETIMAGE кнопке
                HBITMAP ic=LoadBitmap(NULL,MAKEINTRESOURCE(101));
                SendMessage((HWND)lparam,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)ic);

            }
            break;

//        case WM_PAINT:
//            hDC = BeginPaint(Time_Window, &ps);
//            //delayt backgraund
//            SetBkMode(hDC, TRANSPARENT);
//
//            GetClientRect(hWnd, &rect);
//            DrawText(hDC, "Hello, World!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//
//            EndPaint(hWnd, &ps);

            break;
        case WM_CLOSE:
            userReply = MessageBox(hWnd, "You want to close the application?", "", MB_YESNO | MB_ICONQUESTION);
            if(IDYES == userReply) {
                DestroyWindow(hWnd);

                //free memory
                for (int j = 0; j < x_main; ++j) {
                    free(array_field[j]);
                    free(array_visited[j]);
                    free(array_window_butten[j]);
                }
                free(array_visited);
                free(array_field);
                free(array_window_butten);
                std::cout << "Yes" << std::endl;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, uMsg, wParam, lparam);
    }
    return 0;
}


