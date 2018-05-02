// Name: ±i®Ñ»Ê
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: Draw Board
#include <iostream>
#include <string>
#include "Drawboard.h"

using namespace std;

int main()
{
	int W, H;
	string cmd;

	cin >> W >> H;
	Drawboard drawboard(W, H);

	while (cin >> cmd)
	{
		// Draw Rect
		if (cmd == "RECT")
		{
			int ux, uy, dx, dy;
			char c;
			cin >> ux >> uy >> dx >> dy >> c;

			drawboard.rect(ux, uy, dx, dy, c);
		}
		// Draw CIRCLE
		else if (cmd == "CIRCLE")
		{
			int cx, cy, r;
			char c;
			cin >> cx >> cy >> r >> c;

			drawboard.circle(cx, cy, r, c);
		}
		else if (cmd == "DRAW")
		{
			cout << drawboard;
		}
	}

	return 0;
}