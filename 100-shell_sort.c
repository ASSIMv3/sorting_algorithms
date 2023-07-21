#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t h, i, j;
	int temp;

	if (!array || size < 2)
		return;

	h = 1;
	while (h < size / 3)
		h = h * 3 + 1;

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
