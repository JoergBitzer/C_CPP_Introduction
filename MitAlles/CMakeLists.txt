
set(TARGET_NAME "MitAlles")

project(${TARGET_NAME} VERSION 1.0.0)

add_executable(${TARGET_NAME}   main.cpp 
                                NoiseGenerator.cpp 
                                NoiseGenerator.h 
                                SinusGenerator.cpp 
                                SinusGenerator.h 
                                FIR.cpp 
                                FIR.h)

configure_file(version.h.in version.h @ONLY)


target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/WaveLib)
target_include_directories(${TARGET_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
target_link_libraries(${TARGET_NAME} WaveLib)
                           