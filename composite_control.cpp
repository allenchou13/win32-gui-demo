#include "composite_control.h"
#include <algorithm>

void CompositeControl::paint(HDC hdc, RECT rect) {
	std::for_each(children.cbegin(), children.cend(), [hdc, rect](Control* c) {
		c->paint(hdc, rect);
	});
}

void CompositeControl::add_child(Control* c)
{
	children.push_back(c);
}
