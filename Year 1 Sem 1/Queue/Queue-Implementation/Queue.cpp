#include <iostream>

struct queuenode
{
	int val;
	queuenode *next;
};
struct queue
{
	queuenode *first_q;
	queuenode *last_q;
};

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
int queue_search(int x, queue q)
{
	int distance=0;

	while(!queue_empty(q))
	{
		int a = queue_pop(q);

		if (a == x) return distance;
		distance++;
	}
	return 0;
}
void queue_print(queue q)
{
	while(!queue_empty(q))
	{
		std::cout << queue_pop(q) << " ";
	}
	std::cout << "\n";
}
int main()
{

	queue q;
	q.first_q = q.last_q = NULL;

	queue_push(12, q);
	queue_push(4, q);
	queue_push(2, q);
	queue_push(9, q);
	queue_push(5, q);

	queue_print(q);
	std::cout << queue_search(2,q) << "\n";
	std::cout << queue_pop(q) << " ";
	std::cout << queue_pop(q) << " ";

	system("pause");
	return 0;
}