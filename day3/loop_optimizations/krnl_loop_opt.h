#ifndef KRNL_LOOP_OPT_H
#define KRNL_LOOP_OPT_H

#include <stdint.h>

#define LOOP_COUNT 256

// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {
/*
  Loop Optimization Kernel
  Arguments:
    in  (input)    --> Input array A
    out  (output)  --> Output array B
    size (input)   --> Size of the input and output arrays
    size2 (input)  --> Size of the second dimension of the input and output arrays
*/
void krnl_loop_opt(const int *in, int *out, int size, int size2);
}

#endif // KRNL_LOOP_OPT_H