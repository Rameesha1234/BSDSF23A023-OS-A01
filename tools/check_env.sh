#!/bin/bash
echo "GCC version:"
gcc --version | head -n1
echo
echo "Building project..."
make all
echo
echo "Listing files:"
ls -lh lib bin
echo
echo "To run dynamic client:"
echo "export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH"
echo "./bin/client_dynamic"
