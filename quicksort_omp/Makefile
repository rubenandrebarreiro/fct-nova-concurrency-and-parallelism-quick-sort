# default values
CC=gcc
CFLAGS=-c -g -std=gnu11 -Wall -Werror
LDFLAGS=

# redefine V with "make V=libc" or "make V=seq" or "make V=omp"
# you may also use "make all" to make the three versions
V=libc

# extra parameters for LIBC qsort
LIBCCC=
LIBCLD=

# extra parameters for SEQ qsort
SEQCC=
SEQLD=

# extra parameters for OMP qsort
OMPCC=-fopenmp
OMPLD=-fopenmp


DIR=src
S=$(shell find $(DIR) -name '*.c' -print)
O=$(shell find $(DIR) -name '*.o' -print)
UC = $(shell echo '$1' | tr '[:lower:]' '[:upper:]')
LC = $(shell echo '$1' | tr '[:upper:]' '[:lower:]')

UV=$(call UC,$(V))

CFLAGS += $($(UV)CC)
LDFLAGS += $($(UV)LD)


TARGET = qs-$(V)

$(TARGET): src/qsbase-$(V).o src/qs-$(V).o
	$(CC) -o $@ $^ $(LDFLAGS)

ALL=libc seq omp
all:
	for i in $(ALL); do make V=$$i; done

src/qsbase-$(V).o: src/qs.c
	$(CC) -o $@ $(CFLAGS) -D$(UV) $^

src/%.o: src/%.c
	$(CC) -o $@ $(CFLAGS) -D$(UV) $^

.PHONY: clean
clean:
	rm -f $(patsubst %,qs-%,$(ALL)) $(O) Makefile.deps

-include Makefile.deps

Makefile.deps:
	$(CC) $(CFLAGS) -MM $(S) > Makefile.deps

