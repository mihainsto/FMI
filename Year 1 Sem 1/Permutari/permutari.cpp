#include <iostream>
#include <fstream>
struct cic
{
	int n;
	int key[100];
};
void citeste_perm(int v[])
{
	int x, k = 0;
	std::ifstream fin;
	fin.open("permutare.txt");
	while(fin>>x)
	{
		v[++k] = x;
	}
	v[0] = k;
	
	fin.close();
	
}
void cicli_perm(int v[], cic cicli[])
{
	int n = v[0];
	int viz[100] = { 0 };
	int k = 0;

	for(int i=1;i<=n;i++)
	{
		
		if(viz[i] == 0)
		{
			
			viz[i] = 1;
			int l = 0;
			cicli[++k].key[++l] = i;
			int j = v[i];
			while(viz[j] == 0)
			{
				
				cicli[k].key[++l] = j;
				viz[j] = 1;
				j = v[j];
			}
			cicli[k].n = l;
		}
	}
	cicli[0].n = k;
}
void afisare_cicli(cic cicli[])
{
	int n = cicli[0].n,i,j;

	for(i=1;i<=n;i++)
	{
		std::cout << "( ";
		for(j=1;j<cicli[i].n;j++)
		{
			std::cout << cicli[i].key[j]<< ", ";
		}
		std::cout << cicli[i].key[j];
		std::cout << " )   ";
	}
}
void afisare_transpozitii(cic cicli[])
{
	int n = cicli[0].n, i, j;

	for (i = 1; i <= n; i++)
	{
		if (cicli[i].n == 1) continue;

		std::cout << "( ";
		std::cout << cicli[i].key[1] << ", ";
		for (j = 2; j < cicli[i].n; j++)
		{
			std::cout << cicli[i].key[j] << ") ";
			std::cout << "( ";
			std::cout << cicli[i].key[j] << ", ";
		}
		std::cout << cicli[i].key[j];
		std::cout << " ) ";
	}
	
}
void afisare_epsilon(cic cicli[])
{
	int n = cicli[0].n, i, j,k=0;

	for (i = 1; i <= n; i++)
	{
		if (cicli[i].n == 1) continue;
		k++;
		for (j = 2; j < cicli[i].n; j++)
			k++;
	
	}
	if (k % 2 == 0) std::cout << 1;
	else std::cout << -1;
	//std::cout << k;
}
int euclid(int a, int b)
{
	int c,p;
	p = a * b;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return p/a;
}
void ridicare_la_putere(cic cicli[], int p)
{
	int ordin = 1, n, i, j, k, ok = 0;
	n = cicli[0].n;

	for(i=1;i<=n;i++)
		ordin = euclid(ordin, cicli[i].n);

	if (p > ordin) p = p % ordin;
	if (p == -1) ok = 1;
	for (i = 1; i <= n; i++)
	{
		if (ok == 1) p = cicli[i].n - 1;

		if (cicli[i].n == p || cicli[i].n == 1) continue;

		j = 1;
		
		int viz[100] = { 0 };
		for (k = 1; k <= cicli[i].n; k++)
		{
			if (viz[cicli[i].key[k]] == 1) continue;
			std::cout << " ( ";
			viz[cicli[i].key[k]] = 1;

			j = k;
			int primu = cicli[i].key[j];
			std::cout << cicli[i].key[j];
			j = j + p;
			while (j > cicli[i].n)
			{
				j = j - cicli[i].n;
			}


			while (cicli[i].key[j] != primu)
			{
				viz[cicli[i].key[j]] = 1;
				std::cout <<", "<< cicli[i].key[j];

				j = j + p;
				while (j > cicli[i].n)
				{
					j = j - cicli[i].n;
				}
			}
			std::cout << " ) ";
		}
	}
	
}
int main()
{ 
	int v[100], option, p;
	cic cicli[100];
	citeste_perm(v);
	cicli_perm(v,cicli);
	std::cout << " 1 - afisare cicli\n 2 - afisare transpozitii\n 3 - afisare epsilon\n 4 - ridica permutarea la o putere \n 5 - exit\n";
	
	while (1)
	{
		std::cout << "\n Optiune:";
		std::cin >> option;
		switch (option)
		{
		case 1: afisare_cicli(cicli);
			break;
		case 2: afisare_transpozitii(cicli);
			break;
		case 3: afisare_epsilon(cicli);
			break;
		case 4:
			std::cout << "Introduce puterea: \n";
			std::cin >> p;
			ridicare_la_putere(cicli, p);
			break;
		case 5:
			return 0;
			break;
		}
	}
	
	system("pause");	
	return 0;
}
