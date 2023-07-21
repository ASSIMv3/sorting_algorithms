#include "sort.h"

/**
 * find_max - Finds the maximum element in an array of integers
 *
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: The maximum element found in the array
 */
int find_max(int *array, int size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, i, *counting_array, *temp_arr;

	if (!array || size < 2)
		return;

	max = find_max(array, size);
	counting_array = malloc((max + 1) * sizeof(int));
	if (!counting_array)
		return;

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;
	for (i = 0; i < (max + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);

	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		temp_arr[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = temp_arr[i];

	free(temp_arr), free(counting_array);
}
