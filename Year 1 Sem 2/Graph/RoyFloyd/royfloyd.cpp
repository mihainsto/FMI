//prim
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <climits>
using namespace std;

void printMatrix(int v[101][101], int n, ostream &fout)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fout << v[i][j] << " ";
		fout << "\n";
	}
}
int graphMatrix[101][101], dist[101][101];
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("royfloyd.in");
	fout.open("royfloyd.out");
	int n;
	fin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fin >> graphMatrix[i][j];
			dist[i][j] = graphMatrix[i][j];
		}
		dist[i][i] = 0;
	}


	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || i == k) continue;
				if ((dist[i][j] > dist[i][k] + dist[k][j] || dist[i][j] == 0) && dist[i][k] && dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
	printMatrix(dist, n, fout);
	return 0;
}