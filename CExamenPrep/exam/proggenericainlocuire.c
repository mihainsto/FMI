#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_int(void* a, void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x == y) return 1;
	return 0;
}
int cmp_char(void* a, void* b)
{
	int x = *(char*)a;
	int y = *(char*)b;
	if (x == y) return 1;
	return 0;
}

int swap_int(void* a, void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	*(int*)a = y;
	//*(int*)b = x;
	return 0;
}

int swap_char(void* a, void* b)
{
	int x = *(char*)a;
	int y = *(char*)b;
	*(char*)a = y;
	//*(char*)b = x;
	return 0;
}
void inlocuire(void* v, void* a, void *b, int size,int count, void(*swap)(void*,void*), int(*cmp)(void*,void*))
{
	int i;
	for(i=0;i<count;i++)
	{
		int ok = cmp((char*)v + i * size, a);
		//printf("%d ", ok);
		if(ok)
		{
			swap((char*)v + i * size, b);
		}
	}
}

int main()
{
	int v_a[100] = { 1,2,3,4,6,4,7,4};

	char s_a[100] = { "string and source sauce" };

	int a = 4, b = 9;
	
	inlocuire(v_a, &a, &b, sizeof(int), 8, swap_int, cmp_int);
	printf("\n");
	for(int i=0;i<8;i++)
	{
		printf("%d ", v_a[i]);
	}
	char a2 = 's', b2 = 'x';

	inlocuire(s_a, &a2, &b2, sizeof(char), strlen(s_a), swap_char, cmp_char);
	printf("\n");
	printf("%s", s_a);
	system("pause");
	return 0;
}
