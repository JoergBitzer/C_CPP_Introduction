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

### per target
target_compile_definitions(${TARGET_NAME} PUBLIC  <definitions> )

