#include "homework.h"
#include <string>

homework::homework(): name(""), assigned_date(), due_date() {}

homework::homework(string name, date assigned_date, date due_date):
    name(name), assigned_date(assigned_date), due_date(due_date){}

int homework::compareTo(homework another_homework)
{
	return(this->due_date.compareTo(another_homework.due_date));
}

ostream &operator<< (ostream &stream, homework h)
{
	stream << h.name << ":" << h.assigned_date << "-" << h.due_date;
	return stream;
}
