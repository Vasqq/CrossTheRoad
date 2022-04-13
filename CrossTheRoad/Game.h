#pragma once
#include "Player.h"
#include "Lane.h"

#include <iostream>
#include <vector>

using namespace std;


class Game
{
private:
	
	bool flag;
	bool quit;
	int numOfLanes;
	int difficulty;
	int width;
	int score;
	Player *player;
	vector<Lane*> map;


public:
	Game(int width, int height);
	Game();
	~Game();

	void draw();
	void input();
	void logic();
	void run();
	void print();

};

