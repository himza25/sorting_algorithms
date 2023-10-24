#include "sort.h"

void combineArrays(int *src, int *buf, size_t st, size_t md, size_t en);
void sortHelper(int *src, int *buf, size_t st, size_t en);

/**
 * combineArrays - Sort a subarray of integers.
 * @src: The source subarray.
 * @buf: Buffer to store sorted values.
 * @st: The start index.
 * @md: Middle index.
 * @en: The end index.
 */
void combineArrays(int *src, int *buf, size_t st, size_t md, size_t en)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(src + st, md - st);
	printf("[right]: ");
	print_array(src + md, en - md);

	for (i = st, j = md; i < md && j < en; k++)
		buf[k] = (src[i] < src[j]) ? src[i++] : src[j++];
	for (; i < md; i++)
		buf[k++] = src[i];
	for (; j < en; j++)
		buf[k++] = src[j];
	for (i = st, k = 0; i < en; i++)
		src[i] = buf[k++];

	printf("[Done]: ");
	print_array(src + st, en - st);
}

/**
 * sortHelper - Recursive function for merge sort.
 * @src: The source subarray.
 * @buf: Buffer to store sorted values.
 * @st: Start index.
 * @en: End index.
 */
void sortHelper(int *src, int *buf, size_t st, size_t en)
{
	size_t md;

	if (en - st > 1)
	{
		md = st + (en - st) / 2;
		sortHelper(src, buf, st, md);
		sortHelper(src, buf, md, en);
		combineArrays(src, buf, st, md, en);
	}
}

/**
 * merge_sort - The main merge sort function.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	sortHelper(array, buf, 0, size);

	free(buf);
}

