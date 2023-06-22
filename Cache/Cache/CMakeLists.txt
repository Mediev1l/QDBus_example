cmake_minimum_required(VERSION 3.14)

project(Cache LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core DBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus)

add_executable(Cache
  main.cpp
  ${CMAKE_SOURCE_DIR}/../dbus_files/cache_adaptor.h
  ${CMAKE_SOURCE_DIR}/../dbus_files/cache_adaptor.cpp
  Cache.h Cache.cpp
)
target_link_libraries(Cache Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus)

target_include_directories(Cache PRIVATE ${CMAKE_SOURCE_DIR}/../dbus_files/)

install(TARGETS Cache
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
