# SCAPES

The School of Computer science Assembly Programming Environment System (SCAPES) is a development
environment that allows a user to write, compile, and execute basic programs written in the School of
Computer science Assembly Programming Language (SCAPL) language. The SCAPL language is a simplified
subset of assembly language instructions, and it is described in section 3 of this document. Users of the
SCAPES system can write programs in the SCAPL language, they can compile those programs into an internal
format suitable for execution, and they can run the compiled programs.


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

1. COMP3004 VM
2. Linux Bash


### Installing

1. Unzip the file
```shell
unzip SCAPES.zip
```
2. Build the SCAPES system
```shell
cd SCAPES
qmake -makefile -o ./Makefile SCAPES.pro
make -f Makefile
```

3. Launch the system
```shell
./SCAPES
```

## Running the tests

The default directory is `../localRepo`. All the test files and the compiled files will be located here.

Program file is the file with `.txt` extension.
Compiled file is the file with `.json` extension.

### Open Program
Select the file from the main menu and click `Open Program`

### Create Program
Simply click the `Create Program` button. And edit your program inside the main dialog. 

### Save Program
Click the `Save Program` button to save the program.


### Compiled Program
After Saving the program, select the program file and click `Compile Program` button to compile.
The compiled program will be appeared in the main window. You are able to view the compiled program by selectiing the compiled program file and click `Open Program`.



## Authors

Dicong Zhao <br />
Marco Shen <br />
Liam Costello  <br />

## License

This project is licensed under the MIT License

