// Name: ±i®Ñ»Ê
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: Draw Board
#include "Drawboard.h"

Drawboard::Drawboard() : board(NULL), width(0), height(0)
{
}

Drawboard::Drawboard(int width, int height) : width(width), height(height)
{
	board = new char*[height];
	for (int i = 0; i < height; ++i)
	{
		board[i] = new char[width];
	}
}

void Drawboard::rect(int ux, int uy, int dx, int dy, char c)
{
	// (ux, uy) : Right-Buttom Pos
	// (dx, dy) : Left-Top pos

	// Check coordinate is in range
	ux = ux >= width ? width - 1 : ux;
	uy = uy >= height ? height - 1 : uy;
	dx = dx < 0 ? 0 : dx;
	dy = dy < 0 ? 0 : dy;

	for (int y = dy; y <= uy; ++y)
	{
		for (int x = dx; x <= ux; ++x)
		{
			board[y][x] = c;
		}
	}
}

void Drawboard::circle(int cx, int cy, int r, char c)
{
	// (cx, cy) : Center of circle
	// (ux, uy) : Right-Buttom Pos
	// (dx, dy) : Left-Top pos

	int ux, uy, dx, dy;
	ux = cx + r;
	uy = cy + r;
	dx = cx - r;
	dy = cy - r;

	// Check coordinate is in range
	for (int y = dy; y <= uy; ++y)
	{
		for (int x = dx; x <= ux; ++x)
		{
			if (0 <= y && y < height && 0 <= x && x < width)
			{
				if ((y - cy) * (y - cy) + (x - cx) * (x - cx) <= r * r)
				{
					board[y][x] = c;
				}
			}
		}
	}
}

std::ostream& operator<<(std::ostream& output, const Drawboard& drawboard)
{
	for (int y = 0; y < drawboard.height; ++y)
	{
		for (int x = 0; x < drawboard.width; ++x)
		{
			output << (char)drawboard.board[y][x];
		}
		output << std::endl;
	}
	return output;
}