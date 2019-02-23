//Priority_queue
#include <iostream>
struct queue_node
{
	int val;
	int priority;
	queue_node *next;
};
struct priority_queue
{
	queue_node *first_node;
};
void pqueue_init(priority_queue &q)
{
	 q.first_node = NULL;
}
void pqueue_add(priority_queue &q, int x, int priority)
{
	queue_node *aux = new queue_node;
	aux->next = NULL;
	aux->priority = priority;
	aux->val = x;
	if(q.first_node == NULL)
	{
		q.first_node = aux;
	}
	else
	{
		queue_node *auxp = q.first_node;
		if (aux->priority == q.first_node->priority)
		{
			aux->next = q.first_node;
			q.first_node = aux;
		}
		else
		while(1)
		{
			if(auxp->priority == aux->priority)
			{
				aux->next = auxp->next;
				auxp->next = aux;
				 x = aux->val;
				aux->val = auxp->val;
				auxp->val = x;
				break;
			}
			if(auxp->next==NULL)
			{
				auxp->next = aux;
				break;
			}
			auxp = auxp->next;
		}
	}
}
int pqueue_pop(priority_queue q, int priority)
{
	queue_node *prev = q.first_node;
	q.first_node = q.first_node->next;
	while(q.first_node != NULL)
	{
		//std::cout << q.first_node->val << " " << q.first_node->priority;
		if(q.first_node->priority == priority+1)
		{
			int x = prev->val;
			prev->val = q.first_node->val;
			prev->priority = q.first_node->priority;
			prev->next = q.first_node->next;
			return x;
		}
		prev = q.first_node;
		q.first_node = q.first_node->next;
		//std::cout << "\n";
	}
}
void pqueue_print(priority_queue q)
{
	while(q.first_node!=NULL)
	{
		std::cout << q.first_node->val << " " << q.first_node->priority;
		q.first_node = q.first_node->next;
		std::cout << "\n";
	}
	std::cout << "\n";
}
int main()
{
	priority_queue q;
	pqueue_init(q);
	pqueue_add(q, 5, 1);
	pqueue_add(q, 2, 1);
	pqueue_add(q, 7, 2);
	pqueue_add(q, 8, 2);
	pqueue_add(q, 3, 3);
	pqueue_add(q, 1, 1);
	pqueue_add(q, 4, 2);
	pqueue_add(q, 5, 3);

	pqueue_print(q);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << pqueue_pop(q, 2);
	std::cout << "\n";
	pqueue_print(q);

	system("pause");

}