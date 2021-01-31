
#pragma once
#ifndef __Seeking__
#define __Seeking__

#include "Scene.h"
#include "Button.h"
#include "Label.h"
#include "Obstacle.h"
#include "SpaceShip.h"
#include "Target.h"

class Seeking : public Scene
{
public:
	Seeking();
	~Seeking();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	// IMGUI Function
	void GUI_Function() const;
	std::string m_guiTitle;

	glm::vec2 m_mousePosition;
	
	SpaceShip* m_pSpaceShip;
	Target* m_pTarget;


	// UI Items

};

#endif // !Arrival