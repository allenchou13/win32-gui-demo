#ifndef _BUTTON_H_
#define _BUTTON_H_	

#include "control.h"


class Button : public Control {
private:
	double width;
	double height;

public:
	void paint(HDC hdc, RECT rect);
};

#endif /* _BUTTON_H_ */