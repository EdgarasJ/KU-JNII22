#include <stdio.h>

int main (){
    float * rod1 = (float*) 200;
    float * rod2 = (float*) 100;
    printf("Orig rod1: %d\n", rod1);
    printf("Orig rod2: %d\n", rod2);
    rod1 += 10;
    printf("rod1 += 10: %d\n", rod1);
    rod2++;
    printf("rod2++ : %d\n", rod2);
    printf("rod1-rod2: %d\n", rod1-rod2);
    return 0;
}
