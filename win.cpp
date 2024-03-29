#include <stdexcept>
#include "win.h"
#include "composite_control.h"
#include "button.h"
#include "trial_control.h"

#pragma comment(lib, "winmm.lib")

Window* Window::inst = nullptr;

Window::Window()
{
	if (inst != nullptr) {
		throw std::logic_error("can only create one window.");
	}
	inst = this;
	auto c = new CompositeControl();
	c->add_child(new TrialControl());
	c->add_child(new Button());
	control = c;
}

Window::~Window()
{
	inst = NULL;
}

void Window::show() {
	HINSTANCE hInstance = GetModuleHandle(NULL);
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return;
	}
	hwnd = CreateWindow(szAppName, // window class name
		TEXT("The Hello Program"), // window caption
		WS_OVERLAPPEDWINDOW, // window style
		CW_USEDEFAULT,// initial x position
		CW_USEDEFAULT,// initial y position
		CW_USEDEFAULT,// initial x size
		CW_USEDEFAULT,// initial y size
		NULL, // parent window handle
		NULL, // window menu handle
		hInstance, // program instance handle
		NULL); // creation parameters
	// ShowWindow(hwnd, iCmdShow);
	ShowWindow(hwnd, true);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	// return msg.wParam;
}

LRESULT Window::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (message)
	{
	case WM_CREATE:
		PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		inst->control->paint(hdc, rect);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
