#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: Pointer to the original array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t middle;
	int *temp_array;

	if (size <= 1)
		return;

	middle = size / 2;
	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;

	merge_sort(array, middle);
	merge_sort(array + middle, size - middle);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);

	printf("[right]: ");
	print_array(array + middle, size - middle);

	for (size_t i = 0; i < size; i++)
		temp_array[i] = array[i];

	merge(array, temp_array, middle, temp_array + middle, size - middle);

	printf("[Done]: ");
	print_array(array, size);

	free(temp_array);
}
