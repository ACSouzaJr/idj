#include "CameraFollower.h"
#include "../../Camera.h"
#include "../../Maths/Rect.h"

CameraFollower::CameraFollower(GameObject& go)
	:Component(go)
{
}

void CameraFollower::Update(float dt)
{
	m_Associated.m_Position.x = Camera::m_Pos.x;
	m_Associated.m_Position.y = Camera::m_Pos.y;
}
