#include <stdio.h>
#include <stdlib.h>
int* creare1d()
{
	int n;
	scanf("%d", &n);
	int* v;

	v = malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}
	v[0] = n;
	return v;
}

void afisare1d(int* v)
{
	int n = v[0];
	printf("\n");

	for (int i = 1; i <= n; i++)
		printf("%d ", v[i]);

	printf("\n");
}
int** creare2d()
{
	int n, i, j;
	scanf("%d", &n);
	int** v;

	v = malloc((n + 1) * sizeof(int*));

	for (i = 1; i <= n; i++)
		v[i] = malloc((n + 1) * sizeof(int));

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}

	v[0][0] = n;
	return v;
}

void printare2d(int** v)
{
	int n, i, j;

	n = v[0][0];

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}


}
int main()
{
	int** v;
	v = creare2d();

	printare2d(v);
	system("pause");
	return 0;
}