# Instructions for Discrete Cosine Transformation

**Important Note**: document your findings through this lab so that we can discuss it later together :)

- Create the HLS component as usual.
**Important Note:**
    - Pay attention to the path strings in `dct_test.cpp` - these paths are hardcoded and may need to be adjusted based on your working directory structure

The top-level function dct, is defined at line 104. It implements 2D DCT algorithm by first processing each row of the input array via a 1D DCT then processing the columns of the resulting array through the same 1D DCT. It calls read_data, dct_2d, and write_data functions. The read_data function is defined at line 80 and consists of two loops – RD_Loop_Row and RD_Loop_Col. The write_data function is defined at line 92 and consists of two loops to perform writing the result. The dct_2d function, defined at line 49, calls dct_1d function and performs transpose. Finally, dct_1d function, defined at line 30, uses dct_coeff_table and performs the required function by implementing a basic iterative form of the 1D Type-II DCT algorithm. Following figure shows the function hierarchy on the left-hand side, the loops in the order they are executes and the flow of data on the right-hand side.

 ![img](./images/Figure3.png)


- Run C Simulation and verify that the tests pass
- Run C Synthesis and observe the synthesis logs and report: 
    - From the **synthesis output log**: Which functions have been inlined?
    - From the **synthesis report**: What are the performance and resource estimates? Note that the loops are already pipelined.
- Run C/RTL Cosimulation. Verify that the simulation passes. 

- Remove the pipeline optimization done by Vitis HLS automatically by adding `#pragma HLS pipeline off` to all loops:  **DCT_Inner_Loop, DCT_Outer_Loop, Row_DCT_Loop, Xpose_Row_Outer_Loop, Xpose_Row_Inner_Loop, Col_DCT_Loop, Xpose_Col_Outer_Loop, Xpose_Col_Inner_Loop, RD_Loop_Row, RD_Loop_Col, WR_Loop_Row, and WR_Loop_Col**.
    - Run C Synthesis again
    - Check the performance and resource utilization in the C Synthesis report without the automatic optimization

- Now we want to manually optimize the design again, by replacing `#pragma HLS pipeline off` with `#pragma HLS pipeline` for **DCT_Inner_Loop, Xpose_Row_Inner_Loop, Xpose_Col_Inner_Loop, RD_Loop_Col, and WR_Loop_Col**.
And remove the `#pragma HLS pipeline off` line completely for the **DCT_Outer_Loop, Row_DCT_Loop, Xpose_Row_Outer_Loop, Col_DCT_Loop, Xpose_Col_Outer_Loop, RD_Loop_Row** and **WR_Loop_Row.**
  - Run C Synthesis again
  - Check the performance and resource utilization in the C Synthesis report with the manual optimization -- this should match again the original values reported using automatic optimizations. 
  - Open the **Schedule Viewer** and determine where most of the clock cycles are spend, i.e. where the large latencies are.
  - Select the dct entry and observe the **RD_Loop_Row_RD_Loop_Col** and **WR_Loop_Row_WR_Loop_Col** entries in the Performance & Resource Estimates. These are two nested loops flattened and given the new names formed by appending inner loop name to the outer loop name. You can verify this by looking in the Console view message.
  - In the Performance & Resource Estimates pane, expand all items. Notice that the most of the latency occurs is in **Row_DCT_Loop_DCT_Outer_Loop** and **Col_DCT_Loop_DCT_Outer_Loop** function. 
  - In the Schedule Viewer pane, select the **Col_DCT_Loop_DCT_Outer_Loop** entry, right-click on the **col_outbuf_addr_write_In45** (write) block in the Schedule Viewer, and select Goto Source. Notice that line 45 is highlighted which is preventing the flattening of the **DCT_Outer_Loop**. 
- Now, we want to apply fine-grain parallelism of performing multiply and add operations of the inner loop of **dct_1d** using **PIPELINE** directive by moving the PIPELINE directive from inner loop to the outer loop of dct_1d.
    - Move the `#pragma HLS pipeline` from the **DCT_INNER_LOOP** to the **DCT_OUTER_LOOP**. By pipelining an outer loop, all inner loops will be unrolled automatically (if legal), so there is no need to explicitly apply an UNROLL directive to DCT_Inner_Loop. Simply move the pipeline to the outer loop: the nested loop will still be pipelined but the operations in the inner-loop body will operate concurrently.
    - Run C Synthesis. 
    - Observe the C Synthesis report, how this change affects resources and latency. Notice, that the **DCT_Outer_Loop** is now pipelined.
- Next, we want to improve Memory Bandwidth. For this, we apply the **ARRAY_PARTITION** directive to `buf_2d_in` of dct (since the bottleneck was on src port of the `dct_1d` function, which was passed via in_block of the dct_2d function, which in turn was passed via buf_2d_in of the dct function) and `col_inbuf` of `dct_2d`. 
    - In the top level kernel `dct`, add the ARRAY_PARTITION pragma `#pragma HLS ARRAY_PARTITION variable=buf_2d_in complete dim=2`
    - Do the same for the `col_inbuf` in `dct_2d`.
    - Run C Synthesis
    - Observe the C Synthesis report, check the effect on latency and resources. 
- Next, we want to apply the DATAFLOW directive to improve the throughput. 
    - Add `#pragma HLS DATAFLOW` to the toplevel kernel `dct`.
    - Run C Synthesis
    - Observe the C Synthesis report, check the effect on latency and resources. 
    - The Dataflow pipeline throughput indicates the number of clock cycles between each set of inputs reads (interval parameter). If this value is less than the design latency it indicates the design can start processing new inputs before the currents input data are output.
    - Look at the console view and notice that `dct_coeff_table` is automatically partitioned in dimension 2.
    - The` buf_2d_in` and `col_inbuf` arrays are partitioned as we had applied the directive in the previous run. The dataflow is applied at the top-level which created channels between top-level functions read_data, dct_2d, and write_data.
    - In the Synthesis report, expand the Performance & Resource Estimates entries, and select the dct_2d entry.
    - Observe that most of the latency and interval (throughput) is caused by the dct_2d function. The interval of the top-level function dct, is less than the sum of the intervals of the read_data, dct_2d, and write_data functions indicating that they operate in parallel and dct_2d is the limiting factor. It can be seen that dct_2d is not completely operating in parallel as Row_DCT_Loop and Col_DCT_Loop were not pipelined. 
    One of the limitations of the dataflow optimization is that it only works on top-level loops and functions. One way to have the blocks in dct_2d operate in parallel would be to pipeline the entire function. This however would unroll all the loops and can sometimes lead to a large area increase. An alternative is to raise these loops up to the top-level of hierarchy, where dataflow optimization can be applied, by removing the dct_2d hierarchy, i.e. inline the dct_2d function.
- Last step of performance optimization: INLINE `dct_2d`. 
    - Add the `#pragma HLS INLINE` to the `dct_2d` function. 
    - Run C Synthesis. 
    - Observe the effects in the Synthesis reports. 

---
## Conclusion

In this lab, you learned various techniques to improve the performance and balance resource utilization. PIPELINE directive when applied to outer loop will automatically cause the inner loop to unroll. When a loop is unrolled, resources utilization increases as operations are done concurrently. Partitioning memory may improve performance but will increase BRAM utilization. When INLINE directive is applied to a function, the lower level hierarchy is automatically dissolved. When DATAFLOW directive is applied, the default memory buffers (of ping-pong type) are automatically inserted between the top-level functions and loops. The console logs can provide insight on what is going on.