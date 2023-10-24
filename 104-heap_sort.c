#include "sort.h"

void swap_elements(int *elem1, int *elem2);
void build_max_heap(int *arr, size_t arr_size, size_t heap_size, size_t root_idx);
void heap_sort(int *arr, size_t arr_size);

/**
 * swap_elements - Swap two integers in an array.
 * @elem1: First integer to swap.
 * @elem2: Second integer to swap.
 */
void swap_elements(int *elem1, int *elem2)
{
	int tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

/**
 * build_max_heap - Converts a binary tree into a complete max-heap.
 * @arr: Array of integers representing the binary tree.
 * @arr_size: Total size of the array.
 * @heap_size: Size of the heap within the array.
 * @root_idx: Index of the root node in the binary tree.
 */
void build_max_heap(int *arr, size_t arr_size, size_t heap_size,
					size_t root_idx)
{
	size_t left_idx, right_idx, largest_idx;

	left_idx = 2 * root_idx + 1;
	right_idx = 2 * root_idx + 2;
	largest_idx = root_idx;

	if (left_idx < heap_size && arr[left_idx] > arr[largest_idx])
		largest_idx = left_idx;
	if (right_idx < heap_size && arr[right_idx] > arr[largest_idx])
		largest_idx = right_idx;

	if (largest_idx != root_idx) {
		swap_elements(arr + root_idx, arr + largest_idx);
		print_array(arr, arr_size);
		build_max_heap(arr, arr_size, heap_size, largest_idx);
	}
}

/**
 * heap_sort - Sort an integer array in ascending order using heap sort.
 * @arr: Array of integers to sort.
 * @arr_size: Size of the array to sort.
 *
 * Description: Utilizes the sift-down version of the heap sort algorithm.
 * Prints the array after each element swap.
 */
void heap_sort(int *arr, size_t arr_size)
{
	int i;

	if (arr == NULL || arr_size < 2)
		return;

	for (i = (arr_size / 2) - 1; i >= 0; i--)
		build_max_heap(arr, arr_size, arr_size, i);

	for (i = arr_size - 1; i > 0; i--) {
		swap_elements(arr, arr + i);
		print_array(arr, arr_size);
		build_max_heap(arr, arr_size, i, 0);
	}
}
