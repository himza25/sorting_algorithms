#include "sort.h"
#include <stdio.h>

/**
 * fill_output - Fills the output array using the counting array
 * @count: Counting array
 * @output: Output array
 * @array: Original array
 * @size: Size of the array
 * @max: Maximum element in the array
 */
void fill_output(int *count, int *output, int *array, size_t size, int max)
{
	int i;

	/* Build the output array */
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
}

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Pointer to array of integers
 * @size: Size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, i, max = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	fill_output(count, output, array, size, max);

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
