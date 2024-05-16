# Basics in C/C++s

## Datatypes

https://en.cppreference.com/w/cpp/language/types

C/C++ have only a few basic datatypes

* void: No datatype
* int: integer number where the number of bytes is based on the machine (PC = 32Bit = 4Bytes)
* long long: at least 64 Bit integer (C++ >= 11)
* long: at least 32 Bit integer
* short: at least 16 Bit integer
* float: 32Bit floating point 
* double: 64Bit floating point
* char: one character at least 8 Bits (1Byte)
* bool: true or false (C++ only)
```C++
#include <iostream>

int main()
{
    std::cout << sizeof(short) << "\n"; 
    std::cout << sizeof(long) << "\n"; 
    std::cout << sizeof(int) << "\n"; 
    std::cout << sizeof(float) << "\n"; 
    std::cout << sizeof(double) << "\n"; 
    std::cout << sizeof(char) << "\n";
    std::cout << sizeof(bool) << "\n"; 
    return 0;
}
```
all integer datatypes can be explicitly set to unsigned (if we know no negative values are possible, often number counters).

## Selection

Selection is one of the 3 basic parts that is needed to implement algorithms. 
In C/C++ we have two methods for this
### if 
if tests if a condition is true. The condition must be in parenthesis, the following block is in braces. For a negative answer an else block is given. However, there is no elif.
```C++
int a = 3
if (a == 3)
{

}
else
{

} 
```
For the condition we have the typical operators
(<,>,<=, =>, ==, !=) and several conditions can be combined with or (|), and(&) and not (!).

### switch
for multiple selection we can use integer or enums (named, increasing integers) to select the foloowing procesing block

```C++
enum mylist
{
    first = 0,
    secondChoice,
    thirdIdea,
    whatever
}

mylist a;
a = mylist::secondChoice;

switch (a)
{
    case first:

        break;
    case secondChoice:

        break;
    
    case thirdIdea:

        break;

    case whatever:

        break;

    default:
}

```
The break in each code block stops the processing after the block, without the next case code would be processed. If no match is found, the default block is accessed. 

## Loops 
We have two different kind of loops. The first one is a typical loop over a given number of elements. The second one is based on conditions.

### for
loops with for come in different flavours. The original c based for loop is based on a 
a counter variable, an inner condition and the increasing counter (cc++ means cc = cc + 1)
```C++
for (int cc = 0; cc < 100; cc++)
{
}
```
Modern C++ has for loops over items comparable to python. To use these features, we need more complex data types, e.g. given in the standard template library (STL), which is part of the C++ language definition. However, we will look at these for loops later.

### while
while-loops exist in two flavors, 
```C++
while (condition)
{

}
```
and
```C++
do
{

} while (condition);
```
The difference is that for the do-while loop it is guaranteed that the code in the block is executed at least once. 

## functions
In contrast to python C/C++ divide functions in declaration and definition. 
Only Declarations have to be known before usage in code.
```C++
#include <iostream>

// declaration
int add(int a, int b);

int main()
{
    std::cout << add(3,4) << "\n"; 
}
// definition
int add(int a, int b)
{
    return a+b;
}
```
Usually, the declarations are in header files (*.h) and the corresponding definitions in source files (*.cpp)
In the main file we include our new header file, since it is in the same directory we use "".

```C++
#include <iostream>
#include "Simplemath.h"
int main()
{
    std::cout << add(3,4) << "\n"; 
}
```
The second source file (Simplemath.cpp) looks like this:
```C++
#include "Simplemath.h"

int add(int a, int b)
{
    return a+b;
}
```
And the corresponding header (Simplemath.h). The #pragma once is a microsoft specific solution to build a header guard (which works for most compilers (gcc, xcode)). This is necessary to prevent multiple declarations of one function, if the header is included more than one time. 
```C++
#pragma once
// declaration
int add(int a, int b);
```
The old school header guard looks like this
```C++
#ifndef _SIMPLE_MATH_H_ // or any other ID that is unique (You can UDE GUID)
#define _SIMPLE_MATH_H_
// declaration
int add(int a, int b);
#endif
```
## Class

object oriented programming

methods
member variables

inheritance 

# Next steps
read STL_in_c.md

