//
// Created by maksi on 3/22/2017.
//


#include <iostream>
#include <windows.h>

#include "KreatWnd.h"
#include "const.h"
#include "calculate.h"
#include "generayt.h"

KWnd::KWnd(LPCTSTR windowsName, HINSTANCE hInst, int cmdShow, LRESULT (WINAPI *pWndProc)(HWND, UINT, WPARAM, LPARAM),
           LPCTSTR menuName, int x, int y, int width, int height, UINT classStile, DWORD windowStyle, HWND hParent)
{
    char szClassName[] = "KWndClass";

    //hPict0 = (HBITMAP)LoadImage( hInst, i0, IMAGE_BITMAP, 20, 20, LR_LOADFROMFILE);


    wc.cbSize = sizeof(wc);
    wc.style = classStile;
    wc.lpfnWndProc = pWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
//    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIcon = (HICON)LoadImage(NULL, (LPCTSTR)"ICON.ico", IMAGE_ICON, 30, 30, LR_LOADFROMFILE);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = menuName;
    wc.lpszClassName = szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Regist class Window
    if (!RegisterClassEx(&wc))
    {
        char msg[100] = "Can not register class: ";
        strcat(msg, szClassName);
        MessageBox(NULL, msg, "Error", MB_OK);
        return;
    }

    //creat Window
    hWnd = CreateWindow(
            szClassName, windowsName, windowStyle, x, y,
            width, height, hParent, (HMENU)NULL, hInst, NULL);

    if (!hWnd) {
        char texe_erorr[100] = "Cannot create window : ";
        strcat(texe_erorr, windowsName);
        MessageBox(NULL, texe_erorr, "Error", MB_OK);
        return;
    }

    //Show Window
    ShowWindow(hWnd, cmdShow);
}

