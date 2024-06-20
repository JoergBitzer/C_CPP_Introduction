

SET(TARGET_NAME "WaveLibUser")
add_executable(${TARGET_NAME} main.cpp)
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/WaveLib)
target_link_libraries(${TARGET_NAME} WaveLib)

# if you have an external library:
# target_link_directories(${TARGET_NAME} PRIVATE ${PROJECT_BINARY_DIR}/WaveLib)