#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes_forward(listint_t **list, listint_t **end,
		listint_t **current);
void swap_nodes_backward(listint_t **list, listint_t **end,
		listint_t **current);
void cocktail_sort_list(listint_t **list);
int find_max(int *array, int size);
void counting_sort(int *array, size_t size);
void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
int get_max_digit(int *array, size_t size);
void counting_sort_by_digit(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void compare_swap(int *array, size_t i, size_t j, int dir);
void bitonic_merge(int *array, size_t size, size_t low,
		size_t cnt, int dir);
void bitonic_sort_recursive(int *array, size_t size, size_t low,
		size_t cnt, int dir);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* MAIN_H */
