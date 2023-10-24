#include "sort.h"

void swap(int *a, int *b, int *array, size_t size);
void hoare_qsort(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - Sort array using quick sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	hoare_qsort(array, 0, size - 1, size);
}

/**
 * hoare_qsort - Quick sort with Hoare partition scheme
 * @array: Pointer to the array
 * @low: Lower bound
 * @high: Upper bound
 * @size: Size of the array
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
 * swap - Swap two integers in the array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 * @array: Pointer to the array
 * @size: Size of the array
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
