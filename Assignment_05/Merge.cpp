#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next; 
};
class list
{
	struct node *findmerge;
public:
	void build(); 
	void display();   
	void Merge(list, list);
};
int main(){
	list n, m,finallist;
	n.build();
	m.build();
	finallist.Merge(n, m);
	finallist.display();
	
	getchar();
	getchar();
	return 0;
}


void list::build()
{
	struct node *nxt, *pre_node;
	int value, num, i;
	findmerge= nxt = pre_node = NULL;
	cin >> num;
	for (i = 1; i <= num; i++){
		cin >> value;
		nxt = new node;
		nxt->data = value;
		nxt->next = NULL;
		if (findmerge == NULL)
			findmerge = nxt;
		else
			pre_node->next = nxt;
		pre_node = nxt;
	}

}

void list::display()
{
	struct node *ptr = findmerge;
	while (ptr != NULL)
	{
		cout << ptr->data<<"\n";
		ptr = ptr->next;
	}
}
void list::Merge(list n, list m)
{
	struct node *nxt, *pre_node, *pptr, *qptr;
	int dat;
	pptr = n.findmerge;
	qptr = m.findmerge;
	findmerge = nxt = pre_node = NULL;
	while (pptr != NULL && qptr != NULL)
	{
		if (pptr->data <= qptr->data)
		{
			dat = pptr->data;
			pptr = pptr->next;
		}
		else
		{
			dat = qptr->data;
			qptr = qptr->next;
		}
		nxt = new node;
		nxt->data = dat;
		nxt->next = NULL;
		if (findmerge == NULL)
			findmerge= nxt;
		else
			pre_node->next = nxt;
		pre_node = nxt;
	}
	if (pptr == NULL)
	{
		while (qptr != NULL)
		{
			nxt = new node;
			nxt->data = qptr->data;
			nxt->next = NULL;
			if (findmerge == NULL)
				findmerge = nxt;
			else
				pre_node->next = nxt;
			pre_node = nxt;
			qptr = qptr->next;
		}
	}
	else if (qptr == NULL)
	{
		while (pptr != NULL)
		{
			nxt = new node;
			nxt->data = pptr->data;
			nxt->next = NULL;
			if (findmerge == NULL)
				findmerge= nxt;
			else
				pre_node->next = nxt;
			pre_node = nxt;
			pptr = pptr->next;
		}
	}
	cout << "\n\n";
	return;
}
