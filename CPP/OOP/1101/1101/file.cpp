// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#include "file.h"

File::File() : Document()
{
}

File::File(string content, string pathname) : Document(content), pathname(pathname)
{
}

void File::setPathname(string pathname)
{
	this->pathname = pathname;
}