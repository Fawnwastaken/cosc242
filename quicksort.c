#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

void quicksort (int* a, int low, int high){
    int pivot;
    int i;
    int j;
    int temp;

    if (high-low<2){
        return;
    }

    pivot = a[low];
    i = low-1;
    j = high;
    
    for (;;){
        do{
            i++;
        }while (a[i] < pivot);
        do{
            j--;
        }while (a[j] > pivot);
        if ( i < j ){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }

    quicksort(a, low, j);
    quicksort(a, j+1, high);
}
