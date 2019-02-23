#include <iostream>
#include <fstream>

struct arraynode
{
	int val , index;
	arraynode *next;

};

void array_add(arraynode *&first, arraynode *&last, int x)
{
	if(first == NULL)
	{
		arraynode *aux = new arraynode;
		aux->index = 1;	aux->val = x; aux->next = NULL;
		first = aux;
		aux = new arraynode;
		aux->val = 0; aux->index = 2;
		first->next = aux;
		last = aux;
	}
	else
	{
		if (x == 0) last->index++;
		else
		{
			last->val = x;
			arraynode *aux = new arraynode;
			aux->val = 0; aux->index = last->index + 1; aux->next = NULL;
			last->next = aux;
			last = aux;

		}

	}

}

void print_zero(int z)
{
	for (int i = 1; i <= z; i++)
		std::cout << "0 ";
}

void array_print(arraynode *first)
{
	int previous_index = 0;
	while (first != NULL && first->val != 0)
	{
		print_zero(first->index - previous_index - 1);
		std::cout << first->val << " ";
		previous_index = first->index;
		first = first->next;
	}
	std::cout << "\n";
}

void array_sum(arraynode *array1_first, arraynode *array2_first, arraynode *&resultarray_first, arraynode *&resultarray_last, int max_size)
{
	for(int i=1;i<=max_size;i++)
	{
		int val1_index, val2_index, val1 = 0, val2 = 0, result = 0;

		if (array1_first != NULL) val1_index = array1_first->index, val1 = array1_first->val;
		if (array2_first != NULL) val2_index = array2_first->index, val2 = array2_first->val;
		
		if(array1_first != NULL) if (i > val1_index) array1_first = array1_first->next;
		if(array2_first != NULL) if (i > val2_index) array2_first = array2_first->next;

		if (array1_first != NULL) val1_index = array1_first->index, val1 = array1_first->val;
		if (array2_first != NULL) val2_index = array2_first->index, val2 = array2_first->val;

		if (val1_index == i) result += val1;
		if (val2_index == i) result += val2;

		array_add(resultarray_first, resultarray_last, result);

	}
}

void array_mult(arraynode *array1_first, arraynode *array2_first, arraynode *&resultarray_first, arraynode *&resultarray_last, int size_array1, int size_array2)
{
	for(int i=1;i<=size_array1;i++)
	{
		if (array1_first != NULL) if (i > array1_first->index) array1_first = array1_first->next;
		int val_array1 = 0;
		if (array1_first->index == i)val_array1 += array1_first->val;

		arraynode *aux_array2 = array2_first;
		for(int j=1;j<=size_array2;j++)
		{  
			if (aux_array2 != NULL) if (j > aux_array2->index) aux_array2 = aux_array2->next;
			int val_array2 = 0;
			if (aux_array2->index == j) val_array2 += aux_array2->val;
			array_add(resultarray_first, resultarray_last, val_array2*val_array1);
		}

	}
}
int main()
{
	std::ifstream fin("array.txt");
	int size_ar1, size_ar2, size_ar3, x;
	arraynode *array1_first, *array2_first, *sumarray_first, *multarray_first, *array1_last, *array2_last,*sumarray_last, *multarray_last;
	array1_first = array2_first = sumarray_first = multarray_first = array1_last = array2_last = sumarray_last = multarray_last = NULL;

	fin >> size_ar1;
	for(int i=1;i<=size_ar1;i++)
	{
		fin >> x;
		array_add(array1_first, array1_last, x);
	}

	fin >> size_ar2;
	for (int i = 1; i <= size_ar2; i++)
	{
		fin >> x;
		array_add(array2_first, array2_last, x);
	}

	int max_size;
	if (size_ar1 > size_ar2) max_size = size_ar1; else max_size = size_ar2;

	array_sum(array1_first, array2_first, sumarray_first, sumarray_last, max_size);
	array_print(sumarray_first);

	std::cout << "-----------------\n";
	
	array_mult(array1_first, array2_first, multarray_first, multarray_last, size_ar1, size_ar2);
	array_print(multarray_first);
	system("pause");
}