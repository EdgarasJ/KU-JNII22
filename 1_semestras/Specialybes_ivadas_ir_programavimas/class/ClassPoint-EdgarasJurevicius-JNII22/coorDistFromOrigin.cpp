#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const bool isWindows=true;
#else
static const bool isWindows=false;
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class Point {
    private:
        int xCoord;
        int yCoord;
        double dist;
    public:
        Point (){}
        Point (int _x, int _y, double _dist){
            xCoord = _x;
            yCoord = _y;
            dist = _dist;
        }
        Point (int _x, int _y) {
            xCoord = _x;
            yCoord = _y;
            dist = sqrt(xCoord * xCoord + yCoord * yCoord);
        }
        void setX(int x){
            xCoord = x;
        }
        void setY(int y){
            yCoord = y;
        }
        void setDistance(double d){
            dist = d;
        }
        int getX(){
            return xCoord;
        }
        int getY(){
            return yCoord;
        }
        double getDistance(){
            return dist;
        }
};

void swapElements(vector<Point>&, int, int);
void shakerSort(vector<Point>&);
string filenameInput(string);
int generateInputContent(string);
int returnSign();

int main(){
    // random seed generacija is dabartinio laiko
    srand(time(NULL));

    bool selected = false;
    char selection;
    // ikoduotas failo pavadinimai, jei bus nenorima ivedineti.
    string inFilename = "input.txt";
    string outFilename = "output-cpp.txt";

    while (!selected){
        cout << "Please, choose Your option:" << endl;
        cout << "1. Manual input of filenames." << endl;
        cout << "2. Automatic filenames: input.txt for input file and output-cpp.txt for output." << endl;
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
    ifstream coordFile;
    coordFile.open(inFilename);
    if (!coordFile.is_open()){
        cerr << "Can't open file " << inFilename << " in reading mode. Check if it exists." << endl;
        return 1;
    }
    // failo turinio apdorojimas ir informacijos sudejimas i Point masyva.
    int coordCount;
    coordFile >> coordCount;
    int xCoord, yCoord;
    vector<Point> points;
    //Point* pts;
    for (int i = 0; i < coordCount; i++){
        coordFile >> xCoord;
        if (coordFile.fail()) break;
        coordFile >> yCoord;
        if (coordFile.fail()) break;
        Point* pts = new Point(xCoord, yCoord);
        points.push_back(*pts);
        delete pts;
    }
    coordFile.close();
    // rusiuojamas Point masyvas pagal atstuma nuo orginalaus tasko.
    shakerSort(points);
    // i output fila irasom tuoliausiai nutolusi nuo tasko (0,0) taska ir ta atstuma.
    ofstream outFile;

    outFile.open(outFilename);
    if (!outFile.is_open()){
        cerr << "Can't open file " << outFilename <<" in writing mode." << endl;
        return 1;
    }
    outFile << "X = " << points.at(coordCount - 1).getX() << " Y = " << points.at(coordCount - 1).getY() << " Distance from origin: " << points.at(coordCount - 1).getDistance();
    outFile.close();
    // i ekrana isvedam taskus ir atstumus surikiuotus pagal atstuma
    cout << setw(5) << right << "X" << setw(5) << right << "Y" << setw(10) << right << "Distance" << endl;
    for (Point pts:points){
        cout << setw(5) << right << pts.getX() << setw(5) << right << pts.getY() << setw(10) << right << fixed << setprecision(4) << pts.getDistance() << endl;
    }

    // rezultato failo atidarymas
    if (isWindows){
        string command = "notepad \""+ outFilename +"\"";
        system(command.c_str());
    }
    //output failo pavadinimo isvedimas i ekrana
    cout << "Output filename: " << outFilename << endl;
    return 0;
    return 0;
}

//failu pavadinimu ivedimas
string filenameInput(string message){
    string result;
    cout << message << endl;
    cin >> result;
    return result;
}

//elementu sukeitimas vietomis
void swapElements(vector<Point>& pts, int index1, int index2){
    Point value = pts.at(index1);
    pts.at(index1) = pts.at(index2);
    pts.at(index2) = value;
}

// rusiavimas patobulintu burbulo metodu (shaker sort)
void shakerSort(vector<Point>& pts){
    bool swapped;
    double value;
    int low = 0;
    int high = pts.size();
    while (true) {
        //perejimas i viena puse
        swapped = false;
        for (int i = low; i < high - 1; i++){
            if (pts.at(i).getDistance() > pts.at(i + 1).getDistance()){
              swapElements(pts, i, i + 1);
              swapped = true;
            }
        }
        if (!swapped) break; // isejimas is pagrindinio while loop
        //perejimas i kita puse
        swapped = false;
        for (int i = high - 2; i >= low; i--){
            if (pts.at(i).getDistance() > pts.at(i + 1).getDistance()){
              swapElements(pts, i, i + 1);
              swapped = true;
            }
        }
        if (!swapped) break; // isejimas is pagrindinio while loop
        low++;
        high--;
    }
}

// ivedimo failo turinio generavimas taskai nuo -99 iki ir nuo 5 iki 104 tasku
int generateInputContent(string filename){
    ofstream file;

    file.open(filename);
    if (!file.is_open()){
        cerr << "Can't open file " << filename <<" in writing mode." << endl;
        return 1;
    }

    int pointCount = (rand()%100) + 5;
    file << pointCount << endl;
    int sign = 1;
    for (int i = 0; i < pointCount; i++){
        file << (rand() % 100)* returnSign() << " " << (rand() % 100)* returnSign() << endl;
    }
    file.close();
    return 0;
}

// random zenklo generacija
int returnSign(){
    if (rand()%2 == 0) return 1;
    return -1;
}
