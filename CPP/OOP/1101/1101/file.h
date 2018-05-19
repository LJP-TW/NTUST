// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#ifndef FILE_H
#define FILE_H

#include "document.h"

using namespace std;

class File : public Document
{
public:
	// Constructor
	File();
	File(string content, string pathname);

	// Mutator
	void setPathname(string pathname);

	// Accessor
	string getPathname() const { return pathname; };

private:
	string pathname;
};

#endif