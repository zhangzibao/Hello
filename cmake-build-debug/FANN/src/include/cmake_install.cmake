# Install script for directory: G:/C++/Hello/FANN/src/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Hello")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "G:/C++/Hello/FANN/src/include/fann.h"
    "G:/C++/Hello/FANN/src/include/doublefann.h"
    "G:/C++/Hello/FANN/src/include/fann_internal.h"
    "G:/C++/Hello/FANN/src/include/floatfann.h"
    "G:/C++/Hello/FANN/src/include/fann_data.h"
    "G:/C++/Hello/FANN/src/include/fixedfann.h"
    "G:/C++/Hello/FANN/src/include/compat_time.h"
    "G:/C++/Hello/FANN/src/include/fann_activation.h"
    "G:/C++/Hello/FANN/src/include/fann_cascade.h"
    "G:/C++/Hello/FANN/src/include/fann_error.h"
    "G:/C++/Hello/FANN/src/include/fann_train.h"
    "G:/C++/Hello/FANN/src/include/fann_io.h"
    "G:/C++/Hello/FANN/src/include/fann_cpp.h"
    )
endif()

