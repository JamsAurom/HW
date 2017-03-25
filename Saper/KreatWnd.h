//
// Created by maksi on 3/22/2017.
//

#include <windows.h>

#ifndef SAPER_WND_H
#define SAPER_WND_H

#endif //SAPER_WND_H

class KWnd {
public:
    KWnd(LPCTSTR windowsName, HINSTANCE hInst, int cmdShow,
         LRESULT(WINAPI *pWndProc)(HWND, UINT, WPARAM, LPARAM),
        LPCTSTR menuName = NULL,
        int x = CW_USEDEFAULT, int y = 0,
        int width = CW_USEDEFAULT, int height = 0,
        UINT classStile = CS_HREDRAW | CS_VREDRAW,
        DWORD windowStyle = WS_OVERLAPPEDWINDOW,
        HWND hParent = NULL);

    HWND GerHWnd() { return hWnd;}

protected:
    HWND hWnd;
    WNDCLASSEX wc;
};