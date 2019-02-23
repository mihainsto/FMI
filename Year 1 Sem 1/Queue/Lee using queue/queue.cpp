#include <iostream>
#include "queue.h"
void queue_push(std::pair<int,int> x, queue &q)
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
std::pair<int, int>  queue_pop(queue &q)
{
	std::pair<int, int>  val = q.first_q->val;
	q.first_q = q.first_q->next;
	return val;
}
std::pair<int, int> queue_peek(queue q)
{
	std::pair<int, int> val = q.first_q->val;
	return val;
}
bool queue_empty(queue q)
{
	if (q.first_q == NULL) return true;
	else return false;
}