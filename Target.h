#ifndef __TARGET_H__
#define __TARGET_H__

#include "GameObject.h"

class Target : public GameObject {
public:
	Target();
	virtual ~Target() {}
	virtual void Move();
};

#endif // !__TARGET_H__