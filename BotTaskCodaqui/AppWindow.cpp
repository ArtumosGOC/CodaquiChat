#include "AppWindow.h"

struct vector3d
{
	float x, y, z;
};
struct vertex
{
	vector3d position;
};

AppWindow::AppWindow()
{

}


AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
}

void AppWindow::onObject(LPCWSTR Type, LPCWSTR Text, int X, int Y, int width, int height)
{
	if (Type == L"EDIT")
	{
        CreateWindow
        (   Type,  // Classe predefinida; Unicode assumido
            Text,      // Texto 
            ES_AUTOVSCROLL| WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE,  // Style 
            X,         // x pos
            Y,         // y pos
            width,        //  largura
            height,        //  largura
            m_hwnd,     // Janela pai
            NULL,       // menu.
            (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
            NULL);      // Ponteiro não necessário
	}
    if (Type == L"EDIT_ROLL")
    {
        Type = L"EDIT";
        CreateWindow
        (Type,  // Classe predefinida; Unicode assumido
            Text,      // Texto 
            0x00800000L | 0x40000000L | 0x10000000L | 0x00200000L | 0x0000L |
            0x0004L | 0x0040L,  // Style 
            X,         // x pos
            Y,         // y pos
            width,        //  largura
            height,        //  largura
            m_hwnd,     // Janela pai
            NULL,       // menu.
            (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
            NULL);      // Ponteiro não necessário
    }
    if (Type == L"BUTTON")
    {
        CreateWindow
        (   Type,  // Classe predefinida; Unicode assumido
            Text,      // Texto 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Style 
            X,         // x pos
            Y,         // y pos
            width,        //  largura
            height,        //  largura
            m_hwnd,     // Janela pai
            NULL,       // menu.
            (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
            NULL);      // Ponteiro não necessário
    }

}

void AppWindow::onUpdate()
{
	Window::onUpdate();
}

void AppWindow::onDestroy()
{
	Window::onDestroy();

}