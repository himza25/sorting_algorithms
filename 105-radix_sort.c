#include "sort.h"

/**
 * get_max - get maximum value in array
 * @array: array
 * @size: size of array
 * Return: maximum element in array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_for_radix - modified counting sort for radix sort
 * @array: array to sort
 * @size: size of array
 * @exp: current digit's positional value
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - sorts an array using radix sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_for_radix(array, size, exp);
}
