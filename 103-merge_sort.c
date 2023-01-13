#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - sorts an array of integers in ascending order using Merge sort.
 * @start: starting indexfor the left array
 * @middle: end index for the left array and
 * starting index for the right array
 * @end: end index for the right array
 * @dest: destination for new array
 * @source: input array
 *
 * Return: void
 */
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - recursively splits the array and merges the sorted arrays
 * @start: starting index
 * @end: end index
 * @array: the array to sort
 * @copy: a copy of the array
 *
 * Return: void
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
