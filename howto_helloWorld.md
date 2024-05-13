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




