#include "krnl_loop_opt.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    int *input = new int[LOOP_COUNT];
    int *output = new int[LOOP_COUNT];

    // Initialize input data
    for(int i = 0; i < LOOP_COUNT; i++){
        input[i] = i;
    }

    // Call the kernel
    krnl_loop_opt(input, output, LOOP_COUNT, 4);

    // Verify results (basic check)
    // The kernel performs: out[i] = in[i] * 2
    // adapt the verification for different loop examples if needed
    bool success = true;
    for(int i = 0; i < LOOP_COUNT; i++){
        if(output[i] != i * 2) {
            success = false;
            break;
        }
    }

    if(success){
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    delete[] input;
    delete[] output;

    return 0;
}