#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

#include "qs.h" 


#define TYPE_SET    1   // to work with doubles
// #define TYPE_SET    2   // to work with longs
// #define TYPE_SET    3, 4, ..., to whatever types you find interesting



////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = double
#if TYPE_SET == 1
#define TYPE        double
#define TYPE_STR    "double"
#define TYPE_PRINT  "%lf"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   drand48

int TYPE_less_than(const void* a, const void* b) {
    TYPE v1 = *(TYPE *)a;
    TYPE v2 = *(TYPE *)b;

    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

void TYPE_DEBUG(const void* array, long N) {
    TYPE *a = (TYPE *)array;
    for (long i = 0; i < N-1; i++)
        printf ("%ld = "TYPE_PRINT"\n", i, a[i]);
}

void TYPE_validate(const void* array, long N, int (*compar)(const void *, const void *)) {
    TYPE *a = (TYPE *)array;
    for (long i = 0; i < N-1; i++)
        if (TYPE_less_than(&a[i], &a[i+1]) == 1) {
            printf ("\nValidation TYPE(%s) failed at position %ld = "TYPE_PRINT", "TYPE_PRINT"\n\n", TYPE_STR, i, a[i], a[i+1]);
            // TYPE_DEBUG(a, N);
            exit(1);
        }
}
#endif
/// End of stuff for TYPE = double

////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = long
#if TYPE_SET == 2
#define TYPE        long
#define TYPE_STR    "long"
#define TYPE_PRINT  "%ld"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   lrand48

int TYPE_less_than(const void* a, const void* b) {
    TYPE v1 = *(TYPE *)a;
    TYPE v2 = *(TYPE *)b;

    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

void TYPE_DEBUG(const void* array, long N) {
    TYPE *a = (TYPE *)array;
    for (long i = 0; i < N-1; i++)
        printf ("%ld = "TYPE_PRINT"\n", i, a[i]);
}

void TYPE_validate(const void* array, long N, int (*compar)(const void *, const void *)) {
    TYPE *a = (TYPE *)array;
    for (long i = 0; i < N-1; i++)
        if (TYPE_less_than(&a[i], &a[i+1]) == 1) {
            printf ("\nValidation TYPE(%s) failed at position %ld = "TYPE_PRINT", "TYPE_PRINT"\n\n", TYPE_STR, i, a[i], a[i+1]);
            // TYPE_DEBUG(a, N);
            exit(1);
        }
}
#endif
/// End of stuff for TYPE = long



////////////////////////////////////////////////////////////////////////////////////////
/// Get wall clock time as a double
double wctime () {
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return tv.tv_sec + 1E-6 * tv.tv_usec;
}



////////////////////////////////////////////////////////////////////////////////////////
/// swap elements from array
void swap (void *a, void *b, size_t width) {

    char buffer[width];

    memcpy (buffer, a, width);

    memcpy (a, b, width);
    memcpy (b, buffer, width);

}



////////////////////////////////////////////////////////////////////////////////////////
/// main
int main (int argc, char* argv[]) {
    if (argc != 2) {
            printf ("Usage: ./quicksort-seq N\n");
        return -1;
    }

    // get the size of the array
    long N = atol (argv[1]);
    
    // initialize the array with ranbdom contents of type TYPE
    TYPE* array = malloc (sizeof (*array) * N);
    TYPE_SRAND;
    for (int i = 0; i < N; i++)
        array[i] = TYPE_RAND ();

    // sort the array using quick sort
    double start = wctime ();
    QSORT(array, N, sizeof (*array), TYPE_less_than);
    double end = wctime ();

    // print execution time
    printf ("\nQuickSort %s\nArray size = %'ld\nWall clock elapsed time = %6.3lf seconds\n\n", VERSION, N, end-start);
    
    // validate that the array is sorted correctly
    TYPE_validate (array, N, TYPE_less_than);
    
    free (array);

    return 0;
}
