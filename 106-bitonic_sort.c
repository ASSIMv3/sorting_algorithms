#include "sort.h"

/**
 * compare_swap - Compare and swap two elements in the array based on direction
 * @array: Pointer to the integer array
 * @i: Index of the first element to compare
 * @j: Index of the second element to compare
 * @dir: Direction flag (1 for ascending, 0 for descending)
 */
void compare_swap(int *array, size_t i, size_t j, int dir)
{
	int temp;

	if (dir == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * bitonic_merge - Perform bitonic merge on the array
 * @array: Pointer to the integer array
 * @size: Size of the array
 * @low: Starting index of the merge
 * @cnt: Number of elements to merge
 * @dir: Direction flag (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t low,
		size_t cnt, int dir)
{
	size_t i, k = cnt / 2;

	if (cnt > 1)
	{
		for (i = low; i < low + k; i++)
		{
			compare_swap(array, i, i + k, dir);
		}
		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Perform bitonic sort recursively on the array
 * @array: Pointer to the integer array
 * @size: Size of the array
 * @low: Starting index of the range to be sorted
 * @cnt: Number of elements in the range to be sorted
 * @dir: Direction flag (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low,
		size_t cnt, int dir)
{
	size_t k = cnt / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", cnt, size, str);
		print_array(array + low, cnt);

		bitonic_sort_recursive(array, size, low, k, 1);
		bitonic_sort_recursive(array, size, low + k, k, 0);
		bitonic_merge(array, size, low, cnt, dir);

		printf("Result [%lu/%lu] (%s):\n", cnt, size, str);
		print_array(array + low, cnt);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in bitonic order using
 *			Bitonic Sort algorithm
 * @array: Pointer to the integer array to be sorted
 * @size: Size of the array
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}
