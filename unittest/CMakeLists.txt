cmake_minimum_required(VERSION 3.5)
project(unittest)

include(gcov.cmake)
# Enable C++14
set(CMAKE_CXX_STANDARD  14)

# Find Qt5 Core
find_package(Qt5 COMPONENTS Core DBus Test REQUIRED)  # <-- Add Widgets here!
find_package(GTest REQUIRED)

# Define Variable that will contain all source files
set(SRC_LIST
wifimanagertest.cpp
ltemanagertest.cpp 
hotspotmanagertest.cpp 
ethernetmanagertest.cpp 
../source/ethernetmanager/ethernetmanager.cpp
../source/WrapperLib/QDBus/iQDBusInterface.cpp
main.cpp)

# Declare the executable FIRST
add_executable(cmlite_test ${SRC_LIST})


# Link libraries AFTER declaring the executable
target_link_libraries(cmlite_test
    PRIVATE
    Qt5::Core           # Qt5 Core
    GTest::gtest        # Google Test 
    GTest::gmock        # Google Mock
    Qt5::Test
    Qt5::DBus
)

set_target_properties(cmlite_test PROPERTIES AUTOMOC TRUE)

# Enable position-independent code
set_target_properties(cmlite_test PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
