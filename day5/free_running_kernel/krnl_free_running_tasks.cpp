
#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <hls_task.h>
#define WORD_LENGTH 64

void read(hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& in, hls::stream<ap_uint<WORD_LENGTH>>& s1) {
    #pragma HLS PIPELINE II=1
    if (!in.empty()) {
        ap_axiu<WORD_LENGTH,0,0,0> in_word = in.read();
        s1.write(in_word.data);
    }
}

void compute(hls::stream<ap_uint<WORD_LENGTH>>& s1, hls::stream<ap_uint<WORD_LENGTH>>& s2) {
    #pragma HLS PIPELINE II=1
    if (!s1.empty()) {
        ap_uint<WORD_LENGTH> in_word = s1.read();
        s2.write(in_word + 1); // simple computation: increment the input
    }
}

void write(hls::stream<ap_uint<WORD_LENGTH>>& s2, hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& out) {
    #pragma HLS PIPELINE II=1
    if (!s2.empty()) {
        ap_uint<WORD_LENGTH> out_word = s2.read();
        ap_axiu<WORD_LENGTH,0,0,0> out_data;
        out_data.data = out_word;
        out.write(out_data);
    }
}

extern "C" {
void krnl_free_running_tasks(
	hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& in, 
	hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& out) 
{
	#pragma HLS interface ap_ctrl_none port=return
    hls_thread_local hls::stream<ap_uint<WORD_LENGTH>> s1;
    #pragma HLS stream variable=s1 depth=16 
    hls_thread_local hls::stream<ap_uint<WORD_LENGTH>> s2; 
    #pragma HLS stream variable=s2 depth=16
    hls_thread_local hls::task t1(read, in, s1);
    hls_thread_local hls::task t2(compute, s1, s2);
    hls_thread_local hls::task t3(write, s2, out);
}
}