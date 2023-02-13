#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

#define BUCKETS 10
#define GET_DIGIT(x, y) (((x) / (int)pow(10, y)) % 10)

/**
 * radix_sort - sorts an array of integers in ascending order using radix sort
 * @array: the array to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
    int i, j, k, digit, m = 0, n = 0;
    listint_t *buckets[BUCKETS];
    listint_t *tmp, *head, *tail;

    if (!array || size < 2)
        return;

    for (i = 0; i < (int)size; i++)
    {
        tmp = malloc(sizeof(*tmp));
        if (!tmp)
            return;
        tmp->n = array[i];
        tmp->prev = tmp->next = NULL;
        buckets[0] = tmp;
        n++;
        for (j = 0; j < n; j++)
        {
            head = tail = buckets[j];
            while (tail->next)
                tail = tail->next;
            for (k = 0; k < BUCKETS; k++)
                buckets[k] = NULL;
            n = 0;
            while (head)
            {
                digit = GET_DIGIT(head->n, m);
                if (!buckets[digit])
                {
                    buckets[digit] = head;
                    n++;
                }
                else
                {
                    tail = buckets[digit];
                    while (tail->next)
                        tail = tail->next;
                    tail->next = head;
                }
                tmp = head->next;
                head->next = NULL;
                head = tmp;
            }
        }
        m++;
        n = 0;
        for (k = 0; k < BUCKETS; k++)
        {
            head = buckets[k];
            while (head)
            {
                array[n++] = head->n;
                tmp = head;
                head = head->next;
                free(tmp);
            }
        }
        print_array(array, size);
    }
}
