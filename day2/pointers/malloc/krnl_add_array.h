#ifndef KRNL_ADD_ARRAY_H
#define KRNL_ADD_ARRAY_H

#include <stdint.h>
#include <cstdlib> 

// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {
/*
  Array Addition Kernel

  Arguments:
    a  (input)  --> Input array A 
    b  (input)  --> Input array B
    c  (output)  --> Output array C (sum of a and b)
    n (input)   --> Number of elements in arrays
*/
void krnl_add_array(int *a, int *b, int *c, int n);
} 

#endif // KRNL_ADD_ARRAY_H
