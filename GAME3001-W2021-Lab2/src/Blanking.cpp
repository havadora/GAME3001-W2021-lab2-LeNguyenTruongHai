#include "Blanking.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

Blanking::Blanking()
{
	Blanking::start();
}

Blanking::~Blanking()
= default;

void Blanking::draw()
{
	drawDisplayList();
}

void Blanking::update()
{
	updateDisplayList();
}

void Blanking::clean()
{
	removeAllChildren();
}

void Blanking::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		TheGame::Instance()->changeSceneState(ARRIVAL);
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_3))
	{
		TheGame::Instance()->changeSceneState(SEEkING);
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_4))
	{
		TheGame::Instance()->changeSceneState(FLEEING);
	}

}

void Blanking::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 100, 100 };
	m_pAvoid = new Label("Press 1: Avoidence", "Consolas", 20, blue, glm::vec2(100.0f, 40.0f));
	m_pAvoid->setParent(this);
	addChild(m_pAvoid);

	m_pArrival = new Label("Press 2: Arrival", "Consolas", 20, red, glm::vec2(300.0f, 40.0f));
	m_pArrival->setParent(this);
	addChild(m_pArrival);


}
