/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_elements(int *first, int *second);
void merge_bitonic(int *arr, size_t arr_size, size_t idx_start,
	size_t sub_len, char orientation);
void build_bitonic(int *arr, size_t arr_size, size_t idx_start,
	size_t sub_len, char orientation);

/**
 * swap_elements - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_elements(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * merge_bitonic - Sort a bitonic sequence within an array.
 * @arr: Array of integers.
 * @arr_size: Size of the array.
 * @idx_start: Starting index of sequence to sort.
 * @sub_len: Size of sequence to sort.
 * @orientation: Direction to sort in.
 */
void merge_bitonic(int *arr, size_t arr_size, size_t idx_start,
	size_t sub_len, char orientation)
{
	size_t i, step = sub_len / 2;

	if (sub_len > 1)
	{
		for (i = idx_start; i < idx_start + step; i++)
		{
			if ((orientation == UP && arr[i] > arr[i + step]) ||
				(orientation == DOWN && arr[i] < arr[i + step]))
				swap_elements(arr + i, arr + i + step);
		}
		merge_bitonic(arr, arr_size, idx_start, step, orientation);
		merge_bitonic(arr, arr_size, idx_start + step, step, orientation);
	}
}

/**
 * build_bitonic - Convert an array into a bitonic sequence.
 * @arr: Array of integers.
 * @arr_size: Size of the array.
 * @idx_start: Starting index of block.
 * @sub_len: Size of block.
 * @orientation: Direction to sort block in.
 */
void build_bitonic(int *arr, size_t arr_size, size_t idx_start,
	size_t sub_len, char orientation)
{
	size_t half = sub_len / 2;
	char *str = (orientation == UP) ? "UP" : "DOWN";

	if (sub_len > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sub_len, arr_size, str);
		print_array(arr + idx_start, sub_len);
		build_bitonic(arr, arr_size, idx_start, half, UP);
		build_bitonic(arr, arr_size, idx_start + half, half, DOWN);
		merge_bitonic(arr, arr_size, idx_start, sub_len, orientation);
		printf("Result [%lu/%lu] (%s):\n", sub_len, arr_size, str);
		print_array(arr + idx_start, sub_len);
	}
}

/**
 * bitonic_sort - Sort an array of integers using bitonic sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	build_bitonic(array, size, 0, size, UP);
}
