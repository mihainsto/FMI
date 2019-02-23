#include <iostream>
#include "queue.h"

void queue_push(int x, queue &q)
{
	queuenode *aux = new queuenode;
	aux->val = x; aux->next = NULL;

	if (q.first_q == NULL) q.first_q = q.last_q = aux;
	else
	{
		q.last_q->next = aux;
		q.last_q = aux;
	}


}
int queue_pop(queue &q)
{
	int val = q.first_q->val;
	q.first_q = q.first_q->next;
	return val;
}
int queue_peek(queue q)
{
	int val = q.first_q->val;
	return val;
}
bool queue_empty(queue q)
{
	if (q.first_q == NULL) return true;
	else return false;
}
void queue_print(queue q)
{
	while (!queue_empty(q))
	{
		std::cout << queue_pop(q) << " ";
	}
	std::cout << "\n";
}
void queue_init(queue q)
{
	q.first_q = q.last_q = NULL;
}