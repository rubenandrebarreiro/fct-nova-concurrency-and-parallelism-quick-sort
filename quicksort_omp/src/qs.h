#ifndef QS_H
#define QS_H

#include <stdlib.h>


#if defined(SEQ)
#define VERSION "SEQ"
#define QSORT qsort_seq
#elif defined(OMP)
#define VERSION "OMP"
#define QSORT qsort_omp
#else
#define VERSION "LIBC"
#define QSORT qsort
#endif



void QSORT(void *base, size_t nel, size_t width, 
           int (*compar)(const void *, const void *));
         
#endif /* QS_H */