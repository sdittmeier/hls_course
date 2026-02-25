#ifndef KRNL_VADD_H
#define KRNL_VADD_H

#include <stdint.h>

#define DATA_SIZE 4096

// TRIPCOUNT identifier for HLS loops
static const int c_size = DATA_SIZE;

// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {

/*
  Vector Addition Kernel

  Arguments:
    in1  (input)  --> Input vector 1
    in2  (input)  --> Input vector 2
    out  (output) --> Output vector
    size (input)  --> Number of elements in vector
*/
void vadd(const unsigned int *in1, const unsigned int *in2, unsigned int *out, int size);

} 

#endif // KRNL_VADD_H
