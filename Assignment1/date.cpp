#include "date.h"

date::date(): year(0), month(0), day(0){}

date::date(int day, int month, int year):
    day(day), month(month), year(year){}

int date::compareTo(date another_date)
{
	if(year!=another_date.year)
		return year - another_date.year;
	else if(month!=another_date.month)
		return month - another_date.month;
	else if(day!=another_date.day)
		return day - another_date.day;
	else
		return 0;
}

ostream &operator<< (ostream &stream, date d)
{
	stream << d.month << "/" << d.day << "/" << d.year;
	return stream;
}
