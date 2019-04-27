#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location & loc, Color c);
	int GridW() const;
	int GridH() const;
	int GridDim() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	// cached graphcis for performance/convenience
	Graphics& gfx;
	// board square size: dimmension x dimension
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
};