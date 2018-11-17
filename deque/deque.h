#pragma once
struct dequenode
{
	int val;
	dequenode *next;
	dequenode *prev;
};
struct deque
{
	dequenode *first;
	dequenode *last;
	dequenode *mid;
};
void deque_init(deque &q);
void deque_add_front(deque &q, int x);
void deque_add_back(deque &q, int x);
void deque_print(deque q);
int deque_pop_front(deque &q);
int deque_pop_back(deque &q);

