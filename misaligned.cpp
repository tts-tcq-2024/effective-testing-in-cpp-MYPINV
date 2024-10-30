// #include <iostream>
// #include <assert.h>

// int printColorMap() {
//     const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
//     const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
//     int i = 0, j = 0;
//     for(i = 0; i < 5; i++) {
//         for(j = 0; j < 5; j++) {
//             std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
//         }
//     }
//     return i * j;
// }

// int main() {
//     int result = printColorMap();
//     assert(result == 25);
//     std::cout << "All is well (maybe!)\n";
//     return 0;
// }


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <assert.h>

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int pairNumber = i * 5 + j;
            std::cout << pairNumber << " | " 
                      << majorColors[i] << " | " 
                      << minorColors[j] << "\n";
        }
    }
    return 25;
}

void testPrintColorMap() {
    std::ostringstream actualOutput;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(actualOutput.rdbuf());

    printColorMap();
    
    std::cout.rdbuf(originalCoutBuffer);

    std::ostringstream expectedOutput;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int pairNumber = i * 5 + j;
            expectedOutput << std::setw(2) << pairNumber << " | " 
                           << std::setw(6) << majorColors[i] << " | " 
                           << std::setw(6) << minorColors[j] << "\n";
        }
    }
   
    // Test if the output matches the expected output
    assert(actualOutput.str() == expectedOutput.str() && "Test failed: Output is not correctly aligned or mapped.");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}


