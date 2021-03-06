#include "Arrival.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"
Arrival::Arrival()
{
	Arrival::start();
}

Arrival::~Arrival()
= default;

void Arrival::draw()
{
	if (EventManager::Instance().isIMGUIActive())
	{
		GUI_Function();
	}

	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void Arrival::update()
{
	updateDisplayList();
	m_pSpaceShip->m_ArrivalMove();
}

void Arrival::clean()
{
	removeAllChildren();
}

void Arrival::handleEvents()
{
	
	EventManager::Instance().update();
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_4))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
	
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(SEEkING);
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		TheGame::Instance()->changeSceneState(FLEEING);
	}


}

void Arrival::start()
{
	
	// Set GUI Title
	m_guiTitle = "Play Scene";
	const SDL_Color blue = { 0, 0, 0, 255 };
	m_pLabel = new Label("Arrival", "Consolas", 20, blue, glm::vec2(400.0f, 40.0f));
	m_pLabel->setParent(this);
	addChild(m_pLabel);

	m_pTarget = new Target();
	m_pTarget->getTransform()->position = glm::vec2(700.0f, 500.0f);
	addChild(m_pTarget);

	

	// instantiating spaceship
	m_pSpaceShip = new SpaceShip();
	m_pSpaceShip->getTransform()->position = glm::vec2(50.0f, 100.0f);
	m_pSpaceShip->setEnabled(true);
	m_pSpaceShip->setDestination(m_pTarget->getTransform()->position);
	addChild(m_pSpaceShip);
}

void Arrival::GUI_Function() const
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();

	ImGui::Begin("GAME3001 - Lab 2", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);

	static float speed = 10.0f;
	if (ImGui::SliderFloat("MaxSpeed", &speed, 0.0f, 100.0f))
	{
		m_pSpaceShip->setMaxSpeed(speed);
	}

	static float angleInRadians = m_pSpaceShip->getRotation();
	if (ImGui::SliderAngle("Orientation Angle", &angleInRadians))
	{
		m_pSpaceShip->setRotation(angleInRadians * Util::Rad2Deg);
	}

	if (ImGui::Button("Start"))
	{
		m_pSpaceShip->setEnabled(true);
	}

	ImGui::SameLine();

	if (ImGui::Button("Reset"))
	{
		m_pSpaceShip->getTransform()->position = glm::vec2(100.0f, 100.0f);
		m_pSpaceShip->setEnabled(false);
	}

	ImGui::Separator();

	static float targetPosition[2] = { m_pTarget->getTransform()->position.x, m_pTarget->getTransform()->position.y };
	if (ImGui::SliderFloat2("Target", targetPosition, 0.0f, 800.0f))
	{
		m_pTarget->getTransform()->position = glm::vec2(targetPosition[0], targetPosition[1]);
		m_pSpaceShip->setDestination(m_pTarget->getTransform()->position);
	}

	ImGui::End();

	// Don't Remove this
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	ImGui::StyleColorsDark();
}
