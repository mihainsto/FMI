#include <iostream>
using namespace std;
struct list 
{
	int val;
	list *next;
};
void insert_in_list(list *&first, int x)
{
	list *aux = new list;
	aux->val = x; 
	if (first == nullptr) aux->next = nullptr;
	else aux->next = first;
	first = aux;
}

void print_list(list *first)
{
	list *aux = first;

	while (aux != nullptr)
	{
		cout << aux->val << " ";
		aux = aux->next;
	}
	cout << "\n";
}

void fliplist1(list *firstlist)
{
	list *firstlist2=nullptr;
	list *aux = firstlist;
	while (aux)
	{
		insert_in_list(firstlist2, aux->val);
		aux = aux->next;
	}
	print_list(firstlist2);
}

void fliplist2(list *firstlist)
{
	list *aux = firstlist;
	int n=0;
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
	print_list(firstlist);
}
int main()
{
	list *firstlist;

	firstlist = nullptr;
	insert_in_list(firstlist,5);
	insert_in_list(firstlist,6);
	insert_in_list(firstlist,1);
	insert_in_list(firstlist, 10);
	insert_in_list(firstlist, 3);
	
	print_list(firstlist);

	fliplist1(firstlist);
	fliplist2(firstlist);
	system("pause");
	return 0;
}