#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char a, b;
	char s[100];
	FILE *f = fopen("string.txt","r");
	//fscanf(f,"%s%s", &a, &b);
	a = fgetc(f);
	fgetc(f);
	b = fgetc(f);
	fgetc(f);

	fgets(s, 100, f);
	int n = strlen(s), i;

	for(i=0;i<n;i++)
	{
		if (s[i]==a) s[i]=b;
	}
	//printf("%s", s);

	FILE *g = fopen("bin", "w+b");

	fwrite(&s, sizeof(char), 30, g);

	fseek(g, 5, SEEK_SET);
	char c[100];
	fread(&c, sizeof(char), 5, g);
	printf("%s", c);

	system("pause");
	return 0;
}
