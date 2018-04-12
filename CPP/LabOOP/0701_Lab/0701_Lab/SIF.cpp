// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Simple Interactive Fiction
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include "scene.h"

using namespace std;

int main() {
	map<string, Scene> scenes;
	ifstream in("script.txt"); // data file
	string str(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); // read file into string
	istringstream iss(str);
	string narration, temp;
	Scene nowScene;

	// Handling Scenes
	narration = "";
	while (getline(iss, temp))
	{
		// every scene is split by empty string ""
		if (temp == "")
		{
			// Insert to scenes
			string sceneName = narration.substr(1, narration.find('\n') - 1);
			scenes[sceneName] = Scene(narration);
			narration = "";
		}
		else
		{
			narration += temp;
			narration += '\n';
		}
	}

	// Main Game Loop
	nowScene = scenes["0"];
	while (cout << nowScene.narration && nowScene.optionCount != 0)
	{
		unsigned int choice;
		cin >> choice;
		nowScene = scenes[nowScene.options[choice - 1]];
	}

	system("pause");
	return 0;
}