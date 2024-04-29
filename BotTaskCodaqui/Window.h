#pragma once
#include <Windows.h>



class Window
{
public:
	Window();
	//Initialize the window
	bool init(LPCWSTR ClassName, LPCWSTR MenuName, int width, int height);
	bool broadcast();
	//Release the window
	bool release();
	bool isRun();

	//LPCWSTR
	LPCWSTR ClassName;
	LPCWSTR MenuName;

	int Width;
	int Height;


	RECT getClientWindowRect();
	void setHWND(HWND hwnd);


	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	virtual void onObject(LPCWSTR Type, LPCWSTR Text, int X, int Y, int width, int height);


	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};