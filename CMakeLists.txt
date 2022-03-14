cmake_minimum_required(VERSION 3.16)
project(LegendOfNeutrinos VERSION 1.0.0)


# prepare
find_package(ROOT REQUIRED)

## pybind11
add_subdirectory(extern/pybind/pybind11)
## Google Sanity check
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/arsenm/sanitizers-cmake/cmake)
find_package(Sanitizers MODULE REQUIRED)

## install path
include(GNUInstallDirs)


# add sub-modules
add_subdirectory(Borexino)