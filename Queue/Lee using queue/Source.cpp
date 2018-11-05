#include <iostream>
#include <fstream>
#include  "queue.h"
std::ifstream fin("matrix.txt");

void matrix_read(int v[100][100], int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fin >> v[i][j];
}
void matrix_print(int v[100][100], int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			std::cout << v[i][j] << " ";
		std::cout << "\n";
	}

}
void backtrace(int v[100][100], int n, int k, int i, int j)
{
	int i_adiacent[] = { -1,1,0,0 };
	int j_adiacent[] = { 0,0,-1,1 };
	queue q; q.first_q = NULL; q.last_q = NULL;
	queue_push(std::make_pair(i, j), q);
	std::pair<int, int> ce;
	while(!queue_empty(q))
	{
		ce = queue_pop(q);
		i = ce.first; j = ce.second;
		v[i][j] = k;
		for(int l=0;l<=3;l++)
		{
			int newi = i + i_adiacent[l], newj = j + j_adiacent[l];

			if (v[newi][newj] == 1) queue_push(std::make_pair(newi, newj), q);

		}
	}
	
}
void lee(int v[100][100], int n)
{
	int k = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] == 1) 
			{
				k++; backtrace(v, n, k, i, j);
			}
			
				
			
		}
}

int main()
{	
	int v[100][100], n;
	fin >> n;
	matrix_read(v, n);
	lee(v, n);
	matrix_print(v, n);
	system("pause");
	return 0;
}