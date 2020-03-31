#include "qs.h"
#include <stdio.h>

int partition(void *base, int low_index, int high_index, size_t size_type, int (*compar)(const void *, const void *)) {

  // The pivot element of the current array/vector
  void *pivot = &high_index;

  //printf("%d", *((int*) pivot));

  // The index of smaller element
  int i = (low_index - size_type);

  for(int j = low_index; j <= (high_index - size_type); j+= size_type) {

    // If the current element is smaller than
    // the pivot element of the current array/vector
    if( compar( (void *) (base + j), pivot ) < 1 ) {

      // Increment the index of the smaller element
      i+= size_type;

      swap((base + i), (base + j), size_type);

    }

  }

  swap((base + i + size_type), &high_index, size_type);

  return (i + size_type);

}

void quick_sort(void *base, int low_index, int high_index, size_t size_type, int (*compar)(const void *, const void *)) {

  printf("%d\n", low_index);
  printf("%d\n", high_index);

  if (low_index < high_index) {

    printf("low_index < high_index");

    int partition_index = partition(base, low_index, high_index, size_type, compar);

    quick_sort(base, low_index, (partition_index - size_type), size_type, compar );
    quick_sort(base, (partition_index + 1), high_index, size_type, compar);

  }

}


////////////////////////////////////////////////////////////////////////////////////////
/// Your own sequential implementation of Quick Sort
void QSORT(void *base, size_t num_elems, size_t size_type, int (*compar)(const void *, const void *)) {

  printf("\n\n");

  printf("Initial array/vector:\n");

  for(int current_elem = 0; current_elem < num_elems; current_elem++) {

    printf( "%lf ", *( (double *) base + current_elem ) );

  }

  printf("\n\n");

  // Your code goes here
  quick_sort(base, 0, (num_elems-1), size_type, compar);

  printf("Final array/vector:\n");

  for(int current_elem = 0; current_elem < num_elems; current_elem++) {

    printf("%lf ", ((double *) &base)[current_elem]);

  }

  printf("\n\n");

}



