#pragma once
#ifndef __Arrival__
#define __Arrival__

#include "Scene.h"
#include "Button.h"
#include "Label.h"
#include "Obstacle.h"
#include "SpaceShip.h"
#include "Target.h"

class Arrival : public Scene
{
public:
	Arrival();
	~Arrival();

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
	Label* m_pLabel;
	SpaceShip* m_pSpaceShip;
	Target* m_pTarget;
	

	// UI Items

};

#endif // !Arrival
