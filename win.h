#include <string>
#include <Windows.h>
#include "control.h"


class Window {
private:
	std::string win_class_name;
	HWND hwnd = 0;
	Control *control;
	
	static Window* inst;

public:
	Window();
	~Window();
	void show();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};