#include "sort.h"

void swap(int *a, int *b, int *array, size_t size);
void hoare_qsort(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - Sorts an array of integers using quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	hoare_qsort(array, 0, size - 1, size);
}

/**
 * hoare_qsort - Implementation of quick sort using Hoare scheme
 * @array: array of integers
 * @low: lower bound
 * @high: upper bound
 * @size: size of the array
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	if (low >= high)
		return;

	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			break;

		swap(&array[i], &array[j], array, size);
	}

	hoare_qsort(array, low, j, size);
	hoare_qsort(array, j + 1, high, size);
}

/**
 * swap - Swaps two integers
 * @a: first integer
 * @b: second integer
 * @array: array of integers for print_array
 * @size: size of the array for print_array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}
