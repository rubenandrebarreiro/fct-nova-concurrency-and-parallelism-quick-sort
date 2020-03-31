#include "qs.h"


////////////////////////////////////////////////////////////////////////////////////////
/// Your own sequential implementation of Quick Sort
void QSORT(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {
    // Your code goes here
    qsort(base, nel, width, compar);
}

