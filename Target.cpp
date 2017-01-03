#include "stdafx.h"
#include "Target.h"

void Target::makeSplinePath()
{
	_spline.addKey(1.0f, FPoint(10.0f, 5.0f));
	_spline.addKey(1.0f, FPoint(60.0f, 5.0f));
	_spline.addKey(1.0f, FPoint(90.0f, 5.0f));
	_spline.addKey(1.0f, FPoint(110.0f, 5.0f));
	_spline.addKey(1.0f, FPoint(210.0f, 5.0f));
	_spline.CalculateGradient();
}

Target::Target()
	: _position(FPoint()),
	_speed(0.0f),
	_alive(true),
	_texture(nullptr)
{
		_texture = Core::resourceManager.Get<Render::Texture>("Circle");
		makeSplinePath();
}

Target::Target(FPoint position)
	: _position(position),
	_speed(0.0f),
	_alive(true),
	_texture(nullptr)
{
	_texture = Core::resourceManager.Get<Render::Texture>("Circle");
	makeSplinePath();
}

void Target::SetTexture(Render::Texture * texture)
{
	_texture = texture;
}

Render::Texture* Target::GetTexture() const
{
	return _texture;
}

TimedSpline<FPoint> const & Target::GetSpline() const
{
	return _spline;
}
