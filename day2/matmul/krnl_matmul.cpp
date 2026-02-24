#include "krnl_matmul.h"

extern "C" {
  void krnl_matmul(
    const mat_a_t a[MAT_A_ROWS][MAT_A_COLS], 
    const mat_b_t b[MAT_B_ROWS][MAT_B_COLS],
    result_t res[MAT_A_ROWS][MAT_B_COLS]
  )
  {
    // Iterate over the rows of the A matrix
    Row: for(int i = 0; i < MAT_A_ROWS; ++i) {
      // Iterate over the columns of the B matrix
      Col: for(int j = 0; j < MAT_B_COLS; ++j) {
        // Initialize accumulator
        res[i][j] = 0;
        // Iterate over the elements of a row of A and column of B
        for(int k = 0; k < MAT_A_COLS; ++k) {
          res[i][j] += a[i][k] * b[k][j];
        }
      }
    }
  }
}
