#include "Button.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

tButton btn = tButton(L"Hello xd", tPoint(10, 10), tPoint(100, 40));

VOID OnPaint(HDC hdc);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    HWND                hWnd;
    MSG                 msg;
    WNDCLASS            wndClass;
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    // Initialize GDI+.
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("GettingStarted");

    RegisterClass(&wndClass);

    hWnd = CreateWindow(
        TEXT("GettingStarted"),   // window class name
        TEXT("Getting Started"),  // window caption
        WS_OVERLAPPEDWINDOW,      // window style
        CW_USEDEFAULT,            // initial x position
        CW_USEDEFAULT,            // initial y position
        CW_USEDEFAULT,            // initial x size
        CW_USEDEFAULT,            // initial y size
        NULL,                     // parent window handle
        NULL,                     // window menu handle
        hInstance,                // program instance handle
        NULL);                    // creation parameters

    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        tMouse mouse;
        POINT pos;

        if ((GetAsyncKeyState(VK_LBUTTON))) {
            mouse.button = tMouseButtons::Left;
            mouse.state = tMouseButtonStates::Down;
        }
        else if (GetAsyncKeyState(VK_RBUTTON)) {
            mouse.button = tMouseButtons::Right;
            mouse.state = tMouseButtonStates::Down;
        }
        else if (GetAsyncKeyState(VK_MBUTTON)) {
            mouse.button = tMouseButtons::Middle;
            mouse.state = tMouseButtonStates::Down;
        }
        else {
            mouse.button = tMouseButtons::None;
            mouse.state = tMouseButtonStates::Up;
        }

        if (GetCursorPos(&pos) && ScreenToClient(hWnd, &pos)) {
            mouse.pos = tPoint(pos.x, pos.y);
        }

        btn.Update(mouse);

        HDC hdc = GetDC(hWnd);
        OnPaint(hdc);
        ReleaseDC(hWnd, hdc);
    }

    Gdiplus::GdiplusShutdown(gdiplusToken);
    return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC          hdc;
    PAINTSTRUCT  ps;

    switch (message)
    {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            OnPaint(hdc);
            EndPaint(hWnd, &ps);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
} // WndProc

void OnPaint(HDC hdc)
{
    //Graphics graphics(hdc);
    //Gdiplus::Pen      pen(Color(255, 0, 0, 255));
    //graphics.DrawLine(&pen, 0, 0, 200, 100);

    btn.Draw(hdc);
}