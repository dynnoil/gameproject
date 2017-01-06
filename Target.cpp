#include "stdafx.h"
#include "Target.h"

Target::Target()
	: GameObject(Core::resourceManager.Get<Render::Texture>("Bubble"))
{
}

void Target::Move()
{
	FPoint point(_direction);
	point *= _velocity;
	_position += point;
}
