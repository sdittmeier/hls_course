#include <iostream>
#include "krnl_free_running_dataflow.h"

#define WORD_LENGTH 64
#define TEST_SIZE 10

// Simple testbench for the free-running kernel
int main() {
    // Create streams for input and output
    hls::stream<ap_axiu<WORD_LENGTH,0,0,0>> input_stream;
    hls::stream<ap_axiu<WORD_LENGTH,0,0,0>> output_stream;

    std::cout << "Starting testbench for krnl_free_running_dataflow..." << std::endl;
    std::cout << "Filling input stream with test data..." << std::endl;
    // Fill input stream with test data
    for (int i = 0; i < TEST_SIZE; i++) {
        ap_axiu<WORD_LENGTH,0,0,0> data;
        data.data = i;
        data.last = (i == TEST_SIZE - 1) ? 1 : 0;  // Mark last packet
        input_stream.write(data);
    }
    std::cout << "Input stream filled with " << TEST_SIZE << " values." << std::endl;
    std::cout << "Running the kernel..." << std::endl;
    // Run the kernel
    krnl_free_running_dataflow(input_stream, output_stream);

    // Read and verify output
    bool success = true;
    std::cout << "Input values: ";
    for (int i = 0; i < TEST_SIZE; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Expected output values: ";
    for (int i = 0; i < TEST_SIZE; i++) {
        std::cout << (i + 1) << " ";
    }
    std::cout << std::endl;

    std::cout << "Actual output values: ";
    for (int i = 0; i < TEST_SIZE; i++) {
        ap_axiu<WORD_LENGTH,0,0,0> output_data = output_stream.read();
        std::cout << output_data.data << " ";
        if (output_data.data != i + 1) {
            success = false;
        }
    }
    std::cout << std::endl;

    if (success) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return success ? 0 : 1;
}