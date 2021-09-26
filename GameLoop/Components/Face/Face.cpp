#include "Face.h"
#include "../Sound/Sound.h"

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
