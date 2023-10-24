#include "sort.h"

void exchange_elements(int *x, int *y);
int hoare_divide(int *arr, size_t sz, int start, int end);
void hoare_recursive_sort(int *arr, size_t sz, int start, int end);

/**
 * exchange_elements - Exchange two integer elements in an array.
 * @x: The first integer to exchange.
 * @y: The second integer to exchange.
 */
void exchange_elements(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * hoare_divide - Reorganize a sub-array according to the Hoare partition.
 * @arr: The array of integers.
 * @sz: The size of the array.
 * @start: The starting index of the sub-array to organize.
 * @end: The ending index of the sub-array to organize.
 *
 * Return: The final partition index.
 *
 * Description: Utilizes the last element of the partition as the pivot.
 * Outputs the array after each element exchange.
 */
int hoare_divide(int *arr, size_t sz, int start, int end)
{
	int pivot_element, higher, lower;

	pivot_element = arr[end];
	for (higher = start - 1, lower = end + 1; higher < lower;)
	{
		do {
			higher++;
		} while (arr[higher] < pivot_element);
		do {
			lower--;
		} while (arr[lower] > pivot_element);

		if (higher < lower)
		{
			exchange_elements(arr + higher, arr + lower);
			print_array(arr, sz);
		}
	}

	return (higher);
}

/**
 * hoare_recursive_sort - Execute the quicksort algorithm recursively.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 * @start: The start index of the array partition to organize.
 * @end: The end index of the array partition to organize.
 *
 * Description: Utilizes the Hoare partition scheme.
 */
void hoare_recursive_sort(int *arr, size_t sz, int start, int end)
{
	int partition_idx;

	if (end - start > 0)
	{
		partition_idx = hoare_divide(arr, sz, start, end);
		hoare_recursive_sort(arr, sz, start, partition_idx - 1);
		hoare_recursive_sort(arr, sz, partition_idx, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursive_sort(array, size, 0, size - 1);
}
