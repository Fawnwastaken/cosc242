#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void){
    int n;

    flexarray f = flexarray_new();
    
    while (1 == scanf("%d", &n)){
        flexarray_append(f, n);
    }

    printf("\n");
    flexarray_print(f);

    flexarray_sort(f);

    flexarray_print(f);

    flexarray_free(f);

    return EXIT_SUCCESS;
}
