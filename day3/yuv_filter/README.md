# Instructions for YUV-Filter

**Important Note**: document your findings through this lab so that we can discuss it later together :)

- Create the HLS component as usual. 
**Important Notes:**
    -  When setting up the testbench, you must add both `yuv_filter_test.cpp` and `image_aux.cpp` to the testbench source files
    - Pay attention to the path strings in both `image_aux.cpp` and `yuv_filter_test.cpp` - these paths are hardcoded and may need to be adjusted based on your working directory structure

- Run C Simulation and verify that the tests pass
- Run C Synthesis and observe the synthesis report: 
    - What is the Estimated Fmax?
    - What are the reported latency and interval?
    - How large is the resource usage?
    - Check the Pragma report for valid used and inferred pragmas
    - Expand Modules & Loops to observe the effect of the used and inferred pragmas.
    - Note that **YUV_SCALE_LOOP_X_YUV_SCALE_LOOP_Y** is already pipelined. -pipeline_loops specifies the lower limit used when automatically pipelining loops. The default is 64, causing Vitis HLS to automatically pipeline loops with a tripcount of 64, or greater. If the option is applied, the innermost loop with a tripcount higher than the threshold is pipelined, or if the tripcount of the innermost loop is less than or equal to the threshold, its parent loop is pipelined. If the innermost loop has no parent loop, the innermost loop is pipelined regardless of its tripcount.
    - You can verify this by opening the **Schedule Viewer**, and expand the **YUV_SCALE_LOOP_X** entry. 
- Remove the pipeline optimization done by Vitis HLS automatically by adding **pipeline off pragma**
    - Within each loop (RGB2YUV_LOOP_X, RGB2YUV_LOOP_Y, YUV2RGB_LOOP_X, YUV2RGB_LOOP_Y, YUV_SCALE_LOOP_X, YUV_SCALE_LOOP_Y), add `#pragma HLS pipeline off` above the `#pragma HLS tripcount`
    - Run C Synthesis, and observe the Performance and area without the automatic optimization of Vitis HLS. How have latency, interval and resources changed? Observe again the pragma report to verify the pragmas have been applied correctly. 
- Manually apply the Pipeline optimization
    - Turn on pipelining for the **RGB2YUV_LOOP_Y** by changing the pragma to `#pragma HLS pipeline`, and remove the line `#pragma HLS pipeline off` completely for the **RGB2YUV_LOOP_X**. Do the same for the YUV2RGB_LOOPs and YUV_SCALE_LOOPs. 
    - Run Snythesis and compare again the performance and resource utilization from the synthesis report. 
- Apply DATAFLOW directive
    - In the top-level **yuv_filter** apply the `#pragma HLS dataflow` above the line `rgb2yuv   (in, yuv);`
    - Run C Synthesis again, and observe the effect of the Dataflow pragma on performance and resource utilization. 
    - Note that when the DATAFLOW optimization is performed, memory buffers are automatically inserted between the functions to ensure the next function can begin operation before the previous function has finished. The default memory buffers are ping-pong buffers sized to fully accommodate the largest producer or consumer array.
    - Vitis HLS allows the memory buffers to be the default ping-pong buffers or FIFOs. Since this design has data accesses which are fully sequential, FIFOs can be used. Another advantage to using FIFOs is that the size of the FIFOs can be directly controlled (not possible in ping-pong buffers where random accesses are allowed).
    The memory buffers type can be selected using Vitis HLS Configuration command.
- Apply Dataflow configuration command
    - Go to **Settings - hls_config.cfg - search for Dataflow - and change the hls.syn.dataflow.default_channel to FIFO** for this kernel. 
    - Run C Synthesis and observe the changes to performance and resource utilization. 