#include "sort.h"

/**
 * my_swap - Swap two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void my_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * my_partition - Applies partition logic to sub-array.
 * @arr: Array being sorted.
 * @size: Size of array.
 * @left: Starting index.
 * @right: Ending index.
 *
 * Return: New partition index.
 */
int my_partition(int *arr, size_t size, int left, int right)
{
	int pivot = arr[right];
	int above = left - 1;
	int below = right + 1;

	while (above < below)
	{
		do {
			above++;
		} while (arr[above] < pivot);

		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			my_swap(&arr[above], &arr[below]);
			print_array(arr, size);
		}
	}

	return (above);
}

/**
 * my_sort - Recursive quicksort logic.
 * @arr: Array being sorted.
 * @size: Size of array.
 * @left: Starting index.
 * @right: Ending index.
 */
void my_sort(int *arr, size_t size, int left, int right)
{
	if (right > left)
	{
		int part = my_partition(arr, size, left, right);

		my_sort(arr, size, left, part - 1);
		my_sort(arr, size, part, right);
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

	hoare_sort(array, size, 0, size - 1);
}
