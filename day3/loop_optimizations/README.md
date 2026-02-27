# Loop Optimizations with Pragmas

This example demonstrates various loop optimization techniques using Vitis HLS pragmas.

## Overview

In this example, you will explore different loop optimization techniques that can be applied using HLS pragmas to improve performance of your kernels. The example shows how to use different pragmas to control loop unrolling, pipelining, and flattening.

## Files

- `krnl_loop_opt.h` - Header file with kernel declaration and constants
- `krnl_loop_opt.cpp` - Main kernel implementation with different pragma examples
- `krnl_loop_opt_test.cpp` - Test file for verification

## Pragma Examples

The kernel implementation includes several examples of different pragmas:

1. **PIPELINE pragma**: Pipelined loop for better throughput
   - `#pragma HLS pipeline off` - Disables pipelining
   - `#pragma HLS PIPELINE II=1` - Enables pipelining with initiation interval of 1

2. **UNROLL pragma**: Completely unrolls the loop, or apply a **factor=N** to unroll by a specified factor
   - `#pragma HLS UNROLL` - Completely unrolls the loop
   - `#pragma HLS UNROLL factor=4` - Unrolls the loop by a factor of 4

3. **FLATTEN pragma**: Flattens nested loops
   - `#pragma HLS LOOP_FLATTEN` - Flattens nested loops

4. **TRIPCOUNT pragma**: Provides loop trip count information for optimization
   - `#pragma HLS LOOP_TRIPCOUNT min=1 max=LOOP_COUNT/4` - Specifies min and max trip counts

5. **LOOP_MERGE pragma**: Merges loops for better optimization
   - `#pragma HLS LOOP_MERGE` - Merges loops to improve performance

## How to Use

1. **Create the HLS component**: Follow the standard Vitis tool flow
2. **Validate execution**: Run the C simulation to verify that all loops produce the same results
3. **Analyze the reports**: Run C Synthesis and examine the synthesis reports to see how each pragma affects the loop
4. **Experiment**: Uncomment different pragma examples to see their effects. Collect performance numbers and resource usage for later discussions.
For some loop implementations you may need to adapt the testbench for validation.

## Expected Results

Most loops should produce identical output since they all perform the same operation (`out[i] = in[i] * 2`), but they will have different resource usage and performance characteristics based on the pragmas used.
For some tests with loop dependencies you will need to adapt the testbench.

## Learning Objectives

- Understand how to apply loop optimization pragmas in Vitis HLS
- Learn when to use different optimization techniques
- Analyze the impact of pragmas on synthesis results
- Compare performance characteristics of different loop optimizations
