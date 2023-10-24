#include "sort.h"
#include <stdio.h>

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * initialize_count - Initialize count array to zero.
 * @count: The count array.
 * @max: The maximum integer in the array.
 */
void initialize_count(int *count, int max)
{
	int i;

	for (i = 0; i <= max; i++)
		count[i] = 0;
}

/**
 * fill_count - Fill the count array.
 * @count: The count array.
 * @array: The original array.
 * @size: Size of the array.
 */
void fill_count(int *count, int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
}

/**
 * cumulative_count - Calculate cumulative sum of the count array.
 * @count: The count array.
 * @max: The maximum integer in the array.
 */
void cumulative_count(int *count, int max)
{
	int i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	initialize_count(count, max);
	fill_count(count, array, size);
	cumulative_count(count, max);
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

