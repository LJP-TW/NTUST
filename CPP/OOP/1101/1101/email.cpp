// Name: ±i®Ñ»Ê B10615025
// Date: May. 17, 2018
// Last Update: May. 17, 2018
// Problem statement: Document
#include "email.h"

Email::Email() : Document(), sender(""), recipient(""), title("")
{
}

Email::Email(string body, string sender, string recipient, string title) : Document(body), sender(sender), recipient(recipient), title(title)
{
}

void Email::setSender(string sender)
{
	this->sender = sender;
}

void Email::setRecipient(string recipient)
{
	this->recipient = recipient;
}

void Email::setTitle(string title)
{
	this->title = title;
}