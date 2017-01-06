#include "stdafx.h"
#include "ShootingGameDelegate.h"
#include "GameWidget.h"

enum {
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 768
};

ShootingGameDelegate::ShootingGameDelegate() {}

void ShootingGameDelegate::GameContentSize(int deviceWidth, int deviceHeight, int & width, int & height) {
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
}

void ShootingGameDelegate::ScreenMode(DeviceMode &mode) {
	mode = DeviceMode::Windowed;
}

void ShootingGameDelegate::RegisterTypes()
{
	REGISTER_WIDGET_XML(GameWidget, "GameWidget");
}

void ShootingGameDelegate::LoadResources() {
	Core::LuaExecuteStartupScript("m_start.lua");
}

void ShootingGameDelegate::OnResourceLoaded() {
	if (Core::appInstance->AllResourcesLoaded()) {
		Core::appInstance->SetLoaded();
	}
}

void ShootingGameDelegate::OnPostDraw() {
	if (!Render::isFontLoaded("arial")) {
		return;
	}

	//
	// Перед вызовом метода Render::PrintString() нужно привязать нужный шрифт
	//
	Render::BindFont("arial");

	int dy = Render::getFontHeight();
	int x = Render::device.Width() - 5;
	int y = Render::device.Height() - 20;

	Render::PrintString(x, y, std::string("FPS: ") + utils::lexical_cast(Core::appInstance->GetCurrentFps()), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Video: ") + utils::lexical_cast(Render::device.GetVideoMemUsage() / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Audio: ") + utils::lexical_cast(Core::resourceManager.GetMemoryInUse<MM::AudioResource>() / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Animations: ") + utils::lexical_cast((Core::resourceManager.GetMemoryInUse<Render::StreamingAnimation>() + Core::resourceManager.GetMemoryInUse<Render::Animation>()) / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Textures: ") + utils::lexical_cast(Core::resourceManager.GetMemoryInUse<Render::Texture>() / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Particles: ") + utils::lexical_cast(Core::resourceManager.GetMemoryInUse<ParticleEffect>() / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
	Render::PrintString(x, y -= dy, std::string("Models: ") + utils::lexical_cast(Core::resourceManager.GetMemoryInUse<Render::ModelAnimation>() / 1024) + std::string("K"), 1.0f, RightAlign, BottomAlign);
}