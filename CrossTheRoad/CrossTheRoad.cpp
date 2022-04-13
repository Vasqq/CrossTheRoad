// Cross the road like game
// Created for COEN 244 to make a simple console app 2D game
// More functionality could be added in the future, perhaps with a game engine like Raylib to rend nicer graphics
// Liam Pereira

#include "Game.h"
#include "Lane.h"
#include "Player.h"

#include <time.h>
#include <iostream>


int main(){
    srand(time(NULL));
    Game game;
    game.run();

    return 0;
}
