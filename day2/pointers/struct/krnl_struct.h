#ifndef KRNL_STRUCT_H
#define KRNL_STRUCT_H

#include <stdint.h>

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    int x;
    int y;
    int z;
} point3_t;
// -----------------------------------------------------------------------------
// Top-level kernel prototype
// -----------------------------------------------------------------------------
extern "C" {
void compute(point_t *p, int n);
}
extern "C" {
void compute3(point3_t *p, int n);
} 
extern "C" {
void compute_decomp(int *x, int *y, int *z, int n);
}

#endif // KRNL_STRUCT_H
