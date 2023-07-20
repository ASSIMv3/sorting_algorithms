#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}

/**
 * quicksort - Recursively sorts a partition of the array
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Return: void
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);
		quicksort(array, size, low, pivot_idx - 1);
		quicksort(array, size, pivot_idx + 1, high);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto's partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Return: void
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
