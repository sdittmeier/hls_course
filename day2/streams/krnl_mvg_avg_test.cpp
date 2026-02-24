// File: krnl_mvg_avg_test.cpp

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include "krnl_mvg_avg.h"

int main() {
    // 1) Allocate two arrays of length DATA_SIZE
    static int in[DATA_SIZE];
    static int out[DATA_SIZE];

    static int baseline = 1024;
    static int variation = 256;
    // random number generator with fixed seed for reproducibility
    srand(42);

    // 2) Initialize input arrays with test values
    //    For example: in[i] = i
    for (int i = 0; i < DATA_SIZE; i++) {
        in[i] = baseline + (rand() % variation) - (variation / 2);  // random values around baseline
        out[i] = 0;  // zero‐initialize output buffer
    }

    // 3) Call the HLS kernel
    krnl_mvg_avg(in, out);

    // 4) Verify results
    bool all_ok = true;
    for (int i = 0; i < DATA_SIZE; i++) {
        int expected = 0;
        // Compute expected moving average for index i
        for (int j = i - WINDOW_SIZE + 1; j <= i; j++) {
            if (j >= 0) {  // only include valid indices
                expected += in[j];
            }
        }
        expected /= WINDOW_SIZE;  // average
        if (out[i] != expected) {
            std::cout << "Mismatch at index " << i
                      << ": expected=" << expected
                      << ", got=" << out[i] << std::endl;
            all_ok = false;
            // If you want to stop on first error, uncomment:
            // break;
        }
    }

    // 5) Print final PASS/FAIL
    if (all_ok) {
        std::cout << "=== Test PASSED: All " << DATA_SIZE
                  << " results matched ===" << std::endl;
        return EXIT_SUCCESS;
    } else {
        std::cout << "=== Test FAILED ===" << std::endl;
        return EXIT_FAILURE;
    }
}
