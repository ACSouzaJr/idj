#include "Game.h"
#include <SDL_image.h>
#include <SDL_mixer.h>

Game* Game::s_Instance = nullptr;

Game::Game(const char* title, int width, int height) 
    :  m_Window(nullptr), m_Renderer(nullptr), m_State(nullptr)
{

    if (s_Instance != nullptr) {
        SDL_Log("Game already Instantiated! \n");
        // this might be a critical error...
        return;
    }

    // Assign reference to self
    s_Instance = this;

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        // In the case that SDL could be initialized...
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }

    // load support for the JPG and PNG image formats
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
        SDL_Log("IMG_Init: %s\n", IMG_GetError());
        // handle error
        return;
    }

    // load support for the OGG and MOD sample/music formats
    flags = MIX_INIT_OGG | MIX_INIT_MOD;
    initted = Mix_Init(flags);
    if ((initted & flags) != flags) {
        SDL_Log("Mix_Init: Failed to init required ogg and mod support!\n");
        SDL_Log("Mix_Init: %s\n", Mix_GetError());
        // handle error
        return;
    }

    // open 22.05KHz, signed 16bit, system byte order,
    //      stereo audio, using 1024 byte chunks
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        SDL_Log("Mix_OpenAudio: %s\n", Mix_GetError());
        return;
        //exit(2);
    }

    // Create an application window 
    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    // Check that the window was successfully created
    if (m_Window == nullptr) {
        // In the case that the window could not be made...
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return;
    }

    // Create an application renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    // Check that the renderer was successfully created
    if (m_Renderer == nullptr) {
        // In the case that the renderer could not be made...
        SDL_Log("Could not create renderer: %s\n", SDL_GetError());
        return;
    }

    // Initialize state
    m_State = new State();
}

Game::~Game()
{
    delete m_State;

    // Close and destroy Audio
    Mix_CloseAudio();
    Mix_Quit();

    // Close Image
    IMG_Quit();

    // Close and destroy the renderer
    SDL_DestroyRenderer(m_Renderer);
    // Close and destroy the window
    SDL_DestroyWindow(m_Window);
    // Clean up
    SDL_Quit();
}

Game& Game::GetInstance()
{
    // Singleton:
    // Instance only once if not already Instantiated
    if (s_Instance == nullptr) {
        new Game("Antonio-160112745", 1024, 600);
    }

    return *s_Instance;
}

void Game::Run()
{
    while (!m_State->QuitRequested())
    {
        // Load State (screen)
        // Read inputs
        // Update State
        m_State->Update(0);
        // Draw State
        m_State->Render();

        // Render State
        SDL_RenderPresent(m_Renderer);
        SDL_Delay(33);
    }
}
