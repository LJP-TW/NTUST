// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Simple Interactive Fiction
#include <sstream>
#include "scene.h"

using namespace std;

Scene::Scene()
{

}

Scene::Scene(std::string input)
{
	// For example:
	//	#Hello
	//	When I open my eyes, all around is wholly black.
	//	It seems that I'm in a maze.
	//	I must find the exit.
	//	- Front #1 - 1
	//	- Back #DE
	istringstream iss(input);
	string result = "", temp, line;
	optionCount = 0;

	// First, Erase first line
	getline(iss, line);

	// Second, handle options
	// - Front #1 - 1
	// will ...
	// options.push_back("1 - 1")
	// narration will be rewrited to (1) Front
	while (getline(iss, line))
	{
		if (line[0] != '-')
		{
			result += line;
			result += '\n';
		}
		else
		{
			int endPosition = line.find('#') - 1;
			temp = line.substr(1, endPosition);

			result += "(";
			result += to_string(optionCount + 1);
			result += ") ";
			result += temp;
			result += '\n';

			temp = line.substr(endPosition + 2, line.size() - 1);
			options.push_back(temp);

			++optionCount;
		}
	}

	narration = result;
}
