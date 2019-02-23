#include <iostream>
#include <fstream>
#include "queue.h"
struct adj_list
{
	int node;
	adj_list *next;
};
void adj_list_add(adj_list *&l, int n)
{
	adj_list *aux = new adj_list;
	aux->node = n;
	if (l == NULL)
	{
		aux->next = NULL;
	}
	else
		aux->next = l;

	l = aux;
}
int main()
{
	std::ifstream fin("adjlist.txt");
	int n, m, i, j, visited_ar[100] = {0};
	fin >> n;
	fin >> m;

	adj_list *lv[100];
	for (i = 1; i <= n; i++)
		lv[i] = NULL;

	for(i=1;i<=m;i++)
	{
		int a, b;
		fin >> a >> b;
		adj_list_add(lv[a], b);
		adj_list_add(lv[b], a);
	}
	queue q;
	q.first_q = q.last_q = NULL;

	for(i=1;i<=n;i++)
	{
		if (visited_ar[i] == 0)
		{
			queue_push(i, q);
			std::cout << "\n";
			
		}
		while(!queue_empty(q))
		{
			int x;
			x = queue_pop(q);
			std::cout << x << " ";
			
				visited_ar[x] = 1;
				adj_list *aux;
				aux = lv[x];
				while(aux != NULL)
				{
					if(visited_ar[aux->node] == 0) queue_push(aux->node, q);
					aux = aux->next;
				}
			
		}
	}
	std::cout << "\n";
	system("pause");
	return 0;
}