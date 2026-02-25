# Labs: Performance Optimization with HLS Directives

This part of the lecture builds on your knowledge of Vitis HLS and explores performance optimization techniques including directives/pragmas, improving throughput and latency, and removing bottlenecks.

---
## 📂 Project Structure Overview
```
hls_course/day3/
├── yuv_filter/               # YUV filter example with performance optimization
├── README.md                 # This file
```

---
## 📜 Component Details

### 🔧 [`yuv_filter/`](./yuv_filter)
This folder contains an example project demonstrating performance optimization techniques in Vitis HLS, including:
- Use of HLS directives and pragmas for optimization
- Throughput and latency improvements
- Bottleneck identification and removal

Each component builds on the previous and is designed to be clear and reproducible.

📁 See the [yuv_filter/](./yuv_filter) folder for the actual HLS source files.

**Important Notes:**
- When setting up the testbench, you must add both `yuv_filter_test.cpp` and `image_aux.cpp` to the testbench source files
- Pay attention to the path strings in both `image_aux.cpp` and `yuv_filter_test.cpp` - these paths are hardcoded and may need to be adjusted based on your working directory structure

---
## 🚀 Quick Start

Start by exploring the performance optimization example:
1. [yuv_filter/](./yuv_filter) - For YUV filter with performance optimization techniques

The example demonstrates various HLS directives and pragmas that can be used to improve kernel performance.