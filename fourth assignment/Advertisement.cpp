#include <iostream>
#include "Advertisement.h"

Advertisement::Advertisement() :
    number(-1), title(""), seller_email(""), body(""), start(0, 0, 0, 0, 0, 0), close(0, 0, 0, 0, 0, 0), quantity(0)
    {}

Advertisement::Advertisement (string title, string seller_email, string body, Date start, Date close, int quantity) :
    number(-1), title(title), seller_email(seller_email), body(body), start(start), close(close), quantity(quantity)
    {}

Advertisement::Advertisement(const Advertisement &a)
{
	number = a.number;
	title = a.title;
	seller_email = a.seller_email;
	body = a.body;
	start = a.start;
	close = a.close;
	quantity = a.quantity;
}

void Advertisement::setBody(string b)
{
	body = b;
}

void Advertisement::setClose(const Date &c)
{
	close = c;
}

void Advertisement::setStart(const Date &s)
{
	start = s;
}

void Advertisement::setEmail(string e)
{
	seller_email = e;
}

void Advertisement::setNumber(int n)
{
	number = n;
}

void Advertisement::setQuantity(int q)
{
	quantity = q;
}

void Advertisement::setTitle(string t)
{
	title = t;
}

Date Advertisement::getStart() const
{
	return start;
}

Date Advertisement::getClose() const
{
	return close;
}

string Advertisement::getTitle() const
{
	return title;
}

string Advertisement::getBody() const
{
	return body;
}

string Advertisement::getEmail() const
{
	return seller_email;
}

int Advertisement::getNumber() const
{
	return number;
}

int Advertisement::getQuantity() const
{
	return quantity;
}

bool Advertisement::operator==(const Advertisement& a) const
{
	if(number == a.number) return true;
	return false;
}

istream &operator>>(istream &stream, Advertisement &a)
{
	return stream;
}
