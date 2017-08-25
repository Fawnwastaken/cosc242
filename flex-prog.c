#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

int main(void){

    /*initiate item and build empty flexarray*/
    int item;
    flexarray my_flex = flexarray_new();

    /*append input to array while there is input*/
    while (1 == scanf("%d", &item)){
        flexarray_append(my_flex, item);
    }


    /*print the array, then free it*/
    flexarray_sort(my_flex);

    flexarray_print(my_flex);
    
    flexarray_free(my_flex);

    return EXIT_SUCCESS;
}
