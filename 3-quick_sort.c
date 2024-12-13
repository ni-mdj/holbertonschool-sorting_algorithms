#include "sort.h"
#include <stdio.h>

/**
* partition - Partitions the array for Quick Sort using Lomuto scheme
* @array: The array to partition
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
* Return: The partition index
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1, temp, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_rec - Recursively sorts the array using Quick Sort
* @array: The array to sort
* @low: The starting index of the current partition
* @high: The ending index of the current partition
* @size: The size of the array
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick Sort algorithm
* @array: The array to sort
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

