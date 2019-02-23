#include <iostream>
using namespace std;

struct listnode
{
	int val;
	listnode *next;
};

void list_add(listnode *&first, int val)
{
	listnode *aux = new listnode;
	
	aux->val = val;
	if (first == NULL)  aux->next = NULL;
	else
		aux->next = first;
	first = aux;

}

void list_print(listnode *first)
{
	while(first != NULL)
	{
		cout << first->val << " ";
		first = first->next;
	}

	cout << "\n";
}

void list_flip(listnode *&firstlist)
{
	listnode *aux = firstlist;
	int n = 0;
	while (aux) aux = aux->next, n++;
	for (int i = 1; i < n; i++)
	{
		aux = firstlist;
		for (int j = 1; j <= n - i; j++)
		{
			swap(aux->val, aux->next->val);
			aux = aux->next;
		}

	}

}

void list_create_even_index_list(listnode *first_list1 , listnode *&first_list2)
{
	bool iseven = 1;
	first_list1 = first_list1->next;

	while(first_list1)
	{
		if (iseven) list_add(first_list2, first_list1->val);
		iseven = !iseven;
		first_list1 = first_list1->next;
	}

	list_flip(first_list2);
}

void list_create_odd_index_list(listnode *first_list1, listnode *&first_list2)
{
	bool isodd = 1;

	while (first_list1)
	{
		if (isodd) list_add(first_list2, first_list1->val);
		isodd = !isodd;
		first_list1 = first_list1->next;
	}

	list_flip(first_list2);
}

int main()
{
	listnode *first_list1, *first_list2, *first_list3;
	first_list1 = first_list2 = first_list3 =  NULL;

	list_add(first_list1, 10);
	list_add(first_list1, 9);
	list_add(first_list1, 1);
	list_add(first_list1, 6);
	list_add(first_list1, 2);
	list_add(first_list1, 13);
	list_add(first_list1, 7);
	list_add(first_list1, 1);
	list_add(first_list1, 5);

	list_print(first_list1);

	list_create_even_index_list(first_list1, first_list2);
	list_print(first_list2);

	list_create_odd_index_list(first_list1, first_list3);
	list_print(first_list3);

	system("pause");
}