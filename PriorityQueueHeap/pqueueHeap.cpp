#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>

struct pqueue
{
	int pr;
	int key;
	int subpr;
};
void qify(pqueue q[], int n)
{

	while (q[n / 2].pr < q[n].pr && n != 1)
	{
		std::swap(q[n / 2], q[n]);
		n = n / 2;
	}
}
int nextsubpr(pqueue q[], int n, int pr)
{
	int k = 0;
	for(int i=1;i<=n;i++)
	{
		if (q[i].pr == pr) k++;
	}
	return k;
}
void q_add(pqueue q[], int &n, pqueue x)
{
	
	q[++n] = x;
	int subpr = nextsubpr(q, n, x.pr);
	q[n].subpr = subpr;
	qify(q, n);
}
void q_print(pqueue q[], int n)
{
	for (int i = 1; i <= n; i++) std::cout << " ( " << q[i].key << " " << q[i].pr <<" "<<q[i].subpr<<" ) ";
	std::cout << "\n";
}
pqueue q_pop(pqueue q[], int &n, int pr)
{
	int i,minsubpr = INT_MAX;
	for (i = 1; i <= n; i++)
	{
		if (q[i].pr == pr)
		{
			if (q[i].subpr < minsubpr) minsubpr = q[i].subpr;
				
		}
	}
	for(i=1;i<=n;i++)
	{
		if (q[i].subpr == minsubpr) break;
	}
	pqueue max = q[i];
	std::swap(q[i], q[n]);
	n--;
	i = 1;
	while (1)
	{
		pqueue son1, son2, maxson;
		son1.pr = INT_MIN; son2.pr = INT_MIN;
		if (2 * i <= n) son1 = q[2 * i];
		if (2 * i + 1 <= n) son2 = q[2 * i + 1];

		int maxsonpr = INT_MIN, maxsoni;
		if (son2.pr >= maxsonpr) maxsonpr = son2.pr, maxson = son2;
		if (son1.pr >= maxsonpr) maxsonpr = son1.pr, maxson = son1;
		if (maxson.pr == son1.pr)  maxsoni = 2 * i;
		else maxsoni = 2 * i + 1;
		if (q[i].pr < maxson.pr) std::swap(q[i], q[maxsoni]);
		else break;

	}
	return max;
}


int main()
{
	pqueue q[100];
	int n;
	n = 0;
	pqueue val;
	val.key = 10;
	val.pr = 3;
	q_add(q, n, val);
	val.key = 5;
	val.pr = 1;
	q_add(q, n, val);
	val.key = 2;
	val.pr = 2;
	q_add(q, n, val);
	val.key = 7;
	val.pr = 2;
	q_add(q, n, val);
	val.key = 15;
	val.pr = 3;
	q_add(q, n, val);
	val.key = 15;
	val.pr = 3;
	q_add(q, n, val);
	q_print(q, n);
	pqueue x = q_pop(q, n, 2);
	//x = q_pop(q, n, 3);
	//x = q_pop(q, n, 3);
	//std::cout << "( " << x.pr << " " << x.key << " ) \n";
	q_print(q, n);
	system("pause");
	return 0;
}
