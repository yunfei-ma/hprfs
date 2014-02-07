#!/bin/bash
#dd if=../../sam3s_simple/sam3s_test.bin of=generated-x.bin bs=1024 count=20
cp ../../sam3s_simple/sam3s_test.bin generated-x.bin
dd if=out/x-os.bin of=generated-x.bin bs=1024 count=40 seek=20