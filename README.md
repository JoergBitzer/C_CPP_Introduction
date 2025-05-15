WORK IN PROGRESS (be careful, all is subject to change)

# C_CPP_Introduction 
A short course of using C/C++ in a plattform independent way:

The goal of this course is to provide you with the tools and knowledge to develop smal programms in C ür C++ 
without relying on a plattform specific IDE (e.g. Microsoft Visual Studio or XCode). Instead we will use
tools that allows for a plattform independent tool chain (sort of).

## First Steps:
C is a compiler language. You need plattform dependent tools for the compiling process as well as for debugging.
I assume, you have git (version control) installed on your computer. if not, do so (https://git-scm.com/downloads)

### Install the necessary development tools (plattform dependend):

#### Microsoft
The Microsoft compiler suite is in its community edition free of charge. We will use that. Since you install the microsoft visual Studio compiler, you could use the IDE as well. However, this course is not the right choice than.

Download the latest Visual Studio 20xx Community edition:
https://visualstudio.microsoft.com/downloads/

and install it. 

We will use the compiler and debugger, but not the IDE.

#### MacOS
Apple has its own IDE called XCode. You can install XCode for free from the App Store or use a terminal with
```shell
xcode-select --install
```
Alternativ über den AppStore installieren. 



#### Linux
You have to install the build essentials

```shell
sudo apt update
sudo apt install build-essential g++ gdb
```

If you are interested in JUCE (Audio-Framework) development, I recommend to install also:

```shell
sudo apt install libasound2-dev libjack-jackd2-dev \
    ladspa-sdk \
    libcurl4-openssl-dev  \
    libfreetype6-dev \
    libx11-dev libxcomposite-dev libxcursor-dev libxcursor-dev libxext-dev libxinerama-dev libxrandr-dev libxrender-dev \
    libwebkit2gtk-4.0-dev \
    libglu1-mesa-dev mesa-common-dev
```

### install cmake
Install CMAKE (dont forget to select option use/change PATH for alle users)

https://cmake.org/download/


### install editor
we will use Visual Studio Code for development: 
install it from https://visualstudio.microsoft.com/downloads/

### install extensions for visual studio code

* c/cpp tools (basic language supports for C++ development) (from Microsoft)
* c/c++ ExtensionsPAck (from Microsoft)
* CMake (CMake language supports) (from twxs)
* CMake Tools (Advanced Integration for using CMake in VScode with GUI). Afterwards configure CMake (Crtl+Shift+P (Command Palette)) (from Microsoft)

### next

read howto_helloWorld.md

### A real good free resource to learn:
https://www.learncpp.com/


