// #include <iostream>
// #include <assert.h>

// char size(int cms) {
//     char sizeName = '\0';
//     if(cms < 38) {
//         sizeName = 'S';
//     } else if(cms > 38 && cms < 42) {
//         sizeName = 'M';
//     } else if(cms > 42) {
//         sizeName = 'L';
//     }
//     return sizeName;
// }

// int main() {
//     assert(size(37) == 'S');
//     assert(size(40) == 'M');
//     assert(size(43) == 'L');
//     assert(size(38) == 'S');
//     assert(size(42) == 'M');
//     std::cout << "All is well (maybe!)\n";
//     return 0;
// }

#include <iostream>
#include <assert.h>

char size(int cms) {
    if (cms <= 38) {          // corrected to include 38 in the 'S' size
        return 'S';
    } else if (cms <= 42) {   // corrected to include 42 in the 'M' size
        return 'M';
    } else {
        return 'L';
    }
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S');  // Now returns 'S' for 38 as expected
    assert(size(40) == 'M');
    assert(size(42) == 'M');  // Now returns 'M' for 42 as expected
    assert(size(43) == 'L');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
