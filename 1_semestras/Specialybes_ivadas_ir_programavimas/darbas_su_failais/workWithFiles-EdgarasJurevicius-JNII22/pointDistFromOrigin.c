#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

struct Point {
    int x;
    int y;
    double distance;
};

void filenameInput(char[], char*);
int generateInputContent(char[]);
int returnSign();
void swapElements(struct Point[], int, int);
void shakerSort(struct Point[], int);

main(){
    // random seed generacija is dabartinio laiko
    srand(time(NULL));
    FILE *input, *output;
    char inFilename[40], outFilename[40];
    // ikoduotas failo pavadinimai, jei bus nenorima ivedineti.
    strcpy(inFilename, "input.txt");
    strcpy(outFilename, "output-c.txt");

    bool selected = false;
    char selection;

    while (!selected){
        printf("Please, choose Your option:\n");
        printf("1. Manual input of filenames.\n");
        printf("2. Automatic filenames: input.txt for input file and output-c.txt for output.\n");
        printf("Press q or Q to quit a program.\n");
        scanf("%c", &selection);
        switch (selection){
            case 'q': case 'Q':
                return 0;
                break;
            case '1':
                selected = true;
                filenameInput("Please submit an input file name:", inFilename);
                filenameInput("Please submit an output file name:", outFilename);
                break;
            case '2':
                selected = true;
                break;
            default:
                printf("Error: unknown command %c.", selection);
        }
    }

    selected = false;
    int errorCode;
    char sel;

    while (!selected){
        printf("Please, choose Your option:\n");
        printf("1. Generate random input file content.\n");
        printf("2. Continue with original input file content.\n");
        printf("Press q or Q to quit a program.\n");
        scanf("%c", &sel);
        switch (sel){
            case 'q': case 'Q':
                return 0;
                break;
            case '1':
                selected = true;
                errorCode = generateInputContent(inFilename);
                if (errorCode > 0) {
                    printf("Error. Couldn't generate input file content.\n");
                    system("pause");
                    return 1;
                }
                break;
            case '2':
                selected = true;
                break;
            default:
                printf("Error: unknown command '%c'.", sel);
        }
    }

    // failo atidarymas
    if((input = fopen(inFilename, "r")) == NULL){
        printf("Error: Can't open file '%s' in read mode.", inFilename);
        system("pause");
        return 1;
    }
    // failo turinio apdorojimas ir informacijos sudejimas i Point masyva.
    int coordCount;
    fscanf(input, "%d", &coordCount);
    int xCoord, yCoord;
    struct Point points[coordCount];
    struct Point pts;
    int i;
    for (i = 0; i < coordCount; i++){
        fscanf(input, "%d", &xCoord);
        pts.x = xCoord;
        fscanf(input, "%d", &yCoord);
        pts.y = yCoord;
        pts.distance = sqrt(xCoord * xCoord + yCoord * yCoord);
        points[i]= pts;
    }
    fclose(input);
    // rusiuojamas Point masyvas pagal atstuma nuo orginalaus tasko.
    shakerSort(points, coordCount);
    // i output fila irasom tuoliausiai nutolusi nuo tasko (0,0) taska ir ta atstuma.
    if((output = fopen(outFilename, "w")) == NULL){
        printf("Error: Can't open file '%s' in write mode.", outFilename);
        system("pause");
        return 1;
    }
    fprintf(output, "X =  %d, Y = %d, Distance from Origin: %f \n", points[coordCount - 1].x, points[coordCount - 1].y, points[coordCount - 1].distance);
    fclose(output);
    // i ekrana isvedam taskus ir atstumus surikiuotus pagal atstuma
    char s1[5] = "X";
    char s2[5] = "Y";
    char s3[10] = "Distance";
    printf("%5s %5s %10s \n", s1, s2, s3);
    for (i = 0; i < coordCount; i++){
        struct Point pts = points[i];
        printf("%5d %5d %10f \n", pts.x, pts.y, pts.distance);
    }
    system("pause");
    return 0;

}

//failu pavadinimu ivedimas
void filenameInput(char message[], char *result){
    printf("%s \n", message);
    scanf("%s", result);
}

// ivedimo failo turinio generavimas taskai nuo -99 iki ir nuo 5 iki 104 tasku
int generateInputContent(char filename[]){
    FILE *output;

    if((output = fopen(filename, "w")) == NULL){
        printf("Error: Can't open file '%s' in write mode.", filename);
        return 1;
    }

    int pointCount = (rand()%100) + 5;
    fprintf(output, "%d \n", pointCount);
    int sign = 1;
    int i;
    for (i = 0; i < pointCount; i++){
        fprintf(output, "%d %d\n", (rand() % 100)* returnSign(), (rand() % 100)* returnSign());
    }
    fclose(output);
    return 0;
}

// random zenklo generacija
int returnSign(){
    if (rand()%2 == 0) return 1;
    return -1;
}

//elementu sukeitimas vietomis
void swapElements(struct Point pts[], int index1, int index2){
    struct Point value = pts[index1];
    pts[index1] = pts[index2];
    pts[index2] = value;
}

// rusiavimas patobulintu burbulo metodu (shaker sort)
void shakerSort(struct Point pts[], int coordCount){
    bool swapped;
    double value;
    int low = 0;
    int high = coordCount;
    int i;
    while (true) {
        //perejimas i viena puse
        swapped = false;
        for (i = low; i < high - 1; i++){
            if (pts[i].distance > pts[i + 1].distance){
              swapElements(pts, i, i + 1);
              swapped = true;
            }
        }
        if (!swapped) break; // isejimas is pagrindinio while loop
        //perejimas i kita puse
        swapped = false;
        for (i = high - 2; i >= low; i--){
            if (pts[i].distance > pts[i + 1].distance){
              swapElements(pts, i, i + 1);
              swapped = true;
            }
        }
        if (!swapped) break; // isejimas is pagrindinio while loop
        low++;
        high--;
    }
}
