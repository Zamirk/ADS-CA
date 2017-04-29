// X00110033: Samir Kahvedzic
// X00109340: Shajun Dominic
// Comp 1
//
#pragma comment(lib, "winmm.lib")
#include <functional>
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include "main.h"
#include <windows.h>
#include "fileDetails.h"
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleTitle("Plagiarism Detector \t\t\t by X00110033, X00109340");
    fileDetails myFiles;

    enterDirectory(myFiles);
    while (true) {
        displayMenu(myFiles);
    }
    return 0;
}

/***************************************************************************************

*    Usage: Largely Based On
*    Title: Dirent.h
*    Author: Gabehabe
*    Availability: http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/
*
***************************************************************************************/

void enterDirectory(fileDetails &myFiles) {
    system("cls");
    welcome();
    string a = "";
    red();
    cout << "\t\t<>";
    grey();
    cout << "\tDirectory";
    normal();
    cout << ": " <<"C:\\files (Example)";
    red();
    cout << "\t\t<>" << endl;
    red();
    cout << "\t\t<>";
    green();
    cout << "\tPlease enter a directory.";
    red();
    cout << "\t\t<>\n\t\t<>\t\t\t\t\t\t<>" << endl;
    cout << "\t\t<>\t\t\t\t\t\t<>" << endl;
    cout << "\t\t<>\t\t\t\t\t\t<>" << endl;
    normal();
    cout << "\t\t<>Run 2(Compare Test) before viewing Reports\t<>" << endl;
    red();
    cout << "\t\t<>\t\t\t\t\t\t<>" << endl;
    cout << "\t\t<>\t\t\t\t\t\t<>" << endl;
    cout << "\t\t<>\t\t\t\t\t\t<>" << endl;
    cout << "\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cout << "\t\t";
    cin >> a;
    myFiles.setDir(a);

    const char * myDir = a.c_str();
    int n = 0;

    DIR *pdir = NULL;
    pdir = opendir(myDir);
    struct dirent *pent = NULL;

    while(pent = readdir(pdir)) {
        n++;
        if (n >= 3) {
            string a = pent->d_name;
            myFiles.addName(a);
        }
    }
    closedir(pdir);
};

void displayMenu(fileDetails &myFiles) {
    system("cls");
    welcome();
    int option = 0;
    red();
    cout << "\t\t<>";
    grey();
    cout << "\tDirectory";
    normal();
    cout << ": " <<myFiles.filesDirectory;
    red();
    if (myFiles.filesDirectory.length() <5) {
        cout << "\t\t\t\t<>";
    } else if (myFiles.filesDirectory.length() <13) {
        cout << "\t\t\t<>";
    } else if (myFiles.filesDirectory.length() <21) {
        cout << "\t\t<>";
    } else if (myFiles.filesDirectory.length() <29) {
        cout << "\t<>";
    } else if (myFiles.filesDirectory.length() <30) {
        cout << "<>";
    }
    cout<< "\n\t\t<>";
    red();
    cout << "\t\t\t\t\t\t<>\n\t\t<>";
    green();
    cout << "\t1";
    normal();
    cout << ") Showfiles";
    red();
    cout << "\t\t\t\t<>\n\t\t";
    cout << "<>";
    green();
    cout << "\t2";
    normal();
    cout << ") Compare Files";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    green();
    cout << "\t3";
    normal();
    cout << ") Change Directory ";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    green();
    cout << "\t4";
    normal();
    cout << ") View Reports ";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    green();
    cout << "\t5";
    normal();
    cout << ") Exit";
    red();
    cout << "\t\t\t\t\t<>\n\t\t<>";
    green();
    cout << "\t\tSelect an option";
    red();
    cout << "\t\t<>\n\t\t<>\t\t\t\t\t\t<>";
    cout << "\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> option;

    // Selecting on main menu

    if (option == 1) {
        option1(myFiles);
    } else if (option == 2) {
        option2(myFiles);
    } else if (option == 3) {
        enterDirectory(myFiles);
    } else if (option == 4) {
        report(myFiles);
    } else if (option == 5) {
        exit();
    }
}

void option1(fileDetails &myFiles) {
    system("cls");
    welcome();
    myFiles.printAll();
    red();
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    selectAnOption(myFiles);
};

void option2(fileDetails &myFiles) {
    system("cls");
    welcome();

    // Making sure that directory is correct

    string a = myFiles.filesDirectory;
    const char * myDir = a.c_str();
    chdir(myDir);

    // Displaying current directory

    red();
    cout << "\t\t<>";
    grey();
    cout << "\tDirectory";
    normal();
    cout << ": " << myFiles.filesDirectory;
    red();
    if (myFiles.filesDirectory.length() <5) {
        cout << "\t\t\t\t<>";
    } else if (myFiles.filesDirectory.length() <13) {
        cout << "\t\t\t<>";
    } else if (myFiles.filesDirectory.length() <21) {
        cout << "\t\t<>";
    } else if (myFiles.filesDirectory.length() <29) {
        cout << "\t<>";
    } else if (myFiles.filesDirectory.length() <30) {
        cout << "<>";
    }
    cout<< "\n\t\t<>";
    // Running tests
    normal();
    cout << "\tTest 1: Hash Values.";
    red();
    cout << "\t\t\t<>" << endl;
    normal();
    hashTest(myFiles);
    red();
    cout << "\t\t<>";
    normal();
    cout << "\tTest 2: Plagiarised Lines Test.";
    red();
    cout << "\t\t<>" << endl;
    normal();
    linesSimilarityTest(myFiles);
    red();
    cout << "\t\t<>";
    normal();
    cout << "\tTest 3: Iteration Test.";
    red();
    cout << "\t\t\t<>" << endl;
    normal();
    iterationTest(myFiles);
    red();
    cout << "\t\t<>";
    normal();
    cout << "\tTest 4: Lines Count Test.";
    red();
    cout << "\t\t<>" <<endl;
    normal();
    lineCountTest(myFiles);
    red();
    cout << "\t\t<>";
    normal();
    cout << "\tTests are complete. Please view report.";
    red();
    cout << "\t<>" << endl;
    cout << "\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    selectAnOption(myFiles);
}

/***************************************************************************************

*    Usage: Based On
*    Title: Hash Values
*    Author: NA
*    Availability: http://en.cppreference.com/w/cpp/utility/hash
*
***************************************************************************************/

void hashTest(fileDetails &myFiles) {
    // ** READING THE FIRST FILE **
    for (int n = 0; n < myFiles.numberOfFiles; n++) {
        std::ifstream in1(myFiles.names[n]);
        std::string contents1((std::istreambuf_iterator<char>(in1)),
                              std::istreambuf_iterator<char>());

        hash<char *> ptr_hash;
        hash<std::string> str_hash;
        size_t h1 = std::hash<std::string>()(contents1);
        myFiles.addHash(h1, n);
    }
}

void lineCountTest(fileDetails &myFiles) {
    for (int z = 0; z < myFiles.numberOfFiles; z++) {
        ifstream file;
        file.open(myFiles.names[z], ios::binary);

        // ---------- getting number of lines in files ------------------
        string str;
        int lines = 0;
        file.clear();   //  sets a new value for the error control state
        file.seekg(0, ios::beg);

        while (!file.eof()) {
            getline(file, str);
            lines++;
        }
        // Filling array with values
        myFiles.lineCount[z] = lines;
        file.clear();   //  sets a new value for the error control state
        file.seekg(0, ios::beg);
    }
}

/***************************************************************************************

*    Usage: Based On
*    Title: Comparing lines between 2 files
*    Author: jrok
*    Availability: http://stackoverflow.com/questions/8222563/reading-and-comparing-lines-from-a-text-file%20
*
***************************************************************************************/
void linesSimilarityTest(fileDetails &myFiles) {
    int nFiles = myFiles.numberOfFiles;
    char string1[256], string2[256];
    int fileToTotal = 1;

    // Getting a file to compare.
    for (int z = 1; z <= nFiles; z++) {
        // Comparing it with another file.
        for (int x = z + 1; x <= nFiles; x++) {
            ifstream file1;
            file1.open(myFiles.names[z-1], ios::binary);
            int lineMatchCount = 0;

            // Getting a line of file Z to compare.
            while (!file1.eof()) {
                file1.getline(string1, 256);
                // cout<<"Comparing: "<<string1<<endl;

                ifstream file2;
                file2.open(myFiles.names[x-1], ios::binary);

                // Getting a line of file X to compare.
                while (!file2.eof()) {
                    file2.getline(string2, 256);

                    // If the lines are the same, the count increases.
                    if (strcmp(string1, string2) == 0) {
                        lineMatchCount++;
                    }
                }
                file2.clear();
                file2.seekg(0, ios::beg);
            }
            // Glitch, last line of a file is always
            // matched with last one of other file.
            // Due to this, match count is decreased, last lines are ignored.
            lineMatchCount = lineMatchCount-1;
            file1.clear();
            file1.seekg(0, ios::beg);

            // Creating the line match map for test 3.
            myFiles.matchingLines(z-1, x-1, lineMatchCount);
            // Totaling matched lines, for individual files.
            if (z == fileToTotal || x == fileToTotal) {
                myFiles.totalMatchingLines[x-1] += lineMatchCount;
                myFiles.totalMatchingLines[z-1] += lineMatchCount;
            }
        }
        fileToTotal++;
    }
}
/***************************************************************************************

*    Usage: Based On
*    Title: Occurrence of a pattern or word
*    Author: Ali Akber
*    Availability: http://stackoverflow.com/questions/27615157/count-a-specific-word-in-string-in-c
*
***************************************************************************************/
void iterationTest(fileDetails &myFiles) {
    for (int z = 0; z < myFiles.numberOfFiles; z++) {
        // Filling an array with file contents
        std::ifstream file(myFiles.names[z]);
        std::string str;
        std::string file_contents;
        while (std::getline(file, str)) {
            file_contents += str;
            file_contents.push_back('\n');
        }
        myFiles.contents[z] = file_contents;
        string contents = myFiles.contents[z];

        // Statements which are being checked
        string sta1 = "if";
        string sta1a = "if(";

        string sta2 = "while";
        string sta2a = "while(";

        string sta3 = "for";
        string sta3a = "for(";
        string sta3b = "for(int";

        string sta4 = "do";

        string sta5 = "int";
        string sta6 = "double";
        string sta7 = "string";
        string sta8 = "char";

        stringstream ss(contents);
        int sCnt1 = 0;
        int sCnt2 = 0;
        int sCnt3 = 0;
        int sCnt4 = 0;
        int sCnt5 = 0;
        int sCnt6 = 0;
        int sCnt7 = 0;
        int sCnt8 = 0;

        while (ss >> contents) {
            if (contents == sta1||contents == sta1a) {
                sCnt1++;
            }

            if (contents == sta2|| contents == sta2a) {
                sCnt2++;
            }

            if (contents == sta3||contents == sta3a||contents == sta3b) {
                sCnt3++;
            }

            if (contents == sta4) {
                sCnt4++;
            }

            if (contents == sta5) {
                sCnt5++;
            }

            if (contents == sta6) {
                sCnt6++;
            }

            if (contents == sta7) {
                sCnt7++;
            }

            if (contents == sta8) {
                sCnt8++;
            }
        }
        int arrayOfCounts[8] = {sCnt1, sCnt2, sCnt3,
                                sCnt4, sCnt5, sCnt6, sCnt7, sCnt8};
        // Passing counts into myfiles object
        for (int n = 0; n <8; n++) {
            myFiles.statementCount[z][n] = arrayOfCounts[n];
        }
    }
};

void welcome() {
    cout << "\n\n\n";
    red();
    cout << "\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>\n\t\t<>";
    green();
    cout << "\t\tPlagiarism detector\t\t";
    red();
    cout << "<>\t\t\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
}
void selectAnOption(fileDetails &myFiles) {
    int option = 0;
    red();
    cout << "\t\t<>";
    green();
    cout << "\t\tSelect an option";
    red();
    cout << "\t\t<>" << endl;
    cout << "\t\t<>";
    green();
    cout << "    1";
    normal();
    cout << ") Back";
    green();
    cout << "\t\t\t    2";
    normal();
    cout << ") Exit";
    red();
    cout << "\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> option;
    if (option == 1) {
        displayMenu(myFiles);
    } else if (option == 2) {
        exit();
    }
}

void selectAnOption2(fileDetails &myFiles) {
    int option = 0;
    red();
    cout<< "\t\t<>";
    green();
    cout << "\t\tSelect an option";
    red();
    cout << "\t\t<>" << endl;
    cout << "\t\t<>";
    green();
    cout << "    1";
    normal();
    cout << ") Back";
    green();
    cout << "\t\t\t    2";
    normal();
    cout << ") Exit";
    red();
    cout << "\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> option;

    if (option == 1) {
        report(myFiles);
    } else if (option == 2) {
        exit();
    }
}

/***************************************************************************************
 
*    Usage: Based On
*    Title: Colour Test
*    Author: Sudantha
*    Availability: http://stackoverflow.com/questions/4053837/c-colors-in-console-different-colors-in-different-text
*
***************************************************************************************/
void green() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

BOOL PlaySound(
        LPCTSTR pszSound,
        HMODULE hmod,
        DWORD   fdwSound
);


void red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void normal() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void grey() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}

void report(fileDetails &myFiles) {
    int option = 0;
    system("cls");
    welcome();
    red();
    cout << "\t\t<>\t\t";
    normal();
    cout << "Reports\t";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    normal();
    cout << "\t1) Overall Plagiarism Similarity Index.";
    red();
    cout << "\t<>\n\t\t<>";
    normal();
    cout << "\t2) Hash Test results.";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    normal();
    cout << "\t3) Plagiarised Lines results.";
    red();
    cout << "\t\t<>\n\t\t<>";
    normal();
    cout << "\t4) Iteration Results.";
    red();
    cout << "\t\t\t<>\n\t\t<>";
    normal();
    cout << "\t5) Line count results.";
    red();
    cout <<"\t\t\t<>\n\t\t<>";
    red();
    cout << "<>";
    green();
    cout << "\t\tSelect an option";
    red();
    cout << "\t\t<>" << endl;
    cout << "\t\t<>";
    green();
    cout << "    6";
    normal();
    cout << ") Back";
    green();
    cout << "\t\t\t    7";
    normal();
    cout << ") Exit";
    red();
    cout << "\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> option;

    if (option == 1) {
        reportOne(myFiles);
    } else if (option == 1) {
        reportOne(myFiles);
    } else if (option == 2) {
        reportTwo(myFiles);
    } else if (option == 3) {
        reportThree(myFiles);
    } else if (option == 4) {
        reportFour(myFiles);
    } else if (option == 5) {
        reportFive(myFiles);
    } else if (option == 6) {
        displayMenu(myFiles);
    } else if (option == 7) {
        exit();
    }
}

void reportOne(fileDetails &myFiles) {
    // Clear the console
    system("cls");

    // Shows welcome message
    welcome();

    // Prints reports
    myFiles.printSimilarityIndex();

    // A sks you to select an option
    selectAnOption2(myFiles);
};

void reportTwo(fileDetails &myFiles) {
    system("cls");
    welcome();
    myFiles.printHash();
    selectAnOption2(myFiles);
};

void reportThree(fileDetails &myFiles) {
    system("cls");
    welcome();
    myFiles.print();
    selectAnOption2(myFiles);
};

void reportFour(fileDetails &myFiles) {
    system("cls");
    welcome();
    myFiles.printIterations();
    selectAnOption2(myFiles);
};

void reportFive(fileDetails &myFiles) {
    system("cls");
    welcome();
    myFiles.printLineCount();
    selectAnOption2(myFiles);
};

void exit() {
    int a = 0;
    red();
    system("cls");
    cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    red();
    cout << "\t\t<>";
    normal();
    cout << "Thank you for using the plagarism detector.\t";
    red();
    cout <<"<>\n";
    red();
    cout << "\t\t<>";
    green();
    cout << "\tZamir & The Don";
    red();
    cout << "\t\t\t\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> a;
    exit2();
};
void exit2() {
        int a = 0;
        red();
        system("cls");
        cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
        red();
        cout << "\t\t<>";
        normal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        cout << "Thank you for using the plagarism detector.\t";
        red();
        cout <<"<>\n";
        red();
        cout << "\t\t<>";
        green();
        cout << "\t\tZamir & The Don";
        red();
        cout << "\t\t\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
        normal();
        cin >> a;
        exit3();
    };
void exit3() {
    int a = 0;
    red();
    system("cls");
    cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    red();
    cout << "\t\t<>";
    normal();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    cout << "Thank you for using the plagarism detector.\t";
    red();
    cout <<"<>\n";
    red();
    cout << "\t\t<>";
    green();
    cout << "\t\t\tZamir & The Don";
    red();
    cout << "\t\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> a;
    exit4();
};
void exit4() {
    int a = 0;
    red();
    system("cls");
    cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    red();
    cout << "\t\t<>";
    green();
    cout << "Thank you for using the plagarism detector.\t";
    red();
    cout <<"<>\n";
    red();
    cout << "\t\t<>";
    green();
    cout << "\t\t\t\tZamir & The Don";
    red();
    cout << "\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> a;
    exit4To3();
};

void exit4To3() {
    int a = 0;
    red();
    system("cls");
    cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    red();
    cout << "\t\t<>";
    red();
    cout << "Thank you for using the plagarism detector.\t";
    red();
    cout <<"<>\n";
    red();
    cout << "\t\t<>";
    green();
    cout << "\t\t\tZamir & The Don";
    red();
    cout << "\t\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> a;
    exit3To2();
};

void exit3To2() {
    int a = 0;
    red();
    system("cls");
    cout << "\n\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    red();
    cout << "\t\t<>";
    grey();
    cout << "Thank you for using the plagarism detector.\t";
    red();
    cout <<"<>\n";
    red();
    cout << "\t\t<>";
    green();
    cout << "\t\tZamir & The Don";
    red();
    cout << "\t\t\t<>\n\t\t<><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    normal();
    cin >> a;
    exit();
};


