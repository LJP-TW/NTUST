// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#ifndef EMAIL_H
#define EMAIL_H

#include "document.h"

using namespace std;

class Email : public Document
{
public:
	// Constructor
	Email();
	Email(string body, string sender, string recipient, string title);

	// Mutator
	void setSender(string sender);
	void setRecipient(string recipient);
	void setTitle(string title);

	// Accessor
	string getSender() const { return sender; };
	string getRecipient() const { return recipient; };
	string getTitle() const { return title; };

private:
	string sender;
	string recipient;
	string title;
};

#endif