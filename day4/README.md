# Labs: Advanced HLS Techniques and Optimization

This part of the lecture continues your journey in Vitis HLS, covering advanced techniques and deeper optimization strategies for hardware acceleration.

---
## 📂 Project Structure Overview
```
hls_course/day4/
├── dct/                        # DCT example with advanced optimization
├── matmul_revisited/           # Matrix multiplication optimization exercise
├── README.md                   # This file
```

---
## 📜 Component Details

### 🔧 [`dct/`](./dct)
This folder contains an example project demonstrating advanced HLS techniques, including:
- Advanced optimization strategies
- Memory interface optimization
- Pipeline optimization techniques
- Resource utilization analysis

📁 See the [dct/](./dct) folder for the actual HLS source files.
Here, you also get detailed instructions for this lab.

**Important Notes:**
- Pay attention to the path strings in both the testbench file `dct_test.cpp` - these paths are hardcoded and may need to be adjusted based on your working directory structure

### 🔧 [`matmul_revisited/`](./matmul_revisited)
This folder contains an optimization exercise for matrix multiplication, where you will start with a basic implementation and progressively apply various HLS optimization techniques:

📁 See the [matmul_revisited/](./matmul_revisited) folder for the actual HLS source files.
Here, you also get detailed instructions for this lab.
This exercise guides you through the optimization process from baseline to optimized implementation.

---
## 🚀 Quick Start

Start by exploring the advanced HLS techniques:
1. [dct/](./dct) - For DCT with advanced optimization techniques
2. [matmul_revisited/](./matmul_revisited) - For matrix multiplication optimization exercise

The examples demonstrate various advanced HLS techniques that can be used to improve kernel performance.