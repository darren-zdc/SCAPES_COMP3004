#!/bin/bash
export PATH=$PATH:~/Qt/5.13.0/gcc_64/bin
qmake -makefile -o ./Makefile SCAPES.pro
touch SCAPES.pro
make -f Makefile