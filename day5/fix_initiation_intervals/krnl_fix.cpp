struct A { /* Total size = 192 bits (32 x 6) or 24 bytes */
    int s_1;
    int s_2;
    int s_3;
    int s_4;
    int s_5;
    int s_6;
};

#define NUM 1024

void read(A *a_in, A buf_out[NUM]) {
READ:
    for (int i = 0; i < NUM; i++)
    {
        #pragma HLS PIPELINE II=1
        buf_out[i] = a_in[i];
    }
}
 
void compute(A buf_in[NUM], A buf_out[NUM], int size) {
COMPUTE:
    for (int j = 0; j < NUM; j++)
    {
        #pragma HLS PIPELINE II=1
        buf_out[j].s_1 = buf_in[j].s_1 + size;
        buf_out[j].s_2 = buf_in[j].s_2;
        buf_out[j].s_3 = buf_in[j].s_3;
        buf_out[j].s_4 = buf_in[j].s_4;
        buf_out[j].s_5 = buf_in[j].s_5;
        buf_out[j].s_6 = buf_in[j].s_6 % 2;
    }
}
  
void write(A buf_in[NUM], A *a_out) {
    WRITE:
    for (int k = 0; k < NUM; k++)
    {
        #pragma HLS PIPELINE II=1
        a_out[k] = buf_in[k];
    }
}

extern "C" {
void krnl_fix(A *a_in, A *a_out, int size)
{
#pragma HLS INTERFACE m_axi port=a_in bundle=gmem0
#pragma HLS INTERFACE m_axi port=a_out bundle=gmem1
    A buffer_in[NUM];
    A buffer_out[NUM];
  
#pragma HLS dataflow
    read(a_in, buffer_in);
    compute(buffer_in, buffer_out, size);
    write(buffer_out, a_out);
}
}