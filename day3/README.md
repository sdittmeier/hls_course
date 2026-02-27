# Labs: Performance Optimization with HLS Directives

This part of the lecture builds on your knowledge of Vitis HLS and explores performance optimization techniques including directives/pragmas, improving throughput and latency.

---
## 📂 Project Structure Overview
```
hls_course/day3/
├── yuv_filter/               # YUV filter example with performance optimization
├── loop_optimizations/       # Loop optimization examples with pragmas
├── README.md                 # This file
```

---
## 📜 Component Details

### 🔧 [`yuv_filter/`](./yuv_filter)
This folder contains an example project demonstrating performance optimization techniques in Vitis HLS, including:
- Use of HLS directives and pragmas for optimization
- Throughput and latency improvements

📁 See the [yuv_filter/](./yuv_filter) folder for the actual HLS source files.
Here, you also get detailed instructions for this lab.

**Important Notes:**
- When setting up the testbench, you must add both `yuv_filter_test.cpp` and `image_aux.cpp` to the testbench source files
- Pay attention to the path strings in both `image_aux.cpp` and `yuv_filter_test.cpp` - these paths are hardcoded and may need to be adjusted based on your working directory structure

### 🔧 [`loop_optimizations/`](./loop_optimizations)
This folder contains examples demonstrating loop optimization techniques using Vitis HLS pragmas, including:
- Loop unrolling with different factors
- Loop pipelining
- Loop flattening
- Loop merging
- Performance impact analysis
- Loop dependency handling

📁 See the [loop_optimizations/](./loop_optimizations) folder for the actual HLS source files.

---
## 🚀 Quick Start

Start by exploring the performance optimization examples:
1. [yuv_filter/](./yuv_filter) - For YUV filter with performance optimization techniques
2. [loop_optimizations/](./loop_optimizations) - For loop optimization with pragmas

The examples demonstrate various HLS directives and pragmas that can be used to improve kernel performance.