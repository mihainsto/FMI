#include <iostream>
struct stack
{
	int val;
	stack *next;
};
void stack_push(int a, stack *&st);
int stack_pop(stack *&st);
int stack_peek(stack *st);
bool stack_empty(stack *st);
void print(stack *st);
int search(int a, stack *st);