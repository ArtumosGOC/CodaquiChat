// BotTaskCodaqui.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "AppWindow.h"

int main()
{
	ShowWindow(GetConsoleWindow(), 0);
	AppWindow app;
	if (app.init(L"Codaqui_Bot",L"Chat Codaqui", 700, 200))
	{
		while (app.isRun())
		{
			app.broadcast();
		}
	}

	
}