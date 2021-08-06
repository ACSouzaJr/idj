#include "GameObject.h"

GameObject::GameObject()
	: m_Position({0, 0, 0, 0}), m_IsDead(false)
{
}

GameObject::~GameObject()
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		delete m_Components[i];
	}
	m_Components.clear();
}

void GameObject::AddComponent(Component* component)
{
	m_Components.push_back(component);
}

void GameObject::RemoveComponent(Component* component)
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i] == component) {
			m_Components.erase(m_Components.begin() + i);
			break;
		}
	}
}

Component* GameObject::GetComponent(const char* type)
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i]->IsType(type)) {
			return m_Components[i];
		}
	}
	return nullptr;
}

void GameObject::Update(float dt)
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		m_Components[i]->Update(dt);
	}
}

void GameObject::Render()
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		m_Components[i]->Render();
	}
}
