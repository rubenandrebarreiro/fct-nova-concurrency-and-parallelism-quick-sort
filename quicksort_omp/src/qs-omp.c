#include "qs.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int partition(void *base, int low_index, int high_index, size_t size_type, int (*compar)(const void *, const void *)) {

    // The pivot element of the current array/vector
    void *pivot = (void *) (base + (high_index * size_type));

    // The index of smaller element
    int i = (low_index - 1);

    #pragma omp parallel
    {

        // If there's more thant 2 processors available,
        // it will be used
        if( ( omp_get_num_procs() - 2 ) >= ( ( high_index - 1 ) - low_index ) ) {

            omp_set_num_threads( ( ( high_index - 1 ) - low_index ) ) ;

        }

        #pragma omp parallel for
        for(int j = low_index; j <= (high_index - 1); j++) {

            // If the current element is smaller than
            // the pivot element of the current array/vector
            if( compar( (void *) (base + (j * size_type)), pivot ) < 1 ) {

                // Increment the index of the smaller element
                i++;

                swap((base + (i * size_type)), (base + (j * size_type)), size_type);

            }

        }

    }

    swap((base + ( (i + 1) * size_type)), (base + (high_index * size_type)), size_type);

    return (i + 1);

}

void quick_sort(void *base, int low_index, int high_index, size_t size_type, int (*compar)(const void *, const void *)) {

    if (low_index < high_index) {

        int partition_index = partition(base, low_index, high_index, size_type, compar);

        #pragma omp parallel
        {

            // If there's more thant 2 processors available,
            // it will be used
            if(omp_get_num_procs() >= 2) {

                omp_set_num_threads(2);

            }

            #pragma omp sections
            {

                #pragma omp section
                {
                    quick_sort(base, low_index, (partition_index - 1), size_type, compar);
                }

                #pragma omp section
                {
                    quick_sort(base, (partition_index + 1), high_index, size_type, compar);
                }

            }

        }

    }

}


////////////////////////////////////////////////////////////////////////////////////////
/// Your own Parallel OpenMP implementation of Quick Sort
void QSORT(void *base, size_t num_elems, size_t size_type, int (*compar)(const void *, const void *)) {

    // Your code goes here
    quick_sort(base, 0, (num_elems-1), size_type, compar);

}
