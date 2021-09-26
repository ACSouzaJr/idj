#include <stdio.h>
#include <SDL.h>
#include "Game.h"
#include "Components/TileMap/TileMap.h"

int main(int argc, char* argv[]) {
	Game& game = Game::GetInstance();
	game.Run();

	return 0;
}