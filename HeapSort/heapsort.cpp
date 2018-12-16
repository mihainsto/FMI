#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>

void heapify(int heap[], int n)
{
	
	while(heap[n/2] < heap[n] && n!=1)
	{
		std::swap(heap[n / 2], heap[n]);
		n = n / 2;
	}
}
void heap_add(int heap[], int &n, int x)
{
	heap[++n] = x;
	heapify(heap, n);
}
void heap_print(int heap[], int n)
{
	for (int i = 1; i <= n; i++) std::cout << heap[i]<<" ";
	std::cout << "\n";
}
int heap_delete_first_node(int heap[], int &n)
{
	int max = heap[1];
	std::swap(heap[1], heap[n]);
	n--;
	int i = 1;
	while(1)
	{
		
		int son1 = INT_MIN, son2 = INT_MIN, maxson, maxsoni;
		if (2 * i <= n) son1 = heap[2 * i];
		if (2 * i + 1 <= n) son2 = heap[2 * i + 1];
		
		maxson = std::max(son1, son2);
		if (maxson == son1) maxsoni = 2 * i;
		else maxsoni = 2 * i + 1;
		if (heap[i] < maxson) std::swap(heap[i], heap[maxsoni]);
		else break;
		i = maxsoni;
	}
	return max;
}

void heap_sort(int heap[], int n)
{
	while (n)
	{
		int x = heap_delete_first_node(heap, n);
		std::cout << x << " ";
	}
}
int main()
{
	int heap[100], n;
	n = 0;
	heap_add(heap, n, 104);
	heap_add(heap, n, 32);
	heap_add(heap, n, 64);
	heap_add(heap, n, 30);
	heap_add(heap, n, 19);
	heap_add(heap, n, 48);
	heap_add(heap, n, 15);
	heap_add(heap, n, 7);
	heap_add(heap, n, 10);
	heap_add(heap, n, 8);

	
	heap_sort(heap, n);
	system("pause");
	return 0;
}