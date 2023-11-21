#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Sixe of the array
 *
 * Return: Nothing
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, tmp;

	if (array == NULL || size == 0)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
			{
				k = j;
				continue;
			}
		}

		if (k != i)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
