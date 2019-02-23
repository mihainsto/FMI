#include <iostream>
void print(int n, int arr[])
{
	for(int i=0;i<n;i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}
int partition(int arr[],int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
		
		
	}
	std::swap(arr[i + 1], arr[r]);
	return i + 1;
}
int part_random(int arr[], int l, int r)
{
	int pivot = l + rand() % (l - r);
	std::swap(arr[pivot], arr[r]);

	return partition(arr, l, r);
}
void random_quick_sort(int arr[], int l, int r)
{
	if(l<r)
	{
		int part_index = part_random(arr, l, r);
		random_quick_sort(arr, l, part_index - 1);
		random_quick_sort(arr, part_index + 1, r);
	}
	

		
	

}

int main()
{
	int arr[] = { 21,97,302,621,615,439,1,2,3,4 };
	
	random_quick_sort(arr, 0, 6);
	
	print(6, arr);
				
	system("pause");
	return 0;
}