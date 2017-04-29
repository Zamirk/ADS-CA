
// X00110033: Samir Kahvedzic
// X00109340: Shajun Dominic
// Comp 1
//

using namespace std;
#include <stdlib.h>
#include <windows.h>
#include "fileDetails.h"
using std::array;
#include <iostream>
#include <limits>
#include <string>



void fileDetails::addName(string a) {
    names[numberOfFiles] = a;
    numberOfFiles++;
}

void fileDetails::addHash(size_t a, int b) {
    hash[b] = a;
}

void fileDetails::setDir(string a) {
    filesDirectory = a;
    // Setting everyone to null when changing directory
    for (int n =0; n< 10; n++) {
        names[n] = "";
        hash[n] = 0;
        similarity[n] = 0;
        totalMatchingLines[n] = 0;
        lineCount[n] = 0;
        contents[n] = "";
        for (int i = 0; i < 10; i++) {
            matchingLinesCount[i][n] = NULL;
            statementCount[i][n] = 0;
        }
    }
    numberOfFiles = 0;
}

void fileDetails::matchingLines(int a, int b, int c) {
    matchingLinesCount[a][b] = c;
}

// Printing
void fileDetails::print() {
    // Matching Lines Graph
    cout << "\t\t\tF1 = file 1, F2.., ect." << endl;
    cout << "\t\t\tGraph of matching Lines" << endl;
    cout << "\t\t\t\t";
    for (int n =2; n <= numberOfFiles; n++) {
        cout << "F[" << n << "]" << "\t";
    }
    cout << "" << endl;
    for (int n = 1; n <= numberOfFiles; n++) {
        cout << "\t\t\t";
        cout << "F["<< n << "]";
        for (int i = 1; i <= numberOfFiles; i++) {
            if (matchingLinesCount[n-1][i-1] != NULL) {
                cout << "[" << matchingLinesCount[n-1][i-1] << "]\t";
            } else {
                cout << "\t";
            }
        }
        cout << endl;
    }
    // Printing out total lines matched.
    cout << "\t\t\t\tTotal matched lines" << endl;
    for (int p = 1; p <= numberOfFiles; p++) {
        cout << "\t\t\t\tFile "<< p <<" :" << totalMatchingLines[p-1] << endl;
    }
}

void fileDetails::printAll() {
    // Showing Files
    red();
    cout << "\t\t<>";
    grey();
    // Directory
    cout << "\tDirectory";
    normal();
    cout << ": " << filesDirectory;
    red();
    // Formatting fix
    if (filesDirectory.length() < 5) {
        cout << "\t\t\t\t<>";
    } else if (filesDirectory.length() < 13) {
        cout << "\t\t\t<>";
    } else if (filesDirectory.length() < 21) {
        cout << "\t\t<>";
    } else if (filesDirectory.length() < 29) {
        cout << "\t<>";
    } else if (filesDirectory.length() < 30) {
        cout << "<>";
    }
    cout << "\n\t\t<>";
    grey();
    cout << "\tNumber of files";
    normal();
    cout << ": " << numberOfFiles << "\t\t\t";
    red();
    cout << "<>\n\t\t";
    for (int i = 0; i < numberOfFiles; i++) {
        red();
        cout << "<>";
        grey();
        cout << "\t\tFile " << i + 1;
        normal();
        cout << ":\t" << names[i];
        red();
        // Names formatting fix
        if (names[i].length() < 8) {
            cout << "\t\t\t<>\n\t\t";
        } else if (names[i].length() < 16) {
            cout << "\t\t<>\n\t\t";
        } else if (names[i].length() < 24) {
            cout << "\t<>\n\t\t";
        } else {
            cout << "\n\t\t";
        }
    }
}

void fileDetails::printHash() {
    cout <<"\t\t\tHash Values." << endl;
    for (int n = 1; n <= numberOfFiles; n++) {
        cout << "\t\t\t\tFile " << n << ": " << hash[n-1] << endl;
    }
}

void fileDetails::printLineCount() {
    cout << "\t\t\tLine Counts Values." << endl;
    for (int n = 1; n <= numberOfFiles; n++) {
        cout << "\t\t\t\tFile " << n << ": " <<lineCount[n-1] << endl;
    }
}

void fileDetails::printIterations() {
    normal();
    cout << "\n\t\t\t\tif \twhile \tfor \tdo" << endl;
    green();
    for (int n = 1; n <= numberOfFiles; n++) {
        normal();
        cout << "\t\t\tF ["<< n << "]";
        green();
        for (int m = 0; m < 4; m++) {
            cout << "\t" << statementCount[n-1][m];
        }
        cout << endl;
    }
    normal();
    cout <<"\n\t\t\t\tint \tdouble \tstring \tchar" << endl;
    green();
    for (int n = 1; n <= numberOfFiles; n++) {
        normal();
        cout << "\t\t\tF ["<< n <<"]";
        green();
        for (int m = 4; m < 8; m++) {
            cout << "\t" << statementCount[n-1][m];
        }
        cout << endl;
    }
    normal();
}

void fileDetails::printSimilarityIndex() {
    cout << "\t\t\t\t Similarity Index." << endl;
    cout << "\t\t\t\tHash\tPlagiarised Lines" << endl;
    for (int n = 0; n < numberOfFiles; n++) {
        string value = "0%";
        for (int m = 0; m < numberOfFiles; m++) {
            string value = "0%";
            int hashValue = hash[n];
            int hashValue2 = hash[m];
            if (hashValue == hashValue2) {
                value = "100%";
            }
            if (m == n) {
                value = "0%";
            }

        }
        cout << "\t\t\tFile [" << n+1 << "]: " <<
        value <<"\t\t" << totalMatchingLines[n] << endl;
    }
}

// Colours
void fileDetails::green() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

void fileDetails::red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void fileDetails::normal() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void fileDetails::grey() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}
