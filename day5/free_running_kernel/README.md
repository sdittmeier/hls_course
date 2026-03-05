# Free Running Kernel: Dataflow vs Tasks Comparison

In this tutorial, we will examine two implementations of a free-running kernel using different HLS approaches: dataflow and tasks. The goal is to understand the differences between these approaches and analyze their characteristics.

## 1. Kernel Implementations

### 1.1 Dataflow Implementation (`krnl_free_running_dataflow.cpp`)
1. Review the code
2. Create the HLS component
3. Run C-Synthesis and observe the reports
4. Run C-Simulation with `testbench.cpp` --> does it work? If not, what is the issue?
5. Run C/RTL Cosimulation --> any differences compared to C-Simulation?

### 1.2 Tasks Implementation (`krnl_free_running_tasks.cpp`)
1. Review the code
2. Create the HLS component
3. Run C-Synthesis and observe the reports --> any differences compared to the dataflow implementation?
4. Adapt the testbench to make use of the `krnl_free_running_tasks` and run C-Simulation
5. Also run C/RTL Cosimulation and verify if it matches C-Simulation

## How can you adapt `krnl_free_running_dataflow.cpp` to mitigate any issues observed in simulation?