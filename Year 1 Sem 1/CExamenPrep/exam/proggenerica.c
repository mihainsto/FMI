#include <stdio.h>
#include <stdlib.h>

int cmp_int(void* a, void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	printf("%d %d\n", x, y);
	if (x == y) return 1;
	return 0;
}
int cmp_char(void* a, void* b)
{
	int x = *(char*)a;
	int y = *(char*)b;
	printf("%c %c\n", x, y);
	if (x == y) return 1;
	return 0;
}


int egale(void* a, void* b, int a_count, int b_count, int size, int(*cmp)(void*,void*))
{
	if (a_count != b_count) return 0;
	int i,n = a_count;

	for(i=0;i<n;i++)
	{
		if (!cmp((char*)a + i * size, (char*)b + i * size)) return 0;
		
	}
	return 1;
}



int main()
{
	int v_a[100] = { 1,2,3,4 };
	int v_b[100] = { 1,2,3,4 };
	int v_c[100] = { 1,2,3,5 };
	
	char s_a[100] = { "string" };
	char s_b[100] = { "string" };
	
	//egale(v_a, v_c, 4, 4, sizeof(int), cmp_int);
	
	  egale(s_a, s_b, 6, 6, sizeof(char),cmp_char);

	
	system("pause");
	return 0;
}
