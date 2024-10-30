// #include <iostream>
// #include <assert.h>

// int alertFailureCount = 0;

// int networkAlertStub(float celcius) {
//     std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
//     // Return 200 for ok
//     // Return 500 for not-ok
//     // stub always succeeds and returns 200
//     return 200;
// }

// void alertInCelcius(float farenheit) {
//     float celcius = (farenheit - 32) * 5 / 9;
//     int returnCode = networkAlertStub(celcius);
//     if (returnCode != 200) {
//         // non-ok response is not an error! Issues happen in life!
//         // let us keep a count of failures to report
//         // However, this code doesn't count failures!
//         // Add a test below to catch this bug. Alter the stub above, if needed.
//         alertFailureCount += 0;
//     }
// }

// int main() {
//     alertInCelcius(400.5);
//     alertInCelcius(303.6);
//     assert(alertFailureCount > 0);
//     std::cout << alertFailureCount << " alerts failed.\n";
//     std::cout << "All is well (maybe!)\n";
//     return 0;
// }

#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

// Modify the stub to simulate failure cases
int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " Celsius.\n";
    // Simulate a failure if the temperature exceeds a threshold
    if (celcius > 200) {  // threshold for testing
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count if return code is non-200
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);  // should increment failure count
    alertInCelcius(303.6);  // should increment failure count
    assert(alertFailureCount > 0);  // now this assertion will pass
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}

