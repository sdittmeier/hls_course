#include "krnl_mvg_avg.h"

extern "C" {
void krnl_mvg_avg(int *in, int *out){
    // Implement a moving average filter with a window size of WINDOW_SIZE.
    // You can buffer the samples in a FIFO (hls::stream) to efficiently compute the moving average.
    // Use a fixed input data size of DATA_SIZE for this kernel.
    // For simplicity, even when the window is not full (i < WINDOW_SIZE), you can still divide by WINDOW_SIZE to compute the average.
    // Hint: the window size is a power of 2 -- how can you implement the division most efficiently?
}
}
