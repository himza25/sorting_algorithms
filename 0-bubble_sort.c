#include "sort.h"

/**
 * bubble_sort - that sort a list
 * @array: the list to sort
 * @size: the size of the list
*/
void bubble_sort(int *array, size_t size)
{
	size_t j = 0, swap, n = size;

	while (size > 0)
	{
		j = 0;
		while (j + 1 < size)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, n);
			}
			j++;
		}
		size--;
	}
}
