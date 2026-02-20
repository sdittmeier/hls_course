# FPGA programming with HLS

Welcome to the workspace of the "FPGA programming with HLS" -- course at Heidelberg University, Summer 2026! This repository organizes several components used for FPGA-based acceleration and remote user setup. Each directory focuses on a specific part of the workflow.

---

## 📂 Project Structure Overview
```
hls_course/
├── vadd          # Vector addition kernel project with documentation and source
    └── part1.md          # Introduction to Vitis Flow
    └── part2.md          # Environment Setup
    └── part3.md          # Code review
    └── part4.md          # HLS component steps
    └── part5.md          # Host and system project
    └── README.md         # This file
    └── src/              # Kernel source
        └── krnl_vadd.cpp       #Kernel source file
        └── krnl_vadd.h         #Kernel source file
        └── krnl_vadd_test.cpp  #Kernel testbench file
        └── vadd.cpp            #OpenCL Host application source file
        └── vadd.h              #OpenCL Host application source file
        └── host.cpp            #native XRT Host application source file
        └── hls_config.cfg      #example configuration file
├── README.md     # This file
```

---

## 📜 Component Details


### 🖥️ [`setup/`](./setup)
Instructions and scripts to run the toolchain.

---

### 🔧 [`vadd/`](./vadd)
This folder contains the example project for hardware acceleration using Vitis Unified IDE 2024.2.  
Includes a multi-part walkthrough:
- [`part1.md`](./vadd/part1.md): Introduction to Vitis Flow
- [`part2.md`](./vadd/part2.md): Environment Setup  
- [`part3.md`](./vadd/part3.md): Code review
- [`part4.md`](./vadd/part4.md): Creating HLS component  
- [`part5.md`](./vadd/part5.md): Creating Host and system project

📁 See [vadd/src](./vadd/src) for the actual HLS and host source files.

---

## 🚀 Quick Start

Start by following [part1.md](vadd/part1.md) to set up your environment and clone the repository.

From there, proceed to part2.md and part3.md and so on in order.

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
