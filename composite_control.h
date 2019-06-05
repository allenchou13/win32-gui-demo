#ifndef _COMPOSITE_CONTROL_H_
#define _COMPOSITE_CONTROL_H_

#include <vector>
#include "control.h"

class CompositeControl : public Control {
private:
	std::vector<Control*> children;
public:
	void paint(HDC hdc, RECT rect);
	void add_child(Control* c);
};

#endif /* _COMPOSITE_CONTROL_H_ */