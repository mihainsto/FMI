#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct 
{
	char name[25];
	int id;
}data;

data* declare()
{
	data *x;
	x = malloc(10 * sizeof(data));
	strcpy(x[0].name, "Mihai");
	strcpy(x[1].name, "Cristi");
	strcpy(x[2].name, "Andrei");
	strcpy(x[3].name, "Cosmin");

	x[0].id = 10;
	x[1].id = 5;
	x[2].id = 10;
	x[3].id = 1;
	return x;
}

void print(data *x)
{
	for(int i=0;i<4;i++)
	{
		printf("%d %s\n",x[i].id,x[i].name);
	}
}
int comparator(const void *p, const void *q)
{
	data x, y;
	x = *(data*)p;
	y = *(data*)q;
	if(x.id<y.id) return -1;
	if(x.id>y.id) return 1;
	if(x.id==y.id)
	{
		if(x.name[0]<y.name[0]) return -1;
		if(x.name[0]>y.name[0]) return 1;
	}

	return 0;
}
int main()
{
	data *x;
	int size = 4;
	x = declare();
	qsort((void*)x,size,sizeof(data),comparator);
	print(x);

	return 0;
}