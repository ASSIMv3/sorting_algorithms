#include "sort.h"

/**
 * sift_down - Perform sift down operation on the heap
 * @array: Pointer to the integer array representing the heap
 * @start: Index of the root node to start sifting down
 * @end: Index of the last node in the heap
 * @size: Size of the array/heap
 *
 * Description: This function performs the sift down operation on the heap
 * to maintain the heap property.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child;
	int temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child += 1;

		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;

			print_array(array, size);

			root = child;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *		using Heap Sort algorithm
 * @array: Pointer to the integer array to be sorted
 * @size: Size of the array
 *
 * Description: function sorts an array of integers using Heap Sort algorithm
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
