/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Pointer to array of integers
 * @size: Size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, i, max = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	fill_output(count, output, array, size, max);

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
