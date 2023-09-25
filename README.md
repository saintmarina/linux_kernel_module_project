# linux_kernel_module_project
Project from Operating System Concepts chapter 2 "Linux Kernel Modules"

## Run
To run **hello.c***:
1. Change the first line of Makefile to:
```bash
obj-m += hello.c
```
2. Run in the terminal:
```bash
make
sudo insmod hello.ko
cat /proc/hello
```
3. Remove the module:
```
sudo rmmod hello
```

To run **jiffies.c*** change the first line of Makefile to:
1. Change the first line of Makefile to:
```bash
obj-m += jiffies.c
```
2. Run in the terminal:
```bash
make
sudo insmod jiffies.ko
cat /proc/jiffies
```
3. Remove the module:
```
sudo rmmod jiffies
```

To run **seconds.c*** change the first line of Makefile to:
1. Change the first line of Makefile to:
```bash
obj-m += seconds.c
```
2. Run in the terminal:
```bash
make
sudo insmod seconds.ko
cat /proc/seconds
```
3. Remove the module:
```
sudo rmmod seconds
```

To run **simple.c**:
1. 1. Change the first line of Makefile to:
```bash
obj-m += simple.c
```
2. Run in the terminal:
```bash
make
sudo insmod simple.ko
sudo dmesg
```
3. Remove the module:
```
sudo rmmod seconds
```

## Useful commands
```bash
sudo insmod module.ko   # Load kernel module
sudo rmmod module       # Remove kernel module
lsmod                   # Check whether the module has loaded
sudo dmesg              # Check the contents of messages in the kernel log buffer
sudo dmesg -c           # Clean  the kernel log buffer
```
