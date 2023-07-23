#include "sort.h"

/**
 * get_max_digit - Get the maximum number of digits in the array
 * @array: Pointer to the integer array
 * @size: Size of the array
 *
 * Description: This function calculates and returns the max number of digits
 * in the elements of the array.
 *
 * Return: The maximum number of digits in the array elements.
 */
int get_max_digit(int *array, size_t size)
{
	int max = array[0];
	int digit_count;
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	digit_count = 0;
	while (max != 0)
	{
		max /= 10;
		digit_count++;
	}
	return (digit_count);
}

/**
 * counting_sort_by_digit - Sorts an array of integers using Counting
 * Sort by a specific digit
 * @array: Pointer to the integer array to be sorted
 * @size: Size of the array
 * @exp: The current digit place (10^i) for sorting
 *
 * Description: This function sorts the array of int based on a specific digit
 * using Counting Sort algorithm.
 */
void counting_sort_by_digit(int *array, size_t size, int exp)
{
	int counting_array[10] = {0};
	int *output = malloc(size * sizeof(int));
	int i;

	if (!output)
	{
		return;
	}

	for (i = 0; i < (int)size; i++)
		counting_array[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		counting_array[i] += counting_array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[counting_array[(array[i] / exp) % 10] - 1] = array[i];
		counting_array[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix
 *		Sort algorithm
 * @array: Pointer to the integer array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_digit, exp;

	if (size <= 1)
		return;

	max_digit = get_max_digit(array, size);

	for (exp = 1; max_digit > 0; exp *= 10, max_digit--)
	{
		counting_sort_by_digit(array, size, exp);
		print_array(array, size);
	}
}
