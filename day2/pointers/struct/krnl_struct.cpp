#include "krnl_struct.h"

extern "C" {
void compute(point_t *p, int n) {
#pragma HLS PIPELINE
    for (int i = 0; i < n; i++) {
        p[i].x = p[i].x + p[i].y;
        p[i].y = p[i].x - p[i].y;
    }
}
}

extern "C" {
void compute3(point3_t *p, int n) {
#pragma HLS PIPELINE
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].y;
        p[i].z += p[i].x;
    }
}
}

extern "C" {
void compute_decomp(int *x, int *y, int *z, int n) {
#pragma HLS PIPELINE
    for (int i = 0; i < n; i++) {
        x[i] += y[i];
        z[i] += x[i];
    }
}
}