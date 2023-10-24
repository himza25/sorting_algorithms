#include "sort.h"

/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - implements Lomuto partition scheme
 * @array: the array to sort
 * @low: the low index of the partition to sort
 * @high: the high index of the partition to sort
 * @size: size of the array
 * Return: the index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_helper - sorts an array using quick sort
 * @array: the array to sort
 * @low: the low index of the partition to sort
 * @high: the high index of the partition to sort
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
