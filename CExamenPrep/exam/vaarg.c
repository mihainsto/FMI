#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int sum(int n,...)
{
	va_list valist;
	int s = 0;
	va_start(valist, n);

	for(int i=1;i<=n;i++)
	{
		int x = va_arg(valist, int);
		s += x;
	}
	return s;
}

int arraysum(int n,...)
{
	va_list valist;
	int s = 0;
	va_start(valist, n);

	for(int i=1;i<=n;i++)
	{
		int* v = va_arg(valist, int*);

		int m = v[0];
		for(int j=1; j<=m;j++)
		{
			s += v[j];
			
		}
	}
	return s;
}
int main()
{
	printf("%d\n", sum(4, 1, 2, 3, 4));

	int v[100] = { 2,1,2 };
	int b[100] = { 1,3 };
	int c[100] = { 1,4 };

	printf("%d\n", arraysum(3, v, b, c));
	system("pause");
	return 0;
}
