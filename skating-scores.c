#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void){
    int no;
    double s1, s2, s3;

    int win_no = 0;
    double win_s = 0;

    while (scanf("%d%lg%lg%lg", &no, &s1, &s2, &s3) != EOF){

        if (s1 < s2 && s1 < s3){
            if (s2+s3/2 > win_s){
                win_s = s2+s3/2;
                win_no = no;
            }
        }else if (s2 < s1 && s2 < s3){
            if (s1+s3/2 > win_s){
                win_s = s1+s3/2;
                win_no = no;
            }
        }else {
            if (s2+s1/2 > win_s){
                win_s = s2+s1/2;
                win_no = no;
            }
        }
    }
    printf("%d\n", win_no);
    
    return EXIT_SUCCESS;
}
