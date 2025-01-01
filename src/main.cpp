#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void) {
    
    string filepath = "data/maps/01.txt";
    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filepath << endl;
        return 1;
    }

    cout << "Contents of " << filepath << ":" << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}