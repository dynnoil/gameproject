#include "stdafx.h"
#include "GameWidget.h"

GameWidget::GameWidget(const std::string & name, rapidxml::xml_node<>* elem)
	: Widget(name)
{
}

void GameWidget::Draw()
{
}

void GameWidget::Update(float dt)
{
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
}

void GameWidget::CharPressed(int unicodeChar)
{
}
