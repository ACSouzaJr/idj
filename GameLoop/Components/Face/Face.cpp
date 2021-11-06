#include "Face.h"
#include "../Sound/Sound.h"
#include "../../InputManager.h"

Face::Face(GameObject& associated)
	: Component(associated), m_Hitpoints(30)
{
}

void Face::Damage(int damage)
{
	m_Hitpoints -= damage;

	if (m_Hitpoints <= 0)
	{
		m_Associated.RequestDelete();

		Sound *sound = (Sound*) m_Associated.GetComponent("Sound");
		if (sound) {
			sound->Play();
		}
	}
}

void Face::Update(float dt)
{
	
	if (InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON))
	{
		int mouseX, mouseY;

		mouseX = InputManager::GetInstance().GetMouseX();
		mouseY = InputManager::GetInstance().GetMouseY();

		if (m_Associated.m_Position.Contains({ (float)mouseX, (float)mouseY })) {
			Damage(std::rand() % 10 + 10);
		}
	}
}
