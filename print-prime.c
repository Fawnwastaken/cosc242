#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int is_prime(int n){
    int i;
    for (i = 2 ; i < n/2 + 1 ; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}

int main (void) {
    int n = 2;
    int num_printed = 0;
    while (num_printed < 200){
        if (is_prime(n) == 1){
            printf("%d", n);
            num_printed++;
            if (num_printed % 10 == 0){
                printf("\n");
            } else {
                printf("\t");
            }
        }
        n++;
    }

    return EXIT_SUCCESS;
}
