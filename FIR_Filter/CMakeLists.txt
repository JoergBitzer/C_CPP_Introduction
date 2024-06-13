
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

SET(UNITTEST_TARGET FirUnitTests)

add_executable(
    ${UNITTEST_TARGET}
    FirUnitTests.cpp
    FIR.cpp
)
target_link_libraries(
    ${UNITTEST_TARGET}
    GTest::gtest_main
)
set_target_properties(${UNITTEST_TARGET} PROPERTIES CXX_STANDARD 14)
set_target_properties(${UNITTEST_TARGET} PROPERTIES CXX_STANDARD_REQUIRED ON)

include(GoogleTest)
gtest_discover_tests(${UNITTEST_TARGET})

# mein test
add_executable(FirTest TestFirMain.cpp FIR.cpp)
target_compile_definitions(FirTest PRIVATE FASTMODE SUPERFASTMODE)

