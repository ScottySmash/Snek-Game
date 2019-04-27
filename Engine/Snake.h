#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc_in);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInSnakeExceptLastSegment(const Location& target) const;
	bool IsInSnake(const Location& target) const;

private: // not necessary but visual break
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nMaxSegments = 100;
	Segment segments[nMaxSegments];
	int nSegments = 1; //size of current snek
};