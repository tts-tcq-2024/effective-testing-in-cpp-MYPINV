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
#include <cassert>

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Function to print the color map with color pair numbers and returns total pair count
int printColorMap() {
    int colorPairCount = 0;
    for (int majorIndex = 0; majorIndex < 5; ++majorIndex) {
        for (int minorIndex = 0; minorIndex < 5; ++minorIndex) {
            int pairNumber = majorIndex * 5 + minorIndex;
            std::cout << std::setw(2) << pairNumber << " | " 
                      << std::setw(6) << majorColors[majorIndex] << " | "
                      << std::setw(6) << minorColors[minorIndex] << "\n";
            ++colorPairCount;
        }
    }
    return colorPairCount;
}

// Test function to validate printColorMap output alignment and correctness
void testPrintColorMap() {
    std::ostringstream capturedOutput;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();  // Backup original cout buffer
    std::cout.rdbuf(capturedOutput.rdbuf());                 // Redirect cout to capturedOutput
    
    printColorMap();                                         // Call function to capture its output
    std::cout.rdbuf(originalCoutBuffer);                     // Restore original cout buffer

    // Expected output stringstream
    std::ostringstream expectedOutput;
    for (int majorIndex = 0; majorIndex < 5; ++majorIndex) {
        for (int minorIndex = 0; minorIndex < 5; ++minorIndex) {
            int pairNumber = majorIndex * 5 + minorIndex;
            expectedOutput << std::setw(2) << pairNumber << " | "
                           << std::setw(6) << majorColors[majorIndex] << " | "
                           << std::setw(6) << minorColors[minorIndex] << "\n";
        }
    }

    // Check if captured output matches the expected output
    assert(capturedOutput.str() == expectedOutput.str() && "Test failed: Output alignment or content mismatch.");
}

int main() {
    int totalPairs = printColorMap();
    assert(totalPairs == 25 && "Test failed: Total color pairs count mismatch.");
    testPrintColorMap();
    std::cout << "All tests passed successfully!\n";
    return 0;
}

