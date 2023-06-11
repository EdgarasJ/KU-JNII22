#include <iostream>
#include <cmath>

using namespace std;

//Grigaliaus kalendorius ivestas 1583 m.

bool isGrLeapYear(int);
bool isJulLeapYear(int);
void parseDate(string[], string, char);
unsigned int daysBetweenYears(int, int, bool);
unsigned int daysUntilDate(int, int, int, bool);

const unsigned int YEAR_CHANGE = 1583;

int main() {

    string input1, input2;
    cout << "Iveskite pirma data (Pvz.: 2000-01-01): ";
    cin >> input1;
    cout << "Iveskite antra data (Pvz.: 2001-01-01): ";
    cin >> input2;

    //Nors nesimokinome, bet idejau stringu parsinga su arrays. (Uzduoties algoritmui dideles itakos nedaro).

    string dateStr1[3], dateStr2[3];
    parseDate(dateStr1, input1, '-');
    parseDate(dateStr2, input2, '-');

    int year1 = stoi(dateStr1[0]);
    int month1 = stoi(dateStr1[1]);
    int day1 = stoi(dateStr1[2]);
    int year2 = stoi(dateStr2[0]);
    int month2 = stoi(dateStr2[1]);
    int day2 = stoi(dateStr2[2]);

    unsigned int sumOfDays;

    if (year1 < YEAR_CHANGE && year2 < YEAR_CHANGE) { // Jeigu taikomas tik Julijaus kalendorius
        sumOfDays = daysBetweenYears(year1, year2, true) - daysUntilDate(year1, month1, day1, true) + daysUntilDate(year2, month2, day2, true);
    } else if (year1 >= YEAR_CHANGE && year2 >= YEAR_CHANGE) { // Jeigu taikomas tik Grigaliaus kalendorius
        sumOfDays = daysBetweenYears(year1, year2, false) - daysUntilDate(year1, month1, day1, false) + daysUntilDate(year2, month2, day2, false);
    } else { // Jeigu taikomi abu kalendoriai
        sumOfDays = daysBetweenYears(year1, year2, true) - daysUntilDate(year1, month1, day1, true) + daysUntilDate(YEAR_CHANGE, 1, 1, true);
        sumOfDays += sumOfDays = daysBetweenYears(YEAR_CHANGE, year2, false) - daysUntilDate(YEAR_CHANGE, 1, 1, false) + daysUntilDate(year2, month2, day2, false);
    }


    cout << "Dienu skaicius: " << sumOfDays << endl;

    return 0;
}

// Grigaliaus kalendoriaus keliamu metu tikrinimas
bool isGrLeapYear(int year) {

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) return true;

    return false;

}

// Julijaus kalendoriaus keliamu metu tikrinimas
bool isJulLeapYear(int year) {

    return year % 4 == 0;

}

// stringu parsingas
void parseDate(string date[3], string str, char delim) {
    size_t pos = 0;
    int i = 0;
    while ((pos = str.find(delim)) != string::npos) {
        date[i] = str.substr(0, pos);
        i++;
        str.erase(0, pos + 1);
    }
    date[2] = str;
}

// skaiciuojamas dienu skaicius tarp duotu metu.
unsigned int daysBetweenYears(int year1, int year2, bool isJulian){
    unsigned int sum = 0;
    for (int i = year1; i < year2; i++) {
        if (isJulian) {
            if (isJulLeapYear(i)) sum += 366;
            else sum+= 365;
        } else {
            if (isGrLeapYear(i)) sum += 366;
            else sum+= 365;
        }
    }
    return sum;
}

// skaiciuojamas dienu skaicius nuo metu pradzios iki nurodytos menesio dienos.
unsigned int daysUntilDate(int year, int month, int day, bool isJulian){
    unsigned int sum = 0;
    for (int i = 1; i < month; i++) {
        switch (i) {
        case 2:
            if (isJulian) {
                if (isJulLeapYear(year)) sum += 29;
                else sum += 28;
            } else {
                if (isGrLeapYear(year)) sum += 29;
                else sum += 28;
            }
            break;
        case 4: case 6: case 9: case 11:
            sum += 30;
            break;
        default:
            sum += 31;
        }
    }
    sum += day;
    return sum;
}
