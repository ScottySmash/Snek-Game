#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);	
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GridW() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GridH() - 1);

	Location NewLoc;
	do
	{
		NewLoc.x = xDist(rng);
		NewLoc.y = yDist(rng);

	} while (snake.IsInSnake(NewLoc));
	loc = { NewLoc.x, NewLoc.y };
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
