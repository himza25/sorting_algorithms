#include "sort.h"

/**
 * merge - Merges two sub-arrays of integers.
 * @array: The array of integers.
 * @temp: The temp array to hold sorted integers.
 * @left: The left index of the sub-array.
 * @mid: The middle index to divide the sub-array.
 * @right: The right index of the sub-array.
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	i = left;
	j = mid;
	k = left;

	while (i < mid && j <= right)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid + 1);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_split - Splits the array and calls merge function.
 * @array: The array of integers.
 * @temp: The temp array to hold sorted integers.
 * @left: The left index of the sub-array.
 * @right: The right index of the sub-array.
 */
void merge_split(int *array, int *temp, int left, int right)
{
	int mid;

	if (right > left)
	{
		mid = (right + left) / 2;

		merge_split(array, temp, left, mid);
		merge_split(array, temp, mid + 1, right);

		merge(array, temp, left, mid + 1, right);
	}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	merge_split(array, temp, 0, size - 1);

	free(temp);
}
