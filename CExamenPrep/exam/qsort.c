#include <stdio.h>
#include <stdlib.h>

int** citire_matrice(char* file_name)
{
	int** v;
	int i,n,j;
	FILE *f = fopen(file_name, "r");

	fscanf(f, "%d", &n);

	v = malloc((n+1) * sizeof(int*));
	for (i = 1; i <= n; i++)
	v[i] = malloc((n+1) * sizeof(int));

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)	
			fscanf(f, "%d", &v[i][j]);
	v[0][0] = n;

	return v;
}
void afisare_matrice(int** v)
{
	int n, i, j;
	n = v[0][0];

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

int cmp(const void** p, const void** q)
{
	int* a = (int*) *p;
	int* b = (int*) *q;

	int e1 = a[1];
	int e2 = b[1];

	return e1-e2;
}
int main()
{
	int** v;
	int n;
	v = citire_matrice("matrice.txt");
	n = v[0][0];
	
	qsort((void*)(v+1), n, sizeof(int), cmp);

	afisare_matrice(v);
	system("pause");
	return 0;
}
