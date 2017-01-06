#include "stdafx.h"
#include "Gun.h"

Gun::Gun()
	: GameObject(Core::resourceManager.Get<Render::Texture>("Turret"))
	, _rotation(0.0f)
{
}

float Gun::GetRotation() const
{
	return _rotation;
}

void Gun::Rotate(float angle)
{
	_rotation += angle;
}

void Gun::Move()
{
}
