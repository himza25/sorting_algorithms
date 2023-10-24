#include "sort.h"

/**
 * bitonic_compare - helper function to compare and swap two numbers.
 * @array: array of integers.
 * @i: index of first integer.
 * @j: index of second integer.
 * @dir: direction for comparison, 1 for ascending, 0 for descending.
 */
void bitonic_compare(int *array, size_t i, size_t j, int dir)
{
	if (dir == (array[i] > array[j]))
	{
		int tmp = array[i];

		array[i] = array[j];
		array[j] = tmp;
		print_array(array, j + 1);
	}
}

/**
 * bitonic_merge - helper function to sort bitonic sequence.
 * @array: array of integers.
 * @low: lowest index of the sequence in array.
 * @cnt: count of elements in sequence.
 * @dir: direction for comparison, 1 for ascending, 0 for descending.
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		size_t k = cnt / 2;

		for (size_t i = low; i < low + k; i++)
			bitonic_compare(array, i, i + k, dir);
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - recursive bitonic sort helper function.
 * @array: array of integers.
 * @low: lowest index of the sequence in array.
 * @cnt: count of elements in sequence.
 * @dir: direction for comparison, 1 for ascending, 0 for descending.
 */
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		size_t k = cnt / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, cnt, dir);
	}
}

/**
 * bitonic_sort - sort an array of integers in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_recursive(array, 0, size, 1);
}
