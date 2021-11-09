#include "Camera.h"
#include "InputManager.h"

GameObject* Camera::m_Focus = nullptr;
Vec2 Camera::m_Speed = Vec2(0, 0);
Vec2 Camera::m_Pos = Vec2(0, 0);

void Camera::Follow(GameObject* newFocus)
{
	m_Focus = newFocus;
}

void Camera::Unfollow()
{
	m_Focus = nullptr;
}

void Camera::Update(float dt)
{
	if (m_Focus)
	{
		// Stay centralized on screen
		 int xCenter = (m_Focus->m_Position.x + m_Focus->m_Position.w) / 2;
		 int yCenter = (m_Focus->m_Position.y + m_Focus->m_Position.h) / 2;

		 m_Pos = Vec2(xCenter, yCenter);
	}
	else 
	{
		InputManager& input = InputManager::GetInstance();

		int velocityX = input.IsKeyDown(RIGHT_ARROW_KEY) - input.IsKeyDown(LEFT_ARROW_KEY);
		int velocityY = input.IsKeyDown(DOWN_ARROW_KEY) - input.IsKeyDown(UP_ARROW_KEY);
		printf("velocityX %d \n", velocityX);
		printf("velocityY %d \n", velocityY);


		m_Speed = Vec2(100 * velocityX * dt, 100 * velocityY * dt);

		m_Pos = m_Pos + m_Speed;
	}
}
