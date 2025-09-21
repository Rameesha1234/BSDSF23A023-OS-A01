# BSDSF23A023-OS-A01
**Student:** Rameesha Shakeel  
**Roll No:** BSDSF23A023  
**Course:** Operating Systems  
**Assignment:** Programming Assignment – 01 (libmyutils)

This repository contains a complete solution for the Operating Systems Programming Assignment 01:
- Utility library `libmyutils` (string + file utilities)
- Static (`lib/libmyutils.a`) and shared (`lib/libmyutils.so`) libraries
- Example driver programs (`bin/client`, `bin/client_static`, `bin/client_dynamic`)
- Makefile to build multifile, static, dynamic targets, and install + man pages
- Man pages in `man/man3/`
- `REPORT.md` containing answers to report questions.

Usage (on Kali Linux):
```bash
# Build everything (static & shared libs + binaries)
make all

# Run directly linked client
./bin/client

# Run static-linked client
./bin/client_static

# To run dynamic client, add lib path:
export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH
./bin/client_dynamic

# Install (requires sudo)
sudo make install
# After install you can run `client` from anywhere and view man pages: man client
```
