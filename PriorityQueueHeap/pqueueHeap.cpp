#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>

struct pqueue
{
	int pr;
	int key;
	
};
void heapify(pqueue heap[], int n)
{
	
	while(heap[n/2].pr < heap[n].pr && n!=1)
	{
		std::swap(heap[n / 2], heap[n]);
		n = n / 2;
	}
}
void heap_add(pqueue heap[], int &n, pqueue x)
{
	heap[++n] = x;
	heapify(heap, n);
}
void heap_print(pqueue heap[], int n)
{
	for (int i = 1; i <= n; i++) std::cout<<"( " << heap[i].pr<<" "<<heap[i].key<<" ) ";
	std::cout << "\n";
}
pqueue heap_pop(pqueue heap[], int &n, int pr)
{
	int i;
	for( i=1;i<=n;i++)
	{
		if (heap[i].pr == pr) break;
	}
	pqueue max = heap[i];
	std::swap(heap[i], heap[n]);
	n--;
	i = 1;
	while(1)
	{
		pqueue son1, son2, maxson;
		son1.pr = INT_MIN; son2.pr = INT_MIN;
		if (2 * i <= n) son1 = heap[2 * i];
		if (2 * i + 1 <= n) son2 = heap[2 * i + 1];

		int maxsonpr = INT_MIN, maxsoni;		
		if (son2.pr >= maxsonpr) maxsonpr = son2.pr, maxson = son2;
		if (son1.pr >= maxsonpr) maxsonpr = son1.pr, maxson = son1;
		if (maxson.pr == son1.pr)  maxsoni = 2 * i;
		else maxsoni = 2 * i + 1;
		if (heap[i].pr < maxson.pr) std::swap(heap[i], heap[maxsoni]);
		else break;

	}
	return max;
}


int main()
{
	pqueue heap[100];
	int n;
	n = 0;
	pqueue val;
	val.key = 15;
	val.pr = 3;
	heap_add(heap, n, val);
	val.key = 4;
	val.pr = 3;
	heap_add(heap, n, val);
	val.key = 9;
	val.pr = 2;
	heap_add(heap, n, val);
	val.key = 6;
	val.pr = 1;
	heap_add(heap, n, val);
	val.key = 33;
	val.pr = 2;
	heap_add(heap, n, val);
	//heap_sort(heap, n);
	//heap_print(heap, n);
	pqueue x = heap_pop(heap, n, 2);
	//x = heap_pop(heap, n, 3);
	//x = heap_pop(heap, n, 3);
	std::cout << "( " << x.pr << " " << x.key << " ) \n";
	heap_print(heap, n);
	system("pause");
	return 0;
}