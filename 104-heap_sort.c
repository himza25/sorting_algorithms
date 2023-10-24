#include "sort.h"

void swap_elements(int *x, int *y);
void max_heap(int *arr, size_t sz, size_t hs, size_t rt);
void heapify_sort(int *arr, size_t sz);

/**
 * swap_elements - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_elements(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * max_heap - Turn a binary tree into a complete binary heap.
 * @arr: An array of integers representing a binary tree.
 * @sz: The size of the array/tree.
 * @hs: The index of the base row of the tree.
 * @rt: The root node of the binary tree.
 */
void max_heap(int *arr, size_t sz, size_t hs, size_t rt)
{
	size_t l, r, lg;

	l = 2 * rt + 1;
	r = 2 * rt + 2;
	lg = rt;

	if (l < hs && arr[l] > arr[lg])
		lg = l;
	if (r < hs && arr[r] > arr[lg])
		lg = r;

	if (lg != rt)
	{
		swap_elements(arr + rt, arr + lg);
		print_array(arr, sz);
		max_heap(arr, sz, hs, lg);
	}
}

/**
 * heapify_sort - Sort an array of integers in ascending order
 *               using the heap sort algorithm.
 * @arr: An array of integers.
 * @sz: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heapify_sort(int *arr, size_t sz)
{
	int i;

	if (arr == NULL || sz < 2)
		return;

	for (i = (sz / 2) - 1; i >= 0; i--)
		max_heap(arr, sz, sz, i);

	for (i = sz - 1; i > 0; i--)
	{
		swap_elements(arr, arr + i);
		print_array(arr, sz);
		max_heap(arr, sz, i, 0);
	}
}
