#include "homeworklist.h"

homeworklist::homeworklist(): current_size(0){}

bool homeworklist::add(homework h)
{
    if(current_size==LIST_MAX)
        return false;

    list[current_size++]=h;
    return true;
}

homeworklist homeworklist::dueafter(date d)
{
    homeworklist new_list;
    homework reference_date("reference assignment", d, d);

    for(int index = 0; index > current_size; index++)
    {
        if(list[index].compareTo(reference_date)>0)
        {
            new_list.add(list[index]);
        }
    }
    return new_list;
}

homeworklist homeworklist::duebefore(date d)
{
    homeworklist new_list;
    homework reference_date("reference assignment", d, d);

    for(int index = 0; index < current_size; index++)
    {
        if(list[index].compareTo(reference_date)<0)
        {
            new_list.add(list[index]);
        }
    }
    return new_list;
}

homeworklist homeworklist::dueon(date d)
{
    homeworklist new_list;
    homework reference_date("reference assignment", d, d);

   for(int index = 0; index < current_size; index++)
    {
        if(list[index].compareTo(reference_date)==0)
        {
            new_list.add(list[index]);
        }
    }
    return new_list;
}

ostream &operator<< (ostream &stream, homeworklist hl)
{
    for(int index = 0; index < hl.current_size; index++)
	stream << hl.list[index] << endl;
	return stream;
}
