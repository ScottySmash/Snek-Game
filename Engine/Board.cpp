#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx_in)
	:
	gfx (gfx_in)
{}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::GridW() const
{
	return width;
}

int Board::GridH() const
{
	return height;
}

int Board::GridDim() const
{
	return dimension;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return (loc.x >= 0 && loc.x < width 
		&& loc.y >= 0 && loc.y < height);
}


