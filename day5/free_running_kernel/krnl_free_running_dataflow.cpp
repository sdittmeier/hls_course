#include "krnl_free_running_dataflow.h"

void read_df(hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& in, hls::stream<ap_uint<WORD_LENGTH>>& s1) {
    while(true){
        #pragma HLS PIPELINE II=1
        if (!in.empty()) {
            ap_axiu<WORD_LENGTH,0,0,0> in_word = in.read();
            s1.write(in_word.data);
        }
    }
}

void compute_df(hls::stream<ap_uint<WORD_LENGTH>>& s1, hls::stream<ap_uint<WORD_LENGTH>>& s2) {
    while(true){
        #pragma HLS PIPELINE II=1
        if (!s1.empty()) {
            ap_uint<WORD_LENGTH> in_word = s1.read();
            s2.write(in_word + 1); // simple computation: increment the input
        }
    }
}

void write_df(hls::stream<ap_uint<WORD_LENGTH>>& s2, hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& out) {
    while(true){
        #pragma HLS PIPELINE II=1
        if (!s2.empty()) {
            ap_uint<WORD_LENGTH> out_word = s2.read();
            ap_axiu<WORD_LENGTH,0,0,0> out_data;
            out_data.data = out_word;
            out.write(out_data);
        }
    }
}

extern "C" {
void krnl_free_running_dataflow(
	hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& in, 
	hls::stream<ap_axiu<WORD_LENGTH,0,0,0>>& out) 
{
	#pragma HLS interface ap_ctrl_none port=return
    hls::stream<ap_uint<WORD_LENGTH>> s1;
    #pragma HLS stream variable=s1 depth=16 
    hls::stream<ap_uint<WORD_LENGTH>> s2; 
    #pragma HLS stream variable=s2 depth=16

    #pragma HLS dataflow
    read_df(in, s1);
    compute_df(s1, s2);
    write_df(s2, out);
}
}