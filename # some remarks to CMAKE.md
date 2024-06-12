# some remarks to CMAKE

## important variables in CMAKE

https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables

## how to define and use your own variables

SET(VARIABLE_NAME What_it_is)

example:

SET(PROGRAM_SRCS
        program.c
        program_utils.c
        a_lib.c
        b_lib.c
        config.c
        )

Use variable with ${VARIABLE_NAME}:

example: add_executable(program "${PROGRAM_SRCS}")

read more: https://stackoverflow.com/questions/31037882/whats-the-cmake-syntax-to-set-and-use-variables

## set the c++ standard in CMAKE (I recommend to use 14 or 17)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)

## Add Compile defintion for your code
### globally
add_compile_definitions(<definition> ...)

### per target (This is good practice)
target_compile_definitions(${TARGET_NAME} PRIVATE  <definitions> )

## or options
target_compile_options(${TARGET_NAME} PRIVATE -Werror) # All warnings are error

## Easier way to use all *cpp files with GLOB
GLOB scans for all files with cpp and stores the filenames in SRC_FILES

file(GLOB SRC_FILES *.cpp)
add_executable(program "${SRC_FILES}")


## Shared and static Libs
add_library(MyLib SHARED source1.c source2.c)
add_library(MyLibStatic STATIC source1.c source2.c)

do not forget (important for JUCE binary files)
set_property(MyLib PROPERTY POSITION_INDEPENDENT_CODE 1)


## compiler definitions defined in CMAKE
How to inject defines from CMAKE, for example to have builds with cout and without

TBD

## Version numbering
Good starting point is Semantic version number (see for example python versions e.g. 3.11.8)
major, minor, Patch

and how to use that with CMAKE

TBD


### good source for more

https://cliutils.gitlab.io/modern-cmake/
