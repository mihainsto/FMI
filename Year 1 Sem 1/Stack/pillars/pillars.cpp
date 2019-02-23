#include <iostream>
#include "stack.h"

void array_read(int &n, int v[])
{
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> v[i];
}
int check(int n, int v[])
{
	stack *st;
	st = NULL;
	stack_push(v[1], st);
	for(int i=2; i<=n; i++)
	{
		if (stack_peek(st) == v[i]) stack_pop(st);
		else stack_push(v[i], st);
		
	}
	if (stack_empty(st)) return 1;
		return 0;
}
int main()
{
	int v[100], n;

	array_read(n, v);
	std::cout<<check(n, v);

	
	
	system("pause");
	return 0;
}