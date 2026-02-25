// File: krnl_add_array_test.cpp

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include "krnl_add_array.h"

int main() {
    // 1) Allocate three arrays of length size
    static int size = 128;
    int in1[size];
    int in2[size];
    int out[size];

    // 2) Initialize input arrays with test values
    //    For example: in1[i] = i, in2[i] = 2*i
    for (int i = 0; i < size; i++) {
        in1[i] = (int)i;
        in2[i] = (int)(2 * i);
        out[i] = 0;  // zero‐initialize output buffer
    }

    // 3) Call the HLS kernel
    krnl_add_array(in1, in2, out, size);

    // 4) Verify results
    bool all_ok = true;
    for (int i = 0; i < size; i++) {
        int expected = in1[i] + in2[i];
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
        std::cout << "=== Test PASSED: All " << size
                  << " results matched ===" << std::endl;
        return EXIT_SUCCESS;
    } else {
        std::cout << "=== Test FAILED ===" << std::endl;
        return EXIT_FAILURE;
    }
}
