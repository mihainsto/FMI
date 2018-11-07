#include <iostream>
struct listnode
{
	int val;
	listnode *next;
	listnode *prev;
};
void list_front_add(listnode *&first, listnode *&last, int x)
{
	listnode *aux;
	aux = new listnode;
	aux->next = NULL; aux->prev = NULL;
	aux->val = x;

	if (first == NULL) first = last = aux;
	else {
		aux->next = first;
		first->prev = aux;
	}
	first = aux;
}
void list_print(listnode *first)
{
	while(first != NULL)
	{
		std::cout << first->val << " ";
		first = first->next;
	}
	std::cout << "\n";
}
void list_back_add(listnode *&first, listnode *&last, int x)
{
	listnode *aux;
	aux = new listnode;
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
void list_print_reverse(listnode *last)
{
	while(last != NULL)
	{
		std::cout << last->val << " ";
		last = last->prev;
	}
	std::cout << "\n";
}
void list_index_insert(listnode *first, int index, int x)
{
	int i = 1;
	listnode *aux;
	aux = first;
	while(1)
	{
		if(index == i+1)
		{
			listnode *aux2;
			aux2 = new listnode;
			aux2->val = x;
			aux2->prev = aux;
			aux2->next = aux->next;
			aux->next = aux2;
			return;
		}
		i++;
		aux = aux->next;
	}
}
void list_index_delete(listnode *first, int index)
{
	int i = 1;
	listnode *aux;
	aux = first;
	while(aux!=NULL)
	{
		if(i+1==index)
		{
			aux->next = aux->next->next;
			aux->next->prev = aux;
			return;
		}
		i++;
		aux = aux->next;
	}
}
void list_value_delete(listnode *first, int x)
{
	listnode *aux;
	aux = first;
	while (aux != NULL)
	{
		if (aux->next->val == x)
		{
			aux->next = aux->next->next;
			aux->next->prev = aux;
			return;
		}
		aux = aux->next;
	}
}
int main()
{
	listnode *first, *last;
	first = last = NULL;
	list_front_add(first, last, 5);
	list_front_add(first, last, 6);
	list_front_add(first, last, 1);
	list_front_add(first, last, 2);
	std::cout << "front add 5-6-1-2:\n";
	list_print(first);
	std::cout << "back add 10-3:\n";
	list_back_add(first, last, 10);
	list_back_add(first, last, 3);

	list_print(first);
	std::cout << "print reverse:\n";
	list_print_reverse(last);
	std::cout << "insert on index 3 val 4: \n";
	list_index_insert(first, 3, 4);
	list_print(first);
	std::cout << "delete index 3:\n";
	list_index_delete(first, 3);
	list_print(first);
	std::cout << "delete value 10:\n";
	list_value_delete(first, 10);
	list_print(first);
	system("pause");
	return 0;
}