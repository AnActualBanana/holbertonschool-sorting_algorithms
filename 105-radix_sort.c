#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 10
#define get_digit(num, place) (num / (int)pow(BASE, place) % BASE)

void radix_sort(int *array, size_t size) {
  int max = array[0];
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  int num_digits = (int)log10(max) + 1;
  int *temp = malloc(size * sizeof(int));

  for (int place = 0; place < num_digits; place++) {
    int count[BASE] = {0};

    for (size_t i = 0; i < size; i++) {
      count[get_digit(array[i], place)]++;
    }

    for (int i = 1; i < BASE; i++) {
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
      int digit = get_digit(array[i], place);
      temp[--count[digit]] = array[i];
    }

    for (size_t i = 0; i < size; i++) {
      array[i] = temp[i];
    }

    printf("Sorted array after significant digit %d:\n", place + 1);
    for (size_t i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
  }

  free(temp);
}
