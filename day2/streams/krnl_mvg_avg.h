#ifndef KRNL_MVG_AVG_H
#define KRNL_MVG_AVG_H

#include <stdint.h>

#define WINDOW_SIZE 32
#define DATA_SIZE 1024
// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {
/*
  Moving Average Kernel
  Arguments:
    in  (input)    --> Input array A 
    out  (output)  --> Output array B
*/

void krnl_mvg_avg(int *in, int *out);
} 

#endif // KRNL_MVG_AVG_H
