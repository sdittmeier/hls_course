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

---
## 🚀 Quick Start

Start by exploring the performance optimization example:
1. [yuv_filter/](./yuv_filter) - For YUV filter with performance optimization techniques

The example demonstrates various HLS directives and pragmas that can be used to improve kernel performance.

---
## 🛠️ Requirements
- Ubuntu 20.04 or later or Windows (lab machines / ssh connection)
- Vitis Unified IDE 2025.2 or other version
- AMD Alveo platform files (e.g., `xilinx_u55c_gen3x16_xdma_3_202210_1`)
- XRT installed and configured

---
## 🔗 Related Repositories

- [Click here for Vitis Getting Started document](https://docs.amd.com/r/en-US/Vitis-Tutorials-Getting-Started/Vitis-Tutorials-Getting-Started-XD098)
- [Click here for Vitis HLS Tutorials](https://xilinx.github.io/Vitis-Tutorials/2022-1/build/html/docs/Getting_Started/Vitis_HLS/Getting_Started_Vitis_HLS.html)
- [Click here for Vitis Software Installation](https://docs.amd.com/r/en-US/ug1400-vitis-embedded/Vitis-Software-Platform-Installation)
- [Click here for XRT and Deployment Platform Installation Procedures on RedHat and CentOS](https://docs.amd.com/r/en-US/ug1301-getting-started-guide-alveo-accelerator-cards/XRT-and-Deployment-Platform-Installation-Procedures-on-RedHat-and-CentOS)

---