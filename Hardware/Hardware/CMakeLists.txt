cmake_minimum_required(VERSION 3.14)

project(Hardware LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core DBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus)

add_executable(Hardware
  main.cpp
  ${CMAKE_SOURCE_DIR}/../dbus_files/hardware_adaptor.h
  ${CMAKE_SOURCE_DIR}/../dbus_files/hardware_adaptor.cpp
  Hardware.h Hardware.cpp
)
target_link_libraries(Hardware Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus)
target_include_directories(Hardware PRIVATE ${CMAKE_SOURCE_DIR}/../dbus_files/)

install(TARGETS Hardware
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
