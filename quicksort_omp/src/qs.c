#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <sys/time.h>

#include "qs.h"

//#define TYPE_SET 1   // to work with chars
//#define TYPE_SET 2   // to work with float
//#define TYPE_SET 3   // to work with double
#define TYPE_SET 4   // to work with integer
//#define TYPE_SET 5   // to work with longs
//#define TYPE_SET 6   // to work with strings


////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = char
#if TYPE_SET == 1
#define TYPE        char
#define TYPE_STR    "char"
#define TYPE_PRINT  "%c"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   lrand48()%('z'-'a'+1)+'a';

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
    for (long i = 0; i < N; i++)
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
/// End of stuff for TYPE = char

////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = float
#if TYPE_SET == 2
#define TYPE        float
#define TYPE_STR    "float"
#define TYPE_PRINT  "%f"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   drand48()

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
    for (long i = 0; i < N; i++)
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
/// End of stuff for TYPE = float

////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = double
#if TYPE_SET == 3
#define TYPE        double
#define TYPE_STR    "double"
#define TYPE_PRINT  "%lf"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   drand48() * 10.0

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
    for (long i = 0; i < N; i++)
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
/// Stuff for TYPE = integer
#if TYPE_SET == 4
#define TYPE        int
#define TYPE_STR    "int"
#define TYPE_PRINT  "%d"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   rand() % 100

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
    for (long i = 0; i < N; i++)
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
/// End of stuff for TYPE = integer


////////////////////////////////////////////////////////////////////////////////////////
/// Stuff for TYPE = long
#if TYPE_SET == 5
#define TYPE        long
#define TYPE_STR    "long"
#define TYPE_PRINT  "%ld"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   lrand48()

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
    for (long i = 0; i < N; i++)
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
/// Stuff for TYPE = string[STRSIZE]
#if TYPE_SET == 6
#define TYPE        char *
#define TYPE_STR    "string"
#define TYPE_PRINT  "%s"
#define TYPE_SRAND  srand48(time(NULL))
#define TYPE_RAND   TYPE_new()

#define STRSIZE     20
char *TYPE_new (void) {
    char *p=malloc(STRSIZE+1); // include space for terminating '\0'
    for (int i=0; i < STRSIZE; i++) {   // initialize strings w/ random small caps letters
        p[i] = lrand48()%('z'-'a'+1)+'a';
    }
    p[STRSIZE] = '\0'; // terminate the string
    return p;
}

int TYPE_less_than(const void* a, const void* b) {
    const char *a1 = *(char **)a;
    const char *b1 = *(char **)b;
    return strcmp (a1, b1);
}

void TYPE_DEBUG(const void* array, long N) {
    TYPE *a = (TYPE *)array;
    for (long i = 0; i < N; i++)
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
/// End of stuff for TYPE = string[STRSIZE]




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
        printf ("Usage: ./qs-"VERSION" N\n");
        return -1;
    }

    // get the size of the array
    long N = atol (argv[1]);

    // initialize the array with ranbdom contents of type TYPE
    TYPE* array = malloc (sizeof (*array) * N);
    TYPE_SRAND;
    for (int i = 0; i < N; i++)
        array[i] = TYPE_RAND;

    TYPE_DEBUG(array, N); // comment for larger arrays

    // sort the array using quick sort
    double start = wctime ();
    QSORT(array, N, sizeof (TYPE), TYPE_less_than);
    double end = wctime ();

    // print execution time
    printf ("\nqs-%s\nArray size = %'ld\nWall clock elapsed time = %6.3lf seconds\n\n", VERSION, N, end-start);

    TYPE_DEBUG(array, N); // comment for larger arrays

    // validate that the array is sorted correctly
    TYPE_validate (array, N, TYPE_less_than);

    free (array);

    return 0;
}
