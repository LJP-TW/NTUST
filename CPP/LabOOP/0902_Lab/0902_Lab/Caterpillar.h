#ifndef CATERPILLAR_H
#define CATERPILLAR_H

#include <ostream>
#include <string>

class Caterpillar
{
public:
	Caterpillar();

	void eat(std::string);
	void pull(int);
	void throwOut(int);
	void consume(char);
	void sort();

	friend std::ostream& operator<<(std::ostream&, const Caterpillar&);

private:
	std::string body;
};

#endif