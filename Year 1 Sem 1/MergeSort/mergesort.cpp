#include <iostream>
#include <fstream>
void merge(int v[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[100], R[100];

	for (i = 0; i < n1; i++)
		L[i] = v[l + i];
	for (j = 0; j < n2; j++)
		R[j] = v[m + 1 + j];
	
	int a_it = 1, b_it = 1;

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		v[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		v[k] = R[j];
		j++;
		k++;
	}

}
void merge_sort (int v[], int l, int r)
{
	if(l<r)
	{
		int m = l + (r - l) / 2;

		merge_sort(v, l, m);
		merge_sort(v, m + 1, r);

		merge(v, l, m, r);
	}
	
}
int main()
{
	freopen("ar.txt", "r", stdin);
	int  n, a[100],i;
	std::cin >> n;
	for (i = 0; i < n; i++)
		std::cin >> a[i];

	merge_sort(a, 0, n - 1);

	for (i = 0; i < n ; i++)
	{
		std::cout << a[i] << " ";
	}

	system("pause");
	return 0;
}