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
	const SDL_Color red = { 0, 0, 100, 100 };
	m_pStartLabel = new Label("LeNguyenTruongHai", "Consolas", 80, blue, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pStudentID = new Label("101268689", "Consolas", 60, red, glm::vec2(400.0f, 120.0f));
	m_pStudentID->setParent(this);
	addChild(m_pStudentID);
}
