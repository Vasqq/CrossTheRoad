#include "Lane.h"

Lane::Lane(int width)
{
	// Initialize cars at the begining of the game in the lane
	for (int i = 0; i < width; i++)
		cars.push_front(true);

	// Generate either 0 or 1
	right = rand() % 2;
}

void Lane::move()
{
	// Make cars move from left to right
	if (right)
	{
		if (rand() % 10 == 1)
			// Adds a car to the front of the deque
			cars.push_front(true);
		else
			// Don't add a car to the front of the deck
			cars.push_front(false);
		cars.pop_back();

	}

	// Make cars move from right to left
	else
	{
		if (rand() % 10 == 1)
			// Adds a car to the front of the deque
			cars.push_back(true);
		else
			// Don't add a car to the front of the deque
			cars.push_back(false);
		cars.pop_front();
	}

	
}

bool Lane::checkPosition(int pos) { return cars[pos]; }
