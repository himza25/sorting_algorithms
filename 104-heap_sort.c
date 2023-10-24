#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 *            using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i, size);
	}
}

/**
 * sift_down - Sifts down the element at index `start` to its proper
 *            position in the heap, thereby converting the binary tree
 *            rooted at index `start` into a max heap.
 * @array: The heap.
 * @start: The index of the element to sift down.
 * @end: The index representing the 'size' of the heap.
 * @size: The total size of the array (needed for printing).
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while ((root * 2) + 1 < end)
	{
		child = (root * 2) + 1;
		if (child + 1 < end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			int temp = array[root];

			array[root] = array[child];
			array[child] = temp;
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Converts the array into a max heap.
 * @array: The array to be converted.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size, size);
		start--;
	}
}

