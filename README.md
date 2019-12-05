# SCAPES

The School of Computer science Assembly Programming Environment System (SCAPES) is a development
environment that allows a user to write, compile, and execute basic programs written in the School of
Computer science Assembly Programming Language (SCAPL) language. The SCAPL language is a simplified
subset of assembly language instructions, and it is described in section 3 of this document. Users of the
SCAPES system can write programs in the SCAPL language, they can compile those programs into an internal
format suitable for execution, and they can run the compiled programs.


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

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
bash InstallScript.sh
```

3. Launch the system
```shell
./SCAPES
```

## Running the tests

The default directory is `../localRepo`. All the test files and the compiled files will be located here.

Program files are files with the `.txt` extension.
Compiled files are files with the `.json` extension.

If the provided file structure is altered, select the change user type option to become a system admin, and manually set the directory with the change directory option.

### Creating a Program
Click the `Create Program` button, this will create a blank file that can then be opened and edited.

### Opening a Program
Select the file from the main menu and click `Open Program`

### Saving a Program
Click the `Save Program` button to save the program. Changing the name of the file in the bottom text box will cause it to be renamed upon saving.

### Compiling a Program
After saving and closing the program, select the program file and click `Compile Program` button to compile.
The compiled program will be appeared in the main window. You are able to view the contents of the compiled program by selectiing the compiled program file and click `Open Program`.
No json file will be created if the compiler encounters any syntax errors. Compile time errors will be shown in the bottom text box.

### Running Program
Select a compiled(JSON) file from the main menu, and click `Run Program`. Runtime errors will be shown in the bottom text box, while program output will appear in a pop-up window.

## Design Pattern
The SCAPES system contains an implementation of the Proxy design pattern to manage the security of it's preference (default directory, default programming language) options. The design pattern is found in the preferences(.cpp and .h), proxypreferences(.cpp and .h), and realpreferences(.cpp and .h) classes.

## Included Programs
D2Program1Doubling takes a set of three numbers and doubles them x times, where x is the given iterator. (eg givin 3 as a number and 2 as an iterator, it will double 3 to 6 and then 6 to 12)
D2Program2Sum takes a variable length set of numbers (size), places them in an array, and then sums them.

## Authors

Dicong Zhao \\
Marco Shen \\
Liam Costello \\

## License

This project is licensed under the MIT License
