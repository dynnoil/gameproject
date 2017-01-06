#ifndef __GAMEWIDGET_H__
#define __GAMEWIDGET_H__

#include "Target.h"

class GameWidget : public GUI::Widget {
	unsigned int _targetsAmount;
	unsigned int _speed;
	unsigned long _time;
	Target *target;
	TimedSpline<FPoint> spline;
	float _timer;
public:
	GameWidget(const std::string& name, rapidxml::xml_node<>* elem);

	void Draw() override;
	void Update(float dt) override;
	void AcceptMessage(const Message& message) override;
	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;
    void KeyPressed(int keyCode) override;
	void CharPressed(int unicodeChar) override;
};

#endif // !__GAMEWIDGET_H__