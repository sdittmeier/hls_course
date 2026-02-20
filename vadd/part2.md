<h1>🔧 Environment Setup</h1>

Welcome to the HLS course! This section walks you through setting up and cloning the example project used in the hands-on sessions.

---

### 1. Connect to the server "Curvaton":
## for Linux users
Open a terminal and connect via SSH with **X11 forwarding**.
```bash
ssh -Y your_username@curvaton.physi.uni-heidelberg.de
```
## for Mac users
1. Install XQuartz (the X11 server for macOS):
    - Download from: https://www.xquartz.org
    - Install it and log out / log back in after installation.
2. Start XQuartz before connecting.
    - It automatically sets the DISPLAY variable needed for X11 forwarding.
3. Open the Terminal (or iTerm2) and connect via SSH:
```bash
ssh -Y your_username@curvaton.physi.uni-heidelberg.de
```
>⚠️ The -Y option is recommended for macOS because many GUI applications (like Vitis) require trusted X11 forwarding.

## for Windows users
1. Download and install [MobaXterm](https://mobaxterm.mobatek.net).
2. Open MobaXterm → Start local terminal.
3. Click Session → SSH, enter:
    - Remote host: curvaton.physi.uni-heidelberg.de
    - Username: your_username
    - Advanced SSH settings: Enable X11 forwarding (checkbox set by default)
4. Connect and launch GUI apps — X11 forwarding works automatically.


### 2. After you connect for the first time to the server:
You want to add the following lines to your `~/.bashrc` 

```bash
export XILINXD_LICENSE_FILE=REPLACE_WITH_PORT_GIVEN_IN_LECTURE
export XILINX_PATH=/mnt/data1/xilinx
export XILINX_VERSION=2025.2
export PLATFORM_REPO_PATHS=/opt/xilinx/platforms/platforms

source $XILINX_PATH/$XILINX_VERSION/Vitis/settings64.sh
source /opt/xilinx/xrt/setup.sh
```
After updating the `~/.bashrc`, make sure to source it: `source ~/.bashrc`.
This sets the Xilinx environment for you.
Next time you log into the server, the Xilinx environment will be automatically set up, so you don't need to repeat this step later in this course. 

## 📂 Project Checkout

## Create a working directory for the HLS projects:

```bash
mkdir ~/hls
cd ~/hls
```

## Clone the example repository:

```bash
git clone https://github.com/sdittmeier/hls_course.git
```

You are now ready to begin working on the example vector addition project.

---

## Next Step

  **Click here to [Review the Host and Kernel Code](./part3.md)**
