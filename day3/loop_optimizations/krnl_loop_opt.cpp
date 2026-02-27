#include "krnl_loop_opt.h"

extern "C" {
void krnl_loop_opt(const int *in, int *out, int size, int size2){

    //////////// PIPELINE LOOPS ////////////////////
    // Example 1: Basic loop without auto-optimization
    // 
    
    for(int i = 0; i < LOOP_COUNT; i++){
        #pragma HLS pipeline off
        out[i] = in[i] * 2;
    }
    
    
    // Example 2: Loop with pipeline pragma
    // This loop will be pipelined
    /*
    for(int i = 0; i < LOOP_COUNT; i++){
    #pragma HLS PIPELINE II=1
        out[i] = in[i] * 2;
    }
    */

    //////////// UNROLL LOOPS ////////////////////
    // Example 3: Loop with unroll pragma
    // Uncomment the following lines to see the effect of unrolling
    /*
    for(int i = 0; i < LOOP_COUNT; i++){
    #pragma HLS UNROLL
        out[i] = in[i] * 2;
    }
    */

    // Example 4: Loop with factor pragma
    // This loop will be unrolled by a factor of 4
    /*
    for(int i = 0; i < LOOP_COUNT; i++){
    #pragma HLS UNROLL factor=4
        out[i] = in[i] * 2;
    }
    */

    //////////////////// NESTED LOOPS ////////////////////
    // Example 5: Nested Loop without manual optimization
    /*
    for(int i = 0; i < LOOP_COUNT/4; i++){
        for(int j = 0; j < 4; j++){
            out[i*4 + j] = in[i*4 + j] * 2;
        }
    }
    */

    // Example 6: Nested Loop with optimizations
    // This loop will be flattened
    // perfect loop example
    /*
    for(int i = 0; i < LOOP_COUNT/4; i++){
        for(int j = 0; j < 4; j++){
            #pragma HLS LOOP_FLATTEN
            out[i*4 + j] = in[i*4 + j] * 2;
        }
    }
    */

    // Example 7: Nested Loop with optimizations
    // This loop will be flattened
    // semi-perfect loop example
    /*
    for(int i = 0; i < size; i++){
        #pragma HLS LOOP_TRIPCOUNT min=1 max=LOOP_COUNT/4
        for(int j = 0; j < 4; j++){
            #pragma HLS LOOP_FLATTEN
            out[i*4 + j] = in[i*4 + j] * 2;
        }
    }
    */

    // Example 8: Nested Loop without optimizations
    // other type of loop example
    /*
    for(int i = 0; i < size; i++){
        #pragma HLS LOOP_TRIPCOUNT min=1 max=16
        for(int j = 0; j < size2; j++){
            #pragma HLS LOOP_TRIPCOUNT min=1 max=16
            out[i*size2 + j] = in[i*size2 + j] * 2;
        }
    }
    */

    // Example 9: Nested Loop with optimizations
    // other type of loop example
    // does this optimization help? Why or why not?
    /*
    for(int i = 0; i < size; i++){
        #pragma HLS LOOP_TRIPCOUNT min=1 max=16
        for(int j = 0; j < size2; j++){
            #pragma HLS LOOP_TRIPCOUNT min=1 max=16
            #pragma HLS LOOP_FLATTEN
            out[i*size2 + j] = in[i*size2 + j] * 2;
        }
    }
    */

    //////////// LOOPS WITH DEPENDENCIES ////////////////////
    // Example 10: Loop accumlation without optimization
    /*
    int sum = 0;
    for(int i = 0; i < LOOP_COUNT; i++){
        sum += in[i];
    }
    out[0] = sum;
    */

    // Example 11: Loop accumlation with optimization
    /*
    int sum = 0;
    for(int i = 0; i < LOOP_COUNT; i++){
        #pragma HLS UNROLL factor=4
        sum += in[i];
    }
    out[0] = sum;
    */

    //////////// LOOP MERGING////////////////////
    // Example 12: without optimiatzions
    /*
    int temp[LOOP_COUNT];
    int temp2[LOOP_COUNT];
    L12_1: for(int i = 0; i < LOOP_COUNT; i++){
        temp[i] = in[i];
    }
    {
        L12_2: for(int i = 0; i < LOOP_COUNT; i++){
            if(i % 2 == 0){
                temp2[i] = temp[i] * 2;
            }
        }
        L12_3: for(int i = 0; i < LOOP_COUNT; i++){
            if(i % 2 == 1){
                temp2[i] = temp[i] * 4;
            }
        }
    } 
    L12_4: for(int i = 0; i < LOOP_COUNT; i++){
        out[i] = temp2[i];
    }
    */
    
    // Example 13:  with loop merging optimizations
    /*
    int temp[LOOP_COUNT];
    int temp2[LOOP_COUNT];
    L12_1: for(int i = 0; i < LOOP_COUNT; i++){
        temp[i] = in[i];
    }
    {
        #pragma HLS LOOP_MERGE
        L12_2: for(int i = 0; i < LOOP_COUNT; i++){
            if(i % 2 == 0){
                temp2[i] = temp[i] * 2;
            }
        }
        L12_3: for(int i = 0; i < LOOP_COUNT; i++){
            if(i % 2 == 1){
                temp2[i] = temp[i] * 4;
            }
        }
    } 
    L12_4: for(int i = 0; i < LOOP_COUNT; i++){
        out[i] = temp2[i];
    }
    */
}
}