#include "sort.h"

/**
 * swap_elements - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * merge_bitonic_seq - Sort a bitonic sequence in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence.
 * @seq: The size of the sequence.
 * @dir: The direction to sort in.
 */
void merge_bitonic_seq(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, step = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + step; i++)
		{
			if ((dir == UP && array[i] > array[i + step]) ||
			    (dir == DOWN && array[i] < array[i + step]))
				swap_elements(array + i, array + i + step);
		}
		merge_bitonic_seq(array, size, start, step, dir);
		merge_bitonic_seq(array, size, start + step, step, dir);
	}
}

/**
 * create_bitonic_seq - Create a bitonic sequence in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a sequence block.
 * @seq: The size of a sequence block.
 * @dir: The direction to sort the sequence block in.
 */
void create_bitonic_seq(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t half = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		create_bitonic_seq(array, size, start, half, UP);
		create_bitonic_seq(array, size, start + half, half, DOWN);
		merge_bitonic_seq(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * sort_bitonic - Sort array using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void sort_bitonic(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	create_bitonic_seq(array, size, 0, size, UP);
}
