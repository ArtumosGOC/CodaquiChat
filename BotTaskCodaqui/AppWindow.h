#pragma once
#include "Window.h"

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