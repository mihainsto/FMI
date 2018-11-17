#include <iostream>
#include <windows.h>
#include "deque.h"

#define yellowout SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#define whiteout SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
int main()
{
	deque q;
	deque_init(q);
	int step, x;
	std::cout << "1 - front add\n2 - back add\n3 - front pop\n4 - back pop\n5 - print\n0 - exit\n";
	std::cin >> step;
	while(1)
	{
		switch(step)
		{
		case 1:
			std::cin >> x;
			deque_add_front(q, x);
			break;
		case 2:
			std::cin >> x;
			deque_add_back(q, x);
			break;
		case 3:
			yellowout
			std::cout << deque_pop_front(q) << "\n";
			whiteout
			break;
		case 4:
			yellowout
			std::cout << deque_pop_back(q) << "\n";
			whiteout
			break;
		case 5:			
			deque_print(q);
			break;
		}
		std::cin >> step;
	}
	
}