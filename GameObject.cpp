#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(Render::Texture * texture)
	: _texture(texture)
	, _position()
	, _direction(1.0f, 1.0f)
	, _velocity(10.0f)
	, _alive(true)
{}

Render::Texture * GameObject::GetTexture() const
{
	return _texture;
}

bool GameObject::IsAlive() const
{
	return _alive;
}

void GameObject::Kill()
{
	_alive = false;
}

void GameObject::ChangeDirection(FPoint point)
{
	point.Normalize();
	float scalar = (_direction.x * point.x) + (_direction.y * point.y);
	float angle = 90 - acos(scalar);
	float gip = sqrtf(pow(_direction.x, 2) + pow(_direction.y, 2));
	float x = sin(angle) * gip;
	float y = cos(angle) * gip;
	_direction.x = x;
	_direction.y = y;
	_direction.Normalize();
}

FPoint GameObject::GetPosition() const
{
	return _position;
}

FPoint GameObject::GetCenter() const
{
	IRect textureRect = _texture->getBitmapRect();
	float centerX = _position.x + (textureRect.Width() / 2);
	float centerY = _position.y + (textureRect.Height() / 2);
	return FPoint(centerX, centerY);
}

IRect GameObject::GetRecatngle() const
{
	IRect textureRect = _texture->getBitmapRect();
	return IRect(_position.x, _position.y, textureRect.width, textureRect.height);
}

FPoint GameObject::GetDirection() const
{
	return _direction;
}