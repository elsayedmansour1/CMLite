cmake_minimum_required(VERSION 3.5)
project(cmlite)

# Find and include Qt5 Widgets and Core
find_package(Qt5 COMPONENTS Core DBus REQUIRED)  

# Set C standard (optional but recommended)
    set(CMAKE_CXX_STANDARD 14)

# Define Variable that will contain all source files
set(SRC_LIST
wifimanager/wifimanager.cpp
ltemanager/ltemanager.cpp 
hotspotmanager/hotspotmanager.cpp 
ethernetmanager/ethernetmanager.cpp 
networkmanager/networkmanager.cpp
dbus/dbusnetworkmanager.cpp
dbus/EthernetManagerAdaptor.cpp
WrapperLib/QDBus/iQDBusInterface.cpp
main.cpp)

# Declare the executable FIRST
add_executable(cmlite ${SRC_LIST})

target_link_libraries(cmlite
    PRIVATE
    Qt5::Core           # Qt5 Core
    Qt5::DBus
)

set_target_properties(cmlite PROPERTIES AUTOMOC TRUE)



