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

void queue_init(queue q);
int queue_pop(queue &q);
void queue_push(int x, queue &q);
bool queue_empty(queue q);