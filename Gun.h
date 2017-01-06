#ifndef __GUN_H__
#define __GUN_H__

#include "GameObject.h"

class Gun : public GameObject {
	float _rotation;
public:
	Gun();
	virtual ~Gun() {}
	float GetRotation() const;
	void Rotate(float angle);
	virtual void Move();
};

#endif // !__GUN_H__