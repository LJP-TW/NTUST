#ifndef DOCUMENT_H
// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#define DOCUMENT_H

#include <iostream>
#include <string>

using namespace std;

class Document 
{
public:
	// Constructor
	Document();
	Document(string);
	
	// Mutator
	void setText(string text);

	// Accessor
	string getText() const { return text; };

protected:
	string text;
};

#endif