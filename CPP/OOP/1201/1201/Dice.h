// Name: 張書銘 B10615025
// Date: 2018/5/27 下午 08:22:54
// Last Update: 2018/5/27 下午 08:22:54
// Problem statement: Dice
#ifndef DICE_H
#define DICE_H

class Dice
{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;
protected:
	int numSides;
};

int rollTwoDice(const Dice& die1, const Dice& die2);

#endif