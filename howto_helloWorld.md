# How to program you first Hello World
I assume you read the ReadMe.md and installed all necessary tools

## concepts of C/C++
C/C++ are compiler languages. So you program by writing simple text files with typical endings (*.c, *.cpp, *.h, *.hpp) and
compile these files. The compiler will compile your code to machine code (*.obj) and afterwards the linker will link the object code 
to an executable file (or a library). To configure the compile and link step, we will use CMAKE.

## A simple program in c++

### create a new subdirectory for your first program

### Save the following program as helloworldmain.cpp

```C++
#include <iostream>

int main()
{
    std::cout << "Hello World \n"; 
    return 0;
}
```

### configure compiler and linker via CMAKE

Save the following text (CMAKE code) as CMakeLists.txt
```CMAKE
cmake_minimum_required(VERSION 3.4)

project(hello_world)

add_executable(FirstProgramm helloworldmain.cpp)
```

### build programm via cmake

#### CLI
CMAKE generates lots of clutter files. To avoid to clutter your project, use a special build subdirectory.
The plattform independent way is via cmake itsself

```Shell
cmake -E make_directory build
cmake -E chdir build cmake .. 
cmake --build build 
```

#### Visual Code CMAKE extension
I am not sure, why cmake extension starts or not. However, left mouse click on CmakeLists.txt 
has the commands "Build All Projects". This starts a process to choose a sub-directory and start the cmake extension.


### Start your programm
You will find your program in the build subdirectory. You can start it by entering its name in the terminal. For Linux don't forget the directory
```Shell
./FirstProgramm
```
for Windows ist should read FirstProgramm.exe

## Explain the program and steps:

### Programm
All programs (applications) have one entry point in C/C++, that is the main function. The definition is
```C++
int main (int argc, char** argv)
```
Since C/C++ is a strict language in terms of data types, every variable must be defined. In C++ a simplification is possible by using the data-type auto. If you are sure, what you need, I recommend to use the explicit data-type like int for integer values, float for 32Bit floating point, double for 64Bit floating point numbers, char for characters (or Byte fields, since sizeof(char) = 1 Byte)

Each function can have one return variable, the data type is given before the function name (here main). The following variable list is for the main function optional. Therefore int main() is OK.

In C/C++ blocks (functions, if clauses, loops) are declared by curly braces {} (in Python it is coded by indent) and each statement has to be finished with a semicolon ;
```C++
int main (int argc, char** argv)
{
    return 0;
}
```
Since we have defined a return value (int), we have to return an int, by using the command return.

```C++
#include <iostream>

int main()
{
    std::cout << "Hello World \n"; 
    return 0;
}
```
To output variables (text or numbers) to the standard console/terminal we have several commands. In C++ it is console out (cout). This function is defined in the header iostream (python import) and it is part of the namespace std (python example numpy.abs, where numpy is the namespace). A C alternative is printf("Hello World!\n"); defined in stdio.h 
```C
#include <stdio.h>

int main()
{
    printf("Hello World \n"); 
    return 0;
}
```
### CMAKE code
A main CMakeLists.txt file (it is possible to have several in one project in sub-directories) has two necessary lines. One defines the minimum version of CMAKE (here 3.4) and the project name (here hello_world).
```CMAKE
cmake_minimum_required(VERSION 3.4)
project(hello_world)
```
After that CMake has many commands to configure programs, libraries and their dependencies. For this simple example, we want to build one executable. the name of the executable is FirstProgram and it has only one source code file named helloworldmain.cpp
```CMAKE

add_executable(FirstProgramm helloworldmain.cpp)
```
### CLI Code
The three command line interface commands are used to reduce clutter. 
The first one is a plattform independent way to make a new directory (All necessary directories for subsubdirectories will be created. If the new directory already exists, the command is ignored). The second line are two commands, first to change the directory (here change to the new sub-directory build) and afterwards start cmake in the directory above (..), because there is the CMakeLists.txt main file. This file generates all the necessary output files to start the building process in the subdirectory where cmake was started from (here build). The last line starts the build process (--build) in the sub-directory build.
```Shell
cmake -E make_directory build
cmake -E chdir build cmake .. 
cmake --build build 
```


