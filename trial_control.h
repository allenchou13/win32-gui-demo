#ifndef _TRIAL_CONTROL_H_
#define _TRIAL_CONTROL_H_

#include "control.h"

class TrialControl : public Control {

public:
	void paint(HDC hdc, RECT rect);
};

#endif /* _TRIAL_CONTROL_H_ */