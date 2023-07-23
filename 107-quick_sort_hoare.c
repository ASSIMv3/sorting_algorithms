#include "sort.h"

/**
 * swap - Swaps two integer values using pointers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Performs Hoare partition for Quick Sort algorithm
 *
 * @array: Pointer to the integer array
 * @size: Size of the array
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: void
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i, j;

	for (i = low - 1, j = high + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * hoare_sort - Sorts a subarray using Hoare partition in Quick Sort algorithm
 *
 * @array: Pointer to the integer array
 * @size: Size of the array
 * @low: The starting index of the subarray to sort
 * @high: The ending index of the subarray to sort
 *
 * Return: void
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (high - low > 0)
	{
		pivot_idx = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, pivot_idx - 1);
		hoare_sort(array, size, pivot_idx, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using Quick Sort algorithm
 *
 * @array: Pointer to the integer array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
