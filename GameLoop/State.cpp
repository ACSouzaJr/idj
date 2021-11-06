#include <math.h>
#include "State.h"
#include "Components/Sound/Sound.h"
#include "Components/Face/Face.h"
#include "Components/TileMap/TileMap.h"
#include "Maths/vec2.h"
#include "TileSet.h"
#include "InputManager.h"
#include "Camera.h"

State::State() 
	: m_QuitRequested(false), m_Music(Music("assets/audio/stageState.ogg"))
{
	m_Music.Play();
	LoadAssets();
}

State::~State()
{
	m_ObjectArray.clear();
}

void State::LoadAssets()
{
	// Pre-load Assets

	// Load Background
	GameObject* background = new GameObject();
	background->AddComponent(new Sprite(*background, "assets/img/ocean.jpg"));
	m_ObjectArray.emplace_back(background);

	// Load Tiles
	GameObject* mapping = new GameObject();
	TileSet* tileSet = new TileSet(64, 64, "assets/img/tileset.png");
	TileMap* tileMap = new TileMap(*mapping, "assets/map/tileMap.txt", tileSet);
	mapping->AddComponent(tileMap);
	m_ObjectArray.emplace_back(mapping);
}

void State::Update(float dt)
{
	if (InputManager::GetInstance().QuitRequested()) {
		m_QuitRequested = true;
	}

	Camera::Update(dt);

	//printf("CAM POS: %f %f \n", Camera::m_Pos.x, Camera::m_Pos.y);


	Interaction();

	for (size_t i = 0; i < m_ObjectArray.size(); i++)
	{
		// Update Object
		m_ObjectArray[i]->Update(dt);
	}

	for (size_t i = 0; i < m_ObjectArray.size(); i++)
	{
		// If dead remove from array
		if (m_ObjectArray[i]->IsDead())
		{
			m_ObjectArray.erase(m_ObjectArray.begin() + i);
		}
	}

}

void State::Render()
{
	for (size_t i = 0; i < m_ObjectArray.size(); i++)
	{
		m_ObjectArray[i]->Render();

		if (m_ObjectArray[i]->GetComponent("TileMap"))
		{
			TileMap* tileMap = (TileMap*)m_ObjectArray[i].get();
			tileMap->RenderLayer(1, Camera::m_Pos.x, Camera::m_Pos.y);
		}
	}
}

void State::Interaction()
{
	if (InputManager::GetInstance().KeyPress(SPACE_KEY))
	{
		int mouseX, mouseY;

		mouseX = InputManager::GetInstance().GetMouseX();
		mouseY = InputManager::GetInstance().GetMouseY();

		Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
		AddObject((int)objPos.x, (int)objPos.y);
	}
}

void State::AddObject(int mouseX, int mouseY)
{
	GameObject* object = new GameObject();

	object->AddComponent(new Sprite(*object, "assets/img/penguinface.png"));

	auto w = object->m_Position.w;
	auto h = object->m_Position.h;

	object->m_Position = { mouseX + w / 2, mouseY + h / 2, w, h };

	object->AddComponent(new Sound(*object, "assets/audio/boom.wav"));
	object->AddComponent(new Face(*object));

	m_ObjectArray.emplace_back(object);
}
