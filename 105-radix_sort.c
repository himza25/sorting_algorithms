#include "sort.h"

int highest_value(int *list, int sz);
void counting_step(int *list, size_t sz, int digit, int *temp_buf);
void radix_sort(int *list, size_t sz);

/**
 * highest_value - Obtain the largest integer in an array.
 * @list: The integer array.
 * @sz: The array size.
 *
 * Return: Largest integer in the array.
 */
int highest_value(int *list, int sz)
{
	int high, i;

	for (high = list[0], i = 1; i < sz; i++)
	{
		if (list[i] > high)
			high = list[i];
	}

	return (high);
}

/**
 * counting_step - Implement counting sort per digit.
 * @list: The integer array.
 * @sz: The array size.
 * @digit: The digit place to be sorted.
 * @temp_buf: Temporary array to store sorted output.
 */
void counting_step(int *list, size_t sz, int digit, int *temp_buf)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < sz; i++)
		count[(list[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = sz - 1; (int)i >= 0; i--)
	{
		temp_buf[count[(list[i] / digit) % 10] - 1] = list[i];
		count[(list[i] / digit) % 10]--;
	}

	for (i = 0; i < sz; i++)
		list[i] = temp_buf[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order.
 * @list: The integer array.
 * @sz: The array size.
 *
 * Description: This function uses the LSD Radix Sort algorithm.
 * It prints the array after sorting it by each digit.
 */
void radix_sort(int *list, size_t sz)
{
	int high_val, dig, *temp_buf;

	if (list == NULL || sz < 2)
		return;

	temp_buf = malloc(sizeof(int) * sz);
	if (temp_buf == NULL)
		return;

	high_val = highest_value(list, sz);
	for (dig = 1; high_val / dig > 0; dig *= 10)
	{
		counting_step(list, sz, dig, temp_buf);
		print_array(list, sz);
	}

	free(temp_buf);
}
