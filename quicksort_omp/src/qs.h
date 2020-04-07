#ifndef QS_H
#define QS_H

#include <stdlib.h>


#if defined(SEQ)
#define VERSION "seq"
#define QSORT qsort_seq
#elif defined(OMP)
#define VERSION "omp"
#define QSORT qsort_omp
#else
#define VERSION "libc"
#define QSORT qsort
#endif


void swap (void *a, void *b, size_t width);

void QSORT(void *base, size_t nel, size_t width,
           int (*compar)(const void *, const void *));

#endif /* QS_H */