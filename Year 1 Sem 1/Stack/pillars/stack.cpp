#include <iostream>
#include "stack.h"
void stack_push(int a, stack *&st)
{
	stack *aux = new stack;
	aux->val = a;
	if (st == NULL) aux->next = NULL;
	else aux->next = st;
	st = aux;
}
int stack_pop(stack *&st)
{
	int x = st->val;
	st = st->next;
	return x;
}
int stack_peek(stack *st)
{
	if (st == NULL) return -1;
	int x = st->val;
	return x;
}
bool stack_empty(stack *st)
{
	if (st == NULL) return true;
	return false;
}
void print(stack *st)
{
	while (!stack_empty(st))
		std::cout << stack_pop(st) << " ";
	std::cout << "\n";
}
int search(int a, stack *st)
{
	int distance = 0;
	while (!stack_empty(st))
	{
		int x = stack_pop(st);
		if (x == a) return distance;
		distance++;
	}
	return -1;
}