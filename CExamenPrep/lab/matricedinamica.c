#include <stdio.h>
#include <stdlib.h>
int **citire()
{
	int n;
	n = 3;
	int **v;
	v = malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
	{
	int *x;
	x = malloc(n*sizeof(int));
	for(int j=0;j<n;j++)
		{
			scanf("%d",&x[j]);
		}
	v[i] = x;
	}
	
	
	return v;
}

void afisare(int **v)
{	int n=3;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
}	
int main()
{
	int **v;
	v = citire();
	afisare(v);
	return 0;
}