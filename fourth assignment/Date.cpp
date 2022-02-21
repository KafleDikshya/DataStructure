#include <iostream>
#include <cstring>
#include "Date.h"

Date::Date(): month(0), day(0), year(0), hour(0), minute(0), second(0) {}
Date::Date(int month, int day, int year, int hour, int minute, int second):
    month(month), day(day), year(year), hour(hour), minute(minute), second(second) {}

void Date::setDay(int& d)
{
	day = d;
}
void Date::setHour(int& h)
{
	hour = h;
}
void Date::setMinute(int& min)
{
	minute = min;
}
void Date::setMonth(int& m)
{
	month = m;
}
void Date::setSecond(int& s)
{
	second = s;
}
void Date::setYear(int& y)
{
	year = y;
}

int Date::getDay() const
{
	return day;
}
int Date::getHour() const
{
	return hour;
}
int Date::getMinute() const
{
	return minute;
}
int Date::getMonth() const
{
	return month;
}
int Date::getSecond() const
{
	return second;
}
int Date::getYear() const
{
	return year;
}

bool Date::operator== (const Date &rhs)
{
	if(month == rhs.getMonth() && day == rhs.getDay() && year == rhs.getYear() && hour == rhs.getHour() && minute == rhs.getMinute() && second == rhs.getSecond())
	    return true;
	return false;
}
bool Date::operator< (const Date &rhs)
{
	if(rhs.getYear() < year) return true;
	if(rhs.getYear() > year) return false;
	if(rhs.getMonth() < month) return true;
	if(rhs.getMonth() > month) return false;
	if(rhs.getDay() < day) return true;
	if(rhs.getDay() > day) return false;
	if(rhs.getHour() < hour) return true;
	if(rhs.getHour() > hour) return false;
	if(rhs.getMinute() < minute) return true;
	if(rhs.getMinute() > minute) return false;
	if(rhs.getSecond() < second) return true;
	return false;
}

ostream &operator<< (ostream& stream, const Date& date)
{
	stream << date.getMonth() << '/' << date.getDay() << '/' << date.getYear() << ' ' << date.getHour() << ':' << date.getMinute() << ':' << date.getSecond();
	return stream;
}
istream &operator>> (istream& stream, Date& date)
{
	char t[10];
	stream.getline(t, 4, '/');
	int temp = 0;
	int len = strlen(t);

	for(int i = 0; i < len; i++)
        {
		temp = temp * 10 + t[i];
	    }
	date.setMonth(temp);
	stream.getline(t, 4, '/');
	temp = 0;
	len = strlen(t);
	for(int i = 0; i < len; i++)
        {
		temp = temp * 10 + t[i];
        }
	date.setDay(temp);
	stream.getline(t, 5, ' ');
	temp = 0;
	len = strlen(t);
	for(int i = 0; i < len; i++)
	{
		temp = temp * 10 + t[i];
	}
	date.setYear(temp);
	stream.getline(t, 4, ':');
	temp = 0;
	len = strlen(t);
	for(int i = 0; i < len; i++)
	{
		temp = temp * 10 + t[i];
	}
	date.setHour(temp);
	stream.getline(t, 4, ':');
	temp = 0;
	len = strlen(t);
	for(int i = 0; i < len; i++)
	 {
		temp = temp * 10 + t[i];
	}
	date.setMinute(temp);
	stream.getline(t, 4, '\n');
	temp = 0;
	for(int i = 0; i < len; i++)
	{
		temp = temp * 10 + t[i];
	}
	date.setSecond(temp);
	return stream;
}
