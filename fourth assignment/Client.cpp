#include <iostream>
#include <cstring>
#include "Client.h"

Client::Client() : fname(""), lname(""), email(""), passwd("")
{}

Client::Client(string &fname, string &lname, string &email, string &passwd) :
	fname(fname), lname(lname), email(email), passwd(passwd)
	{}

Client::Client(Client const &c)
{
	fname = c.fname;
	lname = c.lname;
	email = c.email;
	passwd = c.passwd;
}

void Client::setEmail(const string& e)
{
	email = e;
}
void Client::setFname(const string& f)
{
	fname = f;
}
void Client::setLname(const string& l)
{
	lname = l;
}
void Client::setPasswd(const string& p)
 {
	passwd = p;
}

string Client::getEmail() const
{
	return email;
}
string Client::getFname() const
{
	return fname;
}
string Client::getLname() const
{
	return lname;
}
string Client::getPasswd() const
{
	return passwd;
}

bool Client::verifyPasswd(string passwd)
{
	if(passwd == this -> passwd) return true;
	return false;
}

istream &operator>>(istream &stream, Client &c)
{
	return stream;
}
