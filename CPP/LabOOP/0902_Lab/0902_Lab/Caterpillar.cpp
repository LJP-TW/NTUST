#include <algorithm>
#include "Caterpillar.h"

using namespace std;

Caterpillar::Caterpillar()
{
	body = "";
}

void Caterpillar::eat(string food)
{
	body += food;
}

void Caterpillar::pull(int n)
{
	body.erase(0, n);
}

void Caterpillar::throwOut(int n)
{
	body.erase(body.size() - n, n);
}

void Caterpillar::consume(char c)
{
	int pos;
	while ((pos = body.find(c)) != string::npos)
	{
		body.erase(pos, 1);
	}
}

void Caterpillar::sort()
{
	std::sort(body.begin(), body.end());
}

std::ostream & operator<<(std::ostream& output, const Caterpillar& c)
{
	output << "@-";
	for (int i = c.body.size() - 1; i >= 0; --i)
	{
		output << c.body[i] << "-";
	}
	output << "*";
	return output;
}
