// File: krnl_matmul_test.cpp

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include "krnl_matmul.h"

int main() {
    // 1) Allocate three matrices: two input matrices and one output matrix
    static mat_a_t in1[MAT_A_ROWS][MAT_A_COLS];
    static mat_b_t in2[MAT_B_ROWS][MAT_B_COLS];
    static result_t out[MAT_A_ROWS][MAT_B_COLS];

    // 2) Initialize input arrays with test values
    for (int i = 0; i < MAT_A_ROWS; i++) {
        for (int j = 0; j < MAT_A_COLS; j++) {
            in1[i][j] = (mat_a_t)(i + j);
        }
    }
    for (int i = 0; i < MAT_B_ROWS; i++) {
        for (int j = 0; j < MAT_B_COLS; j++) {
            in2[i][j] = (mat_b_t)((MAT_B_ROWS-1-i) + (MAT_B_COLS-1-j));
        }
    }
    for (int i = 0; i < MAT_A_ROWS; i++) {
        for (int j = 0; j < MAT_B_COLS; j++) {
            out[i][j] = 0.0f;
        }
    }
    }

    // 3) Call the HLS kernel
    krnl_matmul(in1, in2, out);

    // 4) Verify results
    bool all_ok = true;
    for (int i = 0; i < MAT_A_ROWS; i++) {
        for (int j = 0; j < MAT_B_COLS; j++) {
            mat_a_t expected = 0;
            for (int k = 0; k < MAT_A_COLS; k++) {
                expected += in1[i][k] * in2[k][j];
            }
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
