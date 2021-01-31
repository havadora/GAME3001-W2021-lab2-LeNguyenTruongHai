#pragma once
#ifndef __BLANKING_SCENE__
#define __BLANKING_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Button.h"

class Blanking final : public Scene
{
public:
	Blanking();
	~Blanking();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	Label* m_pAvoid{};
	Label* m_pInstructionsLabel{};
	Label* m_pStudentID{};
	Ship* m_pShip{};

	Button* m_pStartButton;
};

#endif /* defined (__START_SCENE__) */
