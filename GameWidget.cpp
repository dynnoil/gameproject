#include "stdafx.h"
#include "GameWidget.h"

#define VIEWPORT Render::device.GetViewport()

GameWidget::GameWidget(const std::string & name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _timer(0.0f)
{
	target = new Target();

	spline.addKey(0.0f, FPoint(100.0f, 100.0f));
	spline.addKey(0.25f, FPoint(150.0f, 300.0f));
	spline.addKey(0.5f, FPoint(500.0f, 300.0f));
	spline.addKey(0.75f, FPoint(630.0f, 450.0f));
	spline.addKey(1.0f, FPoint(600.0f, 550.0f));
	spline.CalculateGradient();
}

void GameWidget::Draw()
{
	if (target->IsAlive()) {
		//FPoint currentPosition = spline.getGlobalFrame(math::clamp(0.0f, 0.5f, _timer / 12.0f));
		Render::device.PushMatrix();
		Render::device.MatrixTranslate(target->GetPosition());
		target->GetTexture()->Draw();
		Render::device.PopMatrix();
	}
}

void GameWidget::Update(float dt)
{
	_timer += dt * 2;
	while (_timer > 2 * math::PI)
	{
		_timer -= 2 * math::PI;
	}
	if (VIEWPORT.Contains(target->GetRecatngle())) {
		target->Move();
	}
	else {
		target->ChangeDirection(target->GetTexture()->getBitmapRect().LeftTop());
		target->Move();
	}
}

void GameWidget::AcceptMessage(const Message & message)
{
}

bool GameWidget::MouseDown(const IPoint & mouse_pos)
{
	return false;
}

void GameWidget::MouseMove(const IPoint & mouse_pos)
{
}

void GameWidget::MouseUp(const IPoint & mouse_pos)
{
}

void GameWidget::KeyPressed(int keyCode)
{
	if (keyCode == VK_SPACE) {
		target->Kill();
	}
}

void GameWidget::CharPressed(int unicodeChar)
{
}
