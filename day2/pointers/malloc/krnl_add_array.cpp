#include "krnl_add_array.h"

extern "C" {
void krnl_add_array(int *a, int *b, int *c, int n) {
    int *temp = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        temp[i] = a[i] + b[i];
    }

    for (int i = 0; i < n; i++) {
        c[i] = temp[i];
    }

    free(temp);
}
}
