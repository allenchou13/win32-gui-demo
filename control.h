#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <Windows.h>

class Control {
public:
	void virtual paint(HDC hdc, RECT rect);
};

#endif /* _CONTROL_H_ */