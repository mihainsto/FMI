/** Fishiere binare*/
#include <stdio.h>
#include <stdlib.h>
int read_pos(int pos, FILE *f)
{ 
	int x;
	fseek(f, sizeof(int)*(pos-1), SEEK_SET);
	fread(&x, sizeof(int), 1, f);
	return x;
}
void write_to_pos(int pos, int x, FILE *f)
{
	
	fseek(f, sizeof(int)*(pos-1), SEEK_SET);
	fwrite(&x, sizeof(int), 1, f);
}
void create_rando_binaryfile()
{
	int n, x;
	scanf("%d",&n);
	FILE *f = fopen("binar","w+b");
	for(int i=1; i<=10; i++)
	{
		x = rand() % (2*n+1);
		x -= n;
		fwrite(&x, sizeof(int), 1, f);
	}
	//write_to_pos(3, 69, f);
	printf("%d\n", read_pos(1, f));

	for(int i=1; i<=10; i++)
		for(int j=1; j<=10; j++)
		{
			int x, y;
			x = read_pos(i,f); y = read_pos(j,f);
			if(x<y) 
			{
              write_to_pos(i, y, f);
              write_to_pos(j, x, f);
			}

		}
	for(int i=1; i<=10; i++)
	{
		printf("%d ", read_pos(i,f) );
	}
}
int main()
{
	//FILE *f = fopen("binar","wb");
	//int v[10]={1,2,3,4,5,6,7,8,9,10};
	//fwrite(v,sizeof(int),10,f); 
	create_rando_binaryfile();
}