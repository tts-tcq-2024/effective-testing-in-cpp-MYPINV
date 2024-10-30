#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <assert.h>
using namespace std;

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int pairNumber = i * 5 + j;
            cout << pairNumber << " | " 
                      << majorColors[i] << " | " 
                      << minorColors[j] << "\n";
        }
    }
    return 25;
}

void testPrintColorMap() {
    ostringstream actualOutput;
    streambuf* originalCoutBuffer = std::cout.rdbuf();
    cout.rdbuf(actualOutput.rdbuf());

    printColorMap();
    
    cout.rdbuf(originalCoutBuffer);

    ostringstream expectedOutput;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int pairNumber = i * 5 + j;
            expectedOutput << setw(2) << pairNumber << " | " 
                           << setw(6) << majorColors[i] << " | " 
                           << setw(6) << minorColors[j] << "\n";
        }
    }
   
    // Test if the output matches the expected output
    assert(actualOutput.str() == expectedOutput.str() && "Test failed: Output is not correctly aligned or mapped.");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMap();
    cout << "All is well (maybe!)\n";
    return 0;
}


