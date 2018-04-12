// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Simple Interactive Fiction
#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

class Scene
{
public:
	// Constructor
	Scene();
	Scene(std::string);

	// For example:
	//	#Hello
	//	When I open my eyes, all around is wholly black.
	//	It seems that I'm in a maze.
	//	I must find the exit.
	//	- Front #1 - 1
	//	- Back #DE
	//
	// narration = "When I ...... \nIt seems.... \n ....."
	// options[0] = "1 - 1"
	// options[1] = "DE"
	// optionCount = 2;
	std::string narration;
	std::vector<std::string> options;
	unsigned int optionCount;

};

#endif