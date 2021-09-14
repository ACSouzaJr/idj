#include <math.h>
#include "State.h"
#include "Components/Sound/Sound.h"
#include "Components/Face/Face.h"
#include "Maths/vec2.h"

State::State() 
	: m_QuitRequested(false), m_Music(Music("assets/audio/stageState.ogg"))
{
	// m_Background(Sprite("assets/img/ocean.jpg"))
	GameObject* go = new GameObject();
	go->AddComponent(new Sprite(*go, "assets/img/ocean.jpg"));
	m_ObjectArray.emplace_back(go);

	m_Music.Play();
}

State::~State()
{
	m_ObjectArray.clear();
}

void State::LoadAssets()
{
	// Pre-load Assets
}

void State::Update(float dt)
{
	Input();

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
	}
}

void State::Input()
{
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if (event.type == SDL_QUIT) {
			m_QuitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for (int i = m_ObjectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) m_ObjectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if (go->m_Position.Contains({ (float)mouseX, (float)mouseY })) {
					Face* face = (Face*) go->GetComponent("Face");

					if (face != nullptr) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}

		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				m_QuitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
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
