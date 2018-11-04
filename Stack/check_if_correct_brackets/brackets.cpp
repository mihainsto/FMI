#include <iostream>
#include <fstream>

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
		std::cout << pop(st) << " ";
	std::cout << "\n";
}
int search(int a, stack *st)
{
	int distance = 0;
	while (!empty(st))
	{
		int x = pop(st);
		if (x == a) return distance;
		distance++;
	}
	return -1;
}

int char_to_int(char c)
{
	if (c == '(') return 1;
	else return 0;
}
int main()
{	
	std::ifstream fin("brackets.txt");
	stack *st;
	char c;
	int o, poz = 0;
	st = NULL;

	fin >> c;
	o = char_to_int(c);
	if (o == 0)
	{
		std::cout << "Incorrect brackets - position 0 ";
		system("pause");
		return 0;
	}
	else
		push(1, st);

	while(fin>>c)
	{
		o = char_to_int(c); poz++;
		if(o == 0 && empty(st))
		{
			std::cout << "Incorrect brackets - position "<<poz;
			system("pause");
			return 0;
		}
		if (o == 1) push(1, st);
		else if (o == 0) pop(st);
	}

	if(empty(st)) std::cout << "Correct brackets ";
	else std::cout << "Incorrect brackets "<< poz;

	system("pause");
	return 0;
}