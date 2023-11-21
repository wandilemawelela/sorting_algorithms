#include "sort.h"

/**
 * swap - Function to swap two elements in the array
 * @a: First integer
 * @b: Second interger
 *
 * Return: Nothing
 *
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Low base case
 * @high: High base case
 *
 * Return: Always 0 (Success)
 *
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive quick sort fucntion
 * @array: Array to be sorted
 * @low: Low base case
 * @high: High base case
 *
 * Return: Nothing
 *
 */

void quick_sort_recursive(int *array, int low, int high)
{
	int pivotIndex, i;

	if (low < high)
	{
		pivotIndex = partition(array, low, high);

		quick_sort_recursive(array, low, pivotIndex - 1);
		quick_sort_recursive(array, pivotIndex + 1, high);

		for (i = low; i <= high; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

/**
 * quick_sort - Wrapper function for quick_sort_recursive
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 *
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1);
}
