#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
#include <string.h>

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

static void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

static void *erealloc(void *a, size_t s){
    void *result = realloc(a, s);
    if (NULL == result){
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray f = emalloc(sizeof *f);
    f -> capacity = 2;
    f -> itemcount = 0;
    f -> items = emalloc(f -> capacity * sizeof f -> items[0]);
    return f;
}

void flexarray_append(flexarray f, int num) {
    if (f -> itemcount == f-> capacity){
        f -> capacity += f -> capacity;
        f -> items = erealloc(f -> items, f -> capacity * sizeof f[0]);
    }
    f -> items[f -> itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f -> itemcount; i++){
        printf("%d\n", f -> items[i]);
    }
    printf("\n");
}

void flexarray_sort(flexarray f) {
    int j, i;
    int print;
    int min;
    int n = f -> itemcount;
    int temp;

    int *a = f -> items;

    int key;

    /*selection*/
    
    /*for (j = 0; j < n-1; j++){

        
        min = j;

        
        for (i = j+1; i < n; i++){
            
            if (f -> items[i] < f -> items[min]){
                min = i;
            }
        }

        if (min != j){
            
            temp = f->items[j];
            f -> items[j] = f -> items[min];
            f -> items[min] = temp;
        }

        if (j == (n/2)+1){
            for (print = 0; print < n; print++){
                fprintf(stderr, "%d\n", f -> items[print]);
            }
            printf("\n");
        }
            
        }*/

    /*insertion*/
        
    for (j = 1; j < n; j++){
        
        i = j;
        
        while (i > 0 && a[i-1] > a[i]){

            temp = a[i];
            a[i] = a[i-1];
            a[i-1] = temp;
            
            i--;
        }

        if (j == (n/2)+1){
            for (print = 0; print < n; print++){
                fprintf(stderr, "%d\n", a[print]);
            }
        }
    }
}


void flexarray_free(flexarray f) {
    free(f -> items);
    free(f);
}

