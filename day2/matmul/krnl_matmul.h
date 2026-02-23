#ifndef KRNL_MATMUL_H
#define KRNL_MATMUL_H

#include <stdint.h>

#define MAT_A_ROWS 64
#define MAT_A_COLS 64
#define MAT_B_ROWS 64
#define MAT_B_COLS 64

typedef float mat_a_t;
typedef float mat_b_t;
typedef float result_t;

// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {
/*
  Matrix Multiplication Kernel

  Arguments:
    a  (input)  --> Input matrix A
    b  (input)  --> Input matrix B
    res (output) --> Output matrix C
*/
void krnl_matmul(
  const mat_a_t a[MAT_A_ROWS][MAT_A_COLS], 
  const mat_b_t b[MAT_B_ROWS][MAT_B_COLS], 
  result_t res[MAT_A_ROWS][MAT_B_COLS]);
} 

#endif // KRNL_MATMUL_H
