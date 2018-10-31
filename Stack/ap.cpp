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
int main()
{
	stack *st;
	st = NULL;
	std::ifstream fin("text.txt");
	char c,cd;
	int o;
	fin >> c;
	if (c == 'a')o = 1; else o = 0;
	push(o, st);
	while(fin>>c)
	{
		if (o == 1)
		{
			if (c == 'a')cd = 1; else cd = 0;
			if (cd == 1) push(1, st);
			else
			{
				if(!empty(st)) pop(st);
				else
				{
					o = 0;
					push(0, st);
				}
			}
		} 
		else
		if(o == 0)
		{
			if (c == 'a') cd = 1; else cd = 0;
			if (cd == 0) push(0, st);
			else
			{
				if(!empty(st)) pop(st);
				else
				{
					o = 1;
					push(1, st);
				}
			}
			
		}


	}
	std::cout << empty(st);


	system("pause");

}