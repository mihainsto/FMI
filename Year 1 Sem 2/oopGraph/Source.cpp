#include <iostream>
#include <fstream>
#include "Graph.hpp"


int main()
{
	
	//node x(1, 5);
	//std::cout << x.getKey();
	graph G;
	freopen("GraphInput.txt", "r", stdin);
	std::cin >> G;
	std::cout << G;
	system("pause");
	return 0;
}