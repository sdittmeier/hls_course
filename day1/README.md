# Tutorial: Getting started with HLS

This part of the lecture is meant to familiarize you with the Vitis HLS tool flow.

---

## 📂 Project Structure Overview
```
hls_course/day1/
├── vadd                  # Vector addition kernel project with documentation and source
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


### 🔧 [`vadd/`](./vadd)
This folder contains the example project for hardware acceleration using Vitis Unified IDE 2024.2.  
This repository is split into multiple stages:

- **[Part 1](./vadd/part1.md):** Vitis Flow 101 – Essential Concepts 
- **[Part 2](./vadd/part2.md):** Environment Setup
- **[Part 3](./vadd/part3.md):** Review the Kernel Code and Host Application
- **[Part 4](./vadd/part4.md):** Creating an example HLS component on Vitis Unified, Optimizations & Reviwing reports
- **[Part 5](./vadd/part5.md):** Creating Application Component and System Project

Each part builds on the previous and is designed to be clear and reproducible.


📁 See [vadd/src](./vadd/src) for the actual HLS and host source files.

---

## 🚀 Quick Start

Start by following [part1.md](vadd/part1.md) to set up your environment and clone the repository.

From there, proceed to part2.md and part3.md and so on in order.

