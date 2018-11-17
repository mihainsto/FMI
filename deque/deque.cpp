#include <iostream>
#include <windows.h>
#include "deque.h"

void deque_init(deque &q)
{
	q.first = q.last = q.mid = NULL;
}
void deque_add_front(deque &q, int x)
{
	dequenode *aux = new dequenode;
	aux->val = x; aux->next = NULL; aux->prev = NULL;

	if(q.first == NULL && q.mid == NULL)
	{
		q.first = q.mid = aux;
	}
	else
	if(q.first == NULL)
	{
		aux->next = q.mid;
		q.first = aux;
	}
	else
	{
		aux->next = q.mid->next;
		aux->prev = q.mid;
		q.mid->next = aux;
		q.mid = aux;
	}
}
void deque_add_back(deque &q, int x)
{
	dequenode *aux = new dequenode();
	aux->next = aux->prev = NULL;
	aux->val = x;

	if(q.mid == NULL && q.last == NULL)
	{
		q.mid = q.last = aux;
	}
	else
	if(q.last == NULL)
	{ 
		aux->prev = q.mid;
		q.mid->next = aux;
		q.last = aux;
	}
	else
	{
		aux->prev = q.mid;
		aux->next = q.mid->next;
		q.mid->next = aux;
	}

}
int deque_pop_front(deque& q)
{
	int x;
	x = q.first->val;
	q.first = q.first->next;
	return x;
}
int deque_pop_back(deque &q)
{
	int x = q.last->val;
	q.last = q.last->prev;
	q.last->next = NULL;
	return x;
}
void deque_print(deque q)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	while(q.first!=NULL)
	{
		std::cout << q.first->val<<" ";
		q.first = q.first->next;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "\n";
}
