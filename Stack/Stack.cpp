#include <iostream>
struct stack
{
	int val;
	stack *next;
};
void push(int a, stack *&st)
{
	stack *aux = new stack;
	aux->val = a;	
	if (st == NULL) aux->next = NULL;
	else aux->next = st;
	st = aux;
}
int pop(stack *&st)
{
	int x = st->val;
	st = st->next;
	return x;
}
int peek(stack *st)
{
	int x = st->val;
	return x;
}
bool empty(stack *st)
{
	if (st == NULL) return true;
	return false;
}
void print(stack *st)
{
	while (!empty(st))
		std::cout << pop(st) <<" ";
	std::cout << "\n";
}
int search(int a, stack *st)
{
	int distance = 0;
	while(!empty(st))
	{
		int x = pop(st);
		if (x == a) return distance;
		distance++;
	}
	return -1;
}
int main()
{
	stack *st;
	st = NULL;
	push(6, st); push(14, st); push(4, st); push(3, st);
	print(st);
	std::cout << "searching 14 " << search(14, st) << "\n";
	std::cout << "searching 13 " << search(13, st) << "\n";
	pop(st); pop(st);

	std::cout << pop(st) <<"\n";
	std::cout << peek(st)<<"\n";
	system("pause");

}