
// X00110033: Samir Kahvedzic
// X00109340: Shajun Dominic
// Comp 1
//

#ifndef UNTITLED_FILEDETAILS_H
#define UNTITLED_FILEDETAILS_H

#include <array>
using namespace std;
using std::array;
#include <string>

class fileDetails {
public:
    void setDir(string a);
    void addName(string a);
    void addHash(size_t a, int b);
    void printAll();
    void printHash();
    void matchingLines(int a, int b, int c);
    void print();
    void printLineCount();
    void printIterations();
    void printSimilarityIndex();
    void green();
    void red();
    void normal();
    void grey();

public:
    string filesDirectory = "";
    int numberOfFiles = 0;
    string names[10];
    double similarity[10];
    size_t hash[10];
    int matchingLinesCount[10][10];
    int totalMatchingLines[10];
    int lineCount[10];
    string contents[10];
    int statementCount[10][10];
};



#endif

// UNTITLED_FILEDETAILS_H
