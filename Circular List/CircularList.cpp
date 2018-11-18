#include <iostream>
struct listnode
{
	int val;
	listnode *next;
	listnode *prev;
};
void Clist_insert(listnode *&start, int x)
{
	listnode *aux = new listnode;
	aux->val = x;
	aux->next = NULL;
	aux->prev = NULL;
	if(start->next == NULL)
	{
		start->next = aux;
		start->prev = aux;
		aux->prev = start;
	}
	else
	{
		start->prev->next = aux;
		aux->next = start;
		aux->prev = start->prev;
		start->prev = aux;
	}
}
void Clist_print(listnode *start)
{
	listnode *aux = start;
	aux = aux->next;
	while(aux != start)
	{
		std::cout << aux->val << " ";
		aux = aux->next;
	}
	std::cout << "\n";
}
void Clist_node_delete(listnode *&start, int x)
{
	listnode *aux = start;
	aux = aux->next;
	while (aux != start)
	{
		if(aux->val == x)
		{
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
			return;
		}
		aux = aux->next;
	}
}
void Clist_init(listnode *&start)
{
	start = new listnode;
	start->next = NULL; start->prev = NULL;
}
void Clist_node_left_delete(listnode *&start)
{
	listnode *aux;
	aux = start->prev->prev;
	aux->next = start;
	start->prev = aux;
}
void Clist_node_right_insert(listnode *&start, int x)
{
	listnode *aux = new listnode;
	aux->val = x; 
	aux->next = NULL;
	aux->prev = NULL;
	if(start->next == NULL)
	{
		start->next = aux;
		aux->prev = start;
		aux->next = start;
	}
	else
	{
		start->next->prev = aux;
		aux->next = start->next;
		start->next = aux;
		aux->prev = start;
	}

}
int main()
{
	listnode *start;
	Clist_init(start);

	Clist_insert(start, 5); 
	Clist_insert(start, 8); 
	Clist_insert(start, 9);
	Clist_print(start);
	Clist_node_left_delete(start);
	Clist_node_right_insert(start, 1);
	Clist_print(start);
	system("pause");
	return 0;
}