#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"
#include "flexarray.h"
#include "quicksort.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

/*if array is full then increase its capacity and add the new item, or just add it*/
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity; /*increase capacity*/
        f-> items  = erealloc(f->items, f->capacity * sizeof f[0]); /*realloc memory*/
    }
    f->items[f->itemcount++] = num;/*add item to next appendix*/
}

/*print each item in the array*/
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}

/*sort the array via quicksort*/
void flexarray_sort(flexarray f) {
    clock_t start, end;
    start = clock();
    quicksort(f->items, 0, f->itemcount);
    end = clock();
    fprintf(stderr, "%d %f\n", f->itemcount, (end-start)/(double)CLOCKS_PER_SEC);
}

/*free all items in the flexarray*/
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
