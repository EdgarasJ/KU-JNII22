#include <stdio.h>

int main() {
    int maxHeigth, minHeigth, groupCount, h, i;
    float avg;
    FILE *input, *output;
    if((input = fopen("heigth.txt", "r")) == NULL){
        printf("Error: Can't open file 'heigth.txt' in read mode.");
        return 1;
    }
    fscanf(input, "%d", &groupCount);
    printf("groupCount: %d \n", groupCount);
    maxHeigth = 0;
    minHeigth = 10000;
    avg = 0;
    for (i = 0; i < groupCount; i++){
        fscanf(input, "%d", &h);
        if (h > maxHeigth) maxHeigth = h;
        if (h < minHeigth) minHeigth = h;
        avg += h;
    }
    fclose(input);
    avg = avg / groupCount;
    if((output = fopen("heigthCh.txt", "w")) == NULL){
        printf("Error: Can't open file 'heigthCh.txt' in write mode.");
        return 1;
    }
    fprintf(output, "Max Heigth: %d \n", maxHeigth);
    fprintf(output, "Min Heigth: %d \n", minHeigth);
    fprintf(output, "Average Heigth: %f \n", avg);
    fclose(output);

    printf("Max Heigth: %d \n", maxHeigth);
    printf("Min Heigth: %d \n", minHeigth);
    printf("Average Heigth: %f \n", avg);
    return 0;
}
