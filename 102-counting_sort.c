#include "sort.h"
#include <stdio.h>

/**
 * find_max - Find max element in an array
 * @array: The array
 * @size: The size of the array
 * @max: The max element
 */
void find_max(int *array, size_t size, int *max)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > *max)
			*max = array[i];
	}
}

/**
 * count_elements - Count occurrences of each distinct element
 * @array: The array
 * @size: The size of the array
 * @count: The count array
 * @max: The max element
 */
void count_elements(int *array, size_t size, int *count, int max)
{
	size_t i;

	for (i = 0; i < size; i++)
		count[array[i]]++;
}

/**
 * cum_sum - Calculate the cumulative sum of the array
 * @count: The count array
 * @max: The max element
 */
void cum_sum(int *count, int max)
{
	int i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * counting_sort - Sorts using the counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, *count = NULL, *output = NULL;
	size_t i;

	if (size < 2)
		return;

	find_max(array, size, &max);
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	count_elements(array, size, count, max);
	cum_sum(count, max);
	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
