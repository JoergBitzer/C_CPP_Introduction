
set(TARGET_NAME VersioningTest)

project(${TARGET_NAME} VERSION 0.1.0)

add_executable(${TARGET_NAME} main.cpp)

configure_file(version.h.in version.h @ONLY)

target_include_directories(${TARGET_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
