#pragma once
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

void queue_push(int x, queue &q);
int queue_pop(queue &q);
int queue_peek(queue q);
bool queue_empty(queue q);
int queue_search(int x, queue q);
void queue_print(queue q);



