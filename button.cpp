#include "button.h"

void Button::paint(HDC hdc, RECT rect) {
	MoveToEx(hdc, rect.left, rect.top, nullptr);
	LineTo(hdc, rect.right, rect.top);
	LineTo(hdc, rect.right, rect.bottom);
	LineTo(hdc, rect.left, rect.bottom);
	LineTo(hdc, rect.left, rect.top);
}