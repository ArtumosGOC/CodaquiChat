#include "Window.h"
#include <stdio.h>
#include <locale.h>

//Window* window=nullptr;

Window::Window()
{

}

CONSOLE_SCREEN_BUFFER_INFO csbi;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	switch (msg)
	{
	case WM_CREATE:
	{

		Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;

		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
		window->setHWND(hwnd);
		window->onCreate();
		break;
	}

	case WM_DESTROY:
	{

		Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}


bool Window::init(LPCWSTR ClassName, LPCWSTR MenuName, int Width, int Height)
{

	this->MenuName = MenuName;
	this->ClassName = ClassName;
	this->Width = Width;
	this->Height = Height;



	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = this->ClassName;
	wc.lpszMenuName = this->MenuName;
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	if (!::RegisterClassEx(&wc))
		return false;

	m_hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, wc.lpszMenuName = this->MenuName,
		WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, this->Width, this->Height,
		NULL, NULL, NULL, this);

	if (!m_hwnd)
		return false;


	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);




	m_is_run = true;

	return true;
}



bool Window::broadcast()
{
	MSG msg;

	this->onUpdate();

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Sleep(1);

	return true;
}


bool Window::release()
{

	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

RECT Window::getClientWindowRect()
{
	RECT rc;
	::GetClientRect(this->m_hwnd, &rc);
	return rc;
}

void Window::setHWND(HWND hwnd)
{
	this->m_hwnd = hwnd;
}

void Window::onCreate()
{
	setlocale(LC_ALL, "");

	//onObject(L"EDIT",L"", 0, this->Height-90, this->Width -100, 50);
	onObject(L"EDIT_ROLL", L"", 0, this->Height - 90, this->Width - 80, 50);
	onObject(L"BUTTON", L"Enviar", this->Width - 100, this->Height-90, 85, 50);
	onObject(L"EDIT_ROLL", L"", 0, 0, this->Width - this->Width*0.05, this->Height - (this->Height - 110));
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

void Window::onObject(LPCWSTR Type, LPCWSTR Text, int X, int Y, int width, int height)
{

}

Window::~Window()
{
}