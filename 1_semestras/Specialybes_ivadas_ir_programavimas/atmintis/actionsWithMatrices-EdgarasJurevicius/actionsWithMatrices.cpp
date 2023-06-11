#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const bool isWindows=true;
#else
static const bool isWindows=false;
#endif


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

string filenameInput(string);
int generateInputContent(string);
int returnSign();
void printMatrix(int[], int);
void transpose(int[], int[], int);
void maxElemIndexes(int[], int);
void matrixSum(int[], int[], int[], int);
void matrixProduct(int[], int[], int[], int);
void writeAnswer(string, string, int[], int, bool);

int main(){
    // random seed generacija is dabartinio laiko
    srand(time(NULL));

    bool selected = false;
    char selection;
    // ikoduotas failo pavadinimai, jei bus nenorima ivedineti.
    string inFilename = "inputMatrices.txt";
    string outFilename = "outputMatrices.txt";


    while (!selected){
        cout << "Please, choose Your option:" << endl;
        cout << "1. Manual input of filenames." << endl;
        cout << "2. Automatic filenames: input.txt for input file and output.txt for output." << endl;
        cout << "Press q or Q to quit a program." << endl;
        cin >> selection;
        switch (selection){
            case 'q': case 'Q':
                return 0;
                break;
            case '1':
                selected = true;
                inFilename = filenameInput("Please submit an input file name:");
                outFilename = filenameInput("Please submit an output file name:");
                break;
            case '2':
                selected = true;
                break;
            default:
                cout << "Error: unknown command '" << selection << "'." << endl;
        }
    }

    selected = false;
    int errorCode;

    while (!selected){
        cout << "Please, choose Your option:" << endl;
        cout << "1. Generate random input file content." << endl;
        cout << "2. Continue with original input file content." << endl;
        cout << "Press q or Q to quit a program." << endl;
        cin >> selection;
        switch (selection){
            case 'q': case 'Q':
                return 0;
                break;
            case '1':
                selected = true;
                errorCode = generateInputContent(inFilename);
                if (errorCode > 0) {
                    cout << "Error. Couldn't generate input file content." << endl;
                    return 1;
                }
                break;
            case '2':
                selected = true;
                break;
            default:
                cout << "Error: unknown command '" << selection << "'." << endl;
        }
    }

    // failo atidarymas
    ifstream matrixFile;
    matrixFile.open(inFilename);
    if (!matrixFile.is_open()){
        cerr << "Can't open file " << inFilename << " in reading mode. Check if it exists." << endl;
        return 1;
    }
    // failo turinio apdorojimas ir informacijos sudejimas i matricu masyvus.
    int squareMatrixDimension;
    matrixFile >> squareMatrixDimension;
    int sqMatrix1[squareMatrixDimension*squareMatrixDimension];
    int sqMatrix2[squareMatrixDimension*squareMatrixDimension];
    // pirmos matricos nuskaitymas
    for (int i = 0; i < squareMatrixDimension*squareMatrixDimension; i ++){
        matrixFile >> sqMatrix1[i];
    }
    // ignouojama tuscia eilute tart matricu
    matrixFile.seekg(matrixFile.tellg() + 1);
    // antros matricos nuskaitymas
    for (int i = 0; i < squareMatrixDimension*squareMatrixDimension; i++){
        matrixFile >> sqMatrix2[i];
    }
    matrixFile.close();

    int transposeMatrix[squareMatrixDimension*squareMatrixDimension];
    cout << "************* Transpose of Matrix *************" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(sqMatrix1, squareMatrixDimension);
    cout << "Matrix Transpose:" << endl;
    transpose(sqMatrix1, transposeMatrix, squareMatrixDimension);
    printMatrix(transposeMatrix, squareMatrixDimension);
    cout << "*********** Biggest element indexes ***********" << endl;
    maxElemIndexes(sqMatrix1, squareMatrixDimension);
    cout << "*************** Sum of Matrices ***************" << endl;
    int matSum[squareMatrixDimension*squareMatrixDimension];
    matrixSum(sqMatrix1, sqMatrix2, matSum, squareMatrixDimension);
    cout << "First Matrix:" << endl;
    printMatrix(sqMatrix1, squareMatrixDimension);
    cout << "Second Matrix:" << endl;
    printMatrix(sqMatrix2, squareMatrixDimension);
    cout << "Sum of First and Second Matrices:" << endl;
    printMatrix(matSum, squareMatrixDimension);
    cout << "************* Product of Matrices *************" << endl;
    int matrixProd[squareMatrixDimension*squareMatrixDimension];
    matrixProduct(sqMatrix1, sqMatrix2, matrixProd, squareMatrixDimension);
    cout << "First Matrix:" << endl;
    printMatrix(sqMatrix1, squareMatrixDimension);
    cout << "Second Matrix:" << endl;
    printMatrix(sqMatrix2, squareMatrixDimension);
    cout << "Product of First and Second Matrices:" << endl;
    printMatrix(matrixProd, squareMatrixDimension);
    // rezultatu irasymas i faila
    writeAnswer(outFilename, "Transposed Matrix:", transposeMatrix, squareMatrixDimension, true);
    writeAnswer(outFilename, "Sum of Matrices:", matSum, squareMatrixDimension, false);
    writeAnswer(outFilename, "Product of Matrices:", matrixProd, squareMatrixDimension, false);
    // rezultato failo atidarymas
    if (isWindows){
        string command = "notepad \""+ outFilename +"\"";
        system(command.c_str());
    }
    //output failo pavadinimo isvedimas i ekrana
    cout << "Output filename: " << outFilename << endl;
    return 0;
}

//failu pavadinimu ivedimas
string filenameInput(string message){
    string result;
    cout << message << endl;
    cin >> result;
    return result;
}

// ivedimo failo turinio generavimas elementai nuo -99 iki 99 ir nuo 2 iki 101 stulpelio/eiluciu
int generateInputContent(string filename){
    ofstream file;

    file.open(filename);
    if (!file.is_open()){
        cerr << "Can't open file " << filename <<" in writing mode." << endl;
        return 1;
    }

    int squareMatrixDimension = (rand()%100) + 2;
    file << squareMatrixDimension << endl;
    for (int i = 0; i < squareMatrixDimension; i++){
        for (int j = 0; j < squareMatrixDimension; j++){
            file << setw(8) << (rand() % 100)* returnSign() << " ";
        }
        file << endl;
    }
    file << endl;
    for (int i = 0; i < squareMatrixDimension; i++){
        for (int j = 0; j < squareMatrixDimension; j++){
            file << setw(8) << (rand() % 100)* returnSign() << " ";
        }
        file << endl;
    }
    file.close();
    return 0;
}

// random zenklo generacija
int returnSign(){
    if (rand()%2 == 0) return 1;
    return -1;
}

// matricos isvedimas i ekrana
void printMatrix(int matrix[], int matrixDim){
    cout << "     ";
    for (int i = 0; i < matrixDim; i++){
        cout << setw(8) << i+1;
    }
    cout << endl << setfill('-') << setw(8*matrixDim+5) << "" << setfill(' ') << endl;
    for (int i = 0; i < matrixDim*matrixDim; i += matrixDim){
        cout << setw(2) << i / matrixDim + 1 << " | ";
        for (int j = i; j < matrixDim + i; j++){
            cout << setw(8) << matrix[j];
        }
        cout << endl;
    }
}

// matricos transponavimas
void transpose(int original[], int transposed[], int dimension){
    int lineCount = 0;
    int index;
    for (int i = 0; i < dimension*dimension; i += dimension){
        for (int j = i; j < dimension + i; j++){
            if (lineCount == 0) {
                transposed[j] = original[j * dimension];
            } else {
                index = (j*dimension)%((dimension*dimension - 1)*lineCount);
                if (index == 0) {
                    transposed[j] = original[j];
                } else {
                    transposed[j] = original[index];
                }
            }
        }
        lineCount++;
    }
}

// matricos didziausio elemento ir jo indeksu radimas ir spausdinimas
void maxElemIndexes(int sqMatrix[], int squareMatrixDimension){
    int maxElem = sqMatrix[0];
    int lnIndex = 0;
    int colIndex = 0;
    cout << "Original Matrix:" << endl;
    cout << "     ";
    for (int i = 0; i < squareMatrixDimension; i++){
        cout << setw(5) << i+1;
    }
    cout << endl << setfill('-') << setw(5*squareMatrixDimension+5) << "" << setfill(' ') << endl;
    for (int i = 0; i < squareMatrixDimension*squareMatrixDimension; i += squareMatrixDimension){
        cout << setw(2) << i / squareMatrixDimension + 1 << " | ";
        for (int j = i; j < squareMatrixDimension + i; j++){
            cout << setw(5) << sqMatrix[j];
            if (sqMatrix[j] > maxElem) {
                maxElem = sqMatrix[j];
                lnIndex = i;
                colIndex = j;
            }
        }
        cout << endl;
    }
    lnIndex = lnIndex / squareMatrixDimension;
    colIndex = colIndex % squareMatrixDimension;
    cout << "Biggest Matrix element is: " << maxElem << " at line: " << lnIndex + 1 << " and column: " << colIndex + 1 << endl;
}

// matricu sumavimas
void matrixSum(int sqMatrix1[], int sqMatrix2[], int matrixSum[], int squareMatrixDimension){
    for (int i = 0; i < squareMatrixDimension*squareMatrixDimension; i++){
        matrixSum[i] = sqMatrix1[i] + sqMatrix2[i];
    }
}

// matricu daugyba
void matrixProduct(int sqMatrix1[], int sqMatrix2[], int matrixProduct[], int squareMatrixDimension){
    int prod = 0;
    int lineCount = 0;
    int index;
    int colStart, colCount, lineStart;
    for (int i = 0; i < squareMatrixDimension*squareMatrixDimension; i += squareMatrixDimension){
        colCount = 0;
        for (int j = i; j < squareMatrixDimension + i; j++){
            prod = 0;
            colStart = lineCount*squareMatrixDimension;
            lineStart = j%squareMatrixDimension;
            for (int k = colStart; k < colStart + squareMatrixDimension; k++){

                prod += sqMatrix1[k] * sqMatrix2[lineStart];
                lineStart += squareMatrixDimension;

            }
            matrixProduct[j] = prod;
            colCount++;
        }
        lineCount++;
    }
}

// atsakymu irasymas i faila
void writeAnswer(string filename, string message, int matrix[], int dimension, bool firstTime) {
    ofstream outFile;
    if (firstTime){
        outFile.open(filename);
    } else {
        outFile.open(filename, ios_base::app);
    }
    if (!outFile.is_open()){
        cerr << "Can't open file " << filename <<" in writing mode." << endl;
        return;
    }
    outFile << message << endl;
    outFile << "     ";
    for (int i = 0; i < dimension; i++){
        outFile << setw(8) << i+1;
    }
    outFile << endl << setfill('-') << setw(8*dimension+5) << "" << setfill(' ') << endl;
    for (int i = 0; i < dimension*dimension; i += dimension){
        outFile << setw(2) << i / dimension + 1 << " | ";
        for (int j = i; j < dimension + i; j++){
            outFile << setw(8) << matrix[j];
        }
        outFile << endl;
    }
    outFile << endl;
    outFile.close();
}
