#include "Game.h"
#include "Lane.h"
#include "Player.h"
#include <conio.h>

// Initialize game settings
Game::Game(int width, int height)
{
	this->width = width;
	numOfLanes = height;
	score = 0;
	quit = false;

	for (int i = 0; i < numOfLanes; i++) 
		map.push_back(new Lane(width));
	player = new Player(width);

}
// Default constructor
Game::Game() 
{
	flag = 1;
	score = 0;
	quit = false;

	std::cout << "### A game where you must cross the road to continue playing ###" << std::endl << std::endl;
	std::cout << "Press S to move forwad, W to move backward, A to move left and D to move right" << std::endl;

	std::cout << std::endl;

	std::cout << "- Choose your difficulty -" << std::endl;
	std::cout << "- Press 1 for EASY -" << std::endl;
	std::cout << "- Press 2 for NORMAL -" << std::endl;
	std::cout << "- Press 3 for HARD -" << std::endl;
	std::cin >> difficulty;

	if (difficulty == 1 || difficulty == 2 || difficulty == 3)
	{
		flag = 0;
	}

	while (flag)
	{
		std::cout << "Enter a value that is either 1,2 or 3"  << std::endl;
		std::cin >> difficulty;

		if (difficulty == 1 || difficulty == 2 || difficulty == 3)
			break;
	}
	
	
	switch (difficulty)
	{
		case 1: this->width = 25; numOfLanes = 5;
				break;
		case 2: this->width = 25; numOfLanes = 10;
				break;
		case 3: this->width = 25; numOfLanes = 15;
				break;
	}

	for (int i = 0; i < numOfLanes; i++)
		map.push_back(new Lane(width));
	player = new Player(width);
}

Game::~Game()
{
	// Destructor to dynamically release memory
	delete player;

	for (int i = 0; i < map.size(); i++)
	{
		Lane* current = map.back();
		map.pop_back();
		delete current;
	}
}

void Game::draw()
{
	// Clear the window
	system("cls");

	// Game map is a matrix of numOflanes (rows) and width (columns)
	for (int i = 0; i < numOfLanes; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((j == 0 || j == width - 1))std::cout << "|";
			


			// Print # if there is a car there
			if (map[i]->checkPosition(j) && i != 0 && i != numOfLanes - 1)
				std::cout << "#";

			// Prints the player
			else if (player->x == j && player->y == i)
				std::cout << "v";
			else
				std::cout << " ";

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Score: " << score << std::endl;

	std::cout << std::endl;
	std::cout << "Press Q to quit" << std::endl;
}

void Game::input()
{

	// Get user input
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'a')
			player->x--;
		if (current == 'd')
			player->x++;
		if (current == 'w')
			player->y--;
		if (current == 's')
			player->y++;
		if (current == 'q')
		{
			quit = true; 
			print();
		}
	}

}

void Game::logic()
{
	// Iterate through all the lanes
	for (int i = 1; i < numOfLanes - 1; i++)
	{
		// Move the cars from left to right simulating cars moving along a road
		if (rand() % 10 == 1)
		{
			map[i]->move();
		}
		// If players x coordinate is the same postion as the car and 
		// players y position is same as the char position
		// quit game
		if (map[i]->checkPosition(player->x) && player->y == i)
		{
			quit = true; 
			print();
		}
	}

	if(player->y == numOfLanes - 1)
	{
		score++;
		player->y = 0;

		// Play sound
		cout << "\x07";
	}

}

void Game::run()
{
	while (!quit)
	{
		input();
		draw();
		logic();
	}

}

void Game::print()
{
	std::cout << "-------- GAME OVER ! --------";
}
