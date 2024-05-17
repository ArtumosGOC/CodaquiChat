#pragma once
#include "Window.h"
#include <string>

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	virtual void onCreate() override;
	virtual void onObject(LPCWSTR Type, LPCWSTR Text, int X, int Y, int width, int height) override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;

};