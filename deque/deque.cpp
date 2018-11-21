#include <iostream>
#include <windows.h>
#define yellowout SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#define whiteout SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
struct dequenode
{
	int val;
	dequenode *next;
	dequenode *prev;
};
void deque_front_add(dequenode *&first, dequenode *&last, int x)
{
	dequenode *aux;
	aux = new dequenode;
	aux->next = NULL; aux->prev = NULL;
	aux->val = x;

	if (first == NULL) first = last = aux;
	else {
		aux->next = first;
		first->prev = aux;
	}
	first = aux;
}
void deque_print(dequenode *first)
{
	while (first != NULL)
	{
		std::cout << first->val << " ";
		first = first->next;
	}
	std::cout << "\n";
}
void deque_back_add(dequenode *&first, dequenode *&last, int x)
{
	dequenode *aux;
	aux = new dequenode;
	aux->next = NULL; aux->prev = NULL;
	aux->val = x;
	if (first == NULL) first = last = aux;
	else
	{
		last->next = aux;
		aux->prev = last;
	}
	last = aux;
}
int deque_pop_front(dequenode *first)
{
	int x;
	x = first->val;
	first = first->next;
	first->prev = NULL;
	return x;
}
int deque_pop_back(dequenode *last)
{
	int x;
	x = last->val;
	last = last->prev;
	last->next = NULL;
	return x;

}
int main()
{
	dequenode *first, *last;
	first = last = NULL;
	int step, x;
	std::cout << "1 - front add\n2 - back add\n3 - front pop\n4 - back pop\n5 - print\n0 - exit\n";
	std::cin >> step;
	while (step)
	{
		switch (step)
		{
		case 1:
			std::cin >> x;
			deque_front_add(first,last, x);
			break;
		case 2:
			std::cin >> x;
			deque_back_add(first,last, x);
			break;
		case 3:
			yellowout
				std::cout << deque_pop_front(first) << "\n";
			whiteout
				break;
		case 4:
			yellowout
				std::cout << deque_pop_back(last) << "\n";
			whiteout
				break;
		case 5:
			deque_print(first);
			break;
		}
		std::cin >> step;
	}

	system("pause");
	return 0;
}