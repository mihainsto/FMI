#include <iostream>
#include <fstream>
int degree(int x, int m[100][100], int n)
{
	int i, deg=0;
	for(i=1;i<=n;i++)
	{
		if (m[x][i]) deg++;
	}
	return deg;
}
int edges(int m[100][100], int n)
{
	int i, j, edg = 0;
	for (i = 1; i <= n; i++)
		for (j = i; j <= n; j++)
		{
			if (m[i][j]) edg++;
		}
	return edg;
}
void max_degree(int m[100][100], int n)
{
	int max_deg = degree(1, m, n), i;
	
	for(i=2;i<=n;i++)
	{
		if (max_deg < degree(i, m, n))
			max_deg = degree(i, m, n);
	}

	for (i = 1; i <= n; i++)
	{
		if (max_deg == degree(i, m, n)) std::cout << i << " ";
			
	}
}
int main()
{
	std::ifstream fin("adjmatrix.txt");
	int i,j,n,m[100][100] = { {0} };
	fin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fin >> m[i][j];

	std::cout << degree(1, m, n) << "\n";
	std::cout << edges(m, n) << "\n";
	max_degree(m, n);
	system("pause");
	return 0;
}