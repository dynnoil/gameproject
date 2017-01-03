#ifndef __SHOOTINGGAMEDELEGATE_H__
#define __SHOOTINGGAMEDELEGATE_H__

class ShootingGameDelegate : public Core::EngineAppDelegate {
public:
	ShootingGameDelegate();
	virtual ~ShootingGameDelegate() {}

	virtual void GameContentSize(int deviceWidth, int deviceHeight, int &width, int &height);
	virtual void ScreenMode(DeviceMode &mode);
	virtual void RegisterTypes();
	virtual void LoadResources();
	virtual void OnResourceLoaded();
	virtual void OnPostDraw();
};

#endif // !__SHOOTINGGAMEDELEGATE_H__