// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#include "document.h"

Document::Document() : text("")
{
}

Document::Document(string text) : text(text)
{
}

void Document::setText(string text)
{
	this->text = text;
}
