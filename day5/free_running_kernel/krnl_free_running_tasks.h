#ifndef KRNL_FREE_RUNNING_TASKS_H
#define KRNL_FREE_RUNNING_TASKS_H

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define WORD_LENGTH 64


//Declaring the hardware function
extern "C"{
void krnl_free_running_tasks(
    hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& in,
    hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& out);
}

#endif // KRNL_FREE_RUNNING_TASKS_H
