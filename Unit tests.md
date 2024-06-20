# Unit tests

Für unit tests (test driven development) gibt es mehrere Frameworks zur Unterstützung. Eine Möglichkeit ist gtest von Google. 

## Einbinden in CMAKE

### im Hauptfile CMakeLists.txt
Aus https://google.github.io/googletest/quickstart-cmake.html

Im CMAKE file kann Googletest direkt miteingebunde werden. Der folgende Code läd Googletest runter und installiert alle notwendigen Libraries

```shell
cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

```
Das File 03597a01ee50ed33e9dfd640b249b4be3799d395.zip sollte jeweils mit der aktuellen Version auf dem Repository ausgetauscht werden.

### Für die einzelnen Programme oder Funktionen
Für jede Funktionalität können nun Testdefinitionsdateien (siehe nächster Abschnitt) geschrieben werden. Hier jetzt zum Bsp Test_min.cpp um eine Funktion Min zu testen (Diese Datei hat keine main Funktion, die ist in der Lib von Google).
```shell
enable_testing()

add_executable(
  min_test
  Test_min.cpp
)
target_link_libraries(
  min_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(min_test)
```

## Simple Test Funktion schreiben

Der Vorteil der Nutzung von gtest ist, dass es sehr einfach ist Tests zu schreiben oder diese von ChatGPT erstellen zu lassen. 
```shell
Schreibe UnitTests mit der google testsuite für die folgende Funktion/Klasse:
HIER IHR CODE
```
Üblicherweise bekommt man alle Grundtests direkt zurück. Aber Achtung, häufig sind die Testergebnisse falsch. ChatGPT dient nur dazu ein Grundgerüst schnell aufbauen zu können. Die richtigen Tests zu designen ist immer noch eine Entwicklungsaufgabe.

## Google Testsuite Grundfunktionen für Tests

TBD

## Konkretes Bsp

TBD
