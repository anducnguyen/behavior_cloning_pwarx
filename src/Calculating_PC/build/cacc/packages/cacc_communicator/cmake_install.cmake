# Install script for directory: /home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/src/cacc/packages/cacc_communicator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cacc_communicator" TYPE FILE FILES "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/devel/include/cacc_communicator/carParamConfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/cacc_communicator" TYPE FILE FILES "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/devel/lib/python2.7/dist-packages/cacc_communicator/__init__.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/devel/lib/python2.7/dist-packages/cacc_communicator/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/cacc_communicator" TYPE DIRECTORY FILES "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/devel/lib/python2.7/dist-packages/cacc_communicator/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/build/cacc/packages/cacc_communicator/catkin_generated/installspace/cacc_communicator.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cacc_communicator/cmake" TYPE FILE FILES
    "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/build/cacc/packages/cacc_communicator/catkin_generated/installspace/cacc_communicatorConfig.cmake"
    "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/build/cacc/packages/cacc_communicator/catkin_generated/installspace/cacc_communicatorConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cacc_communicator" TYPE FILE FILES "/home/arun/Desktop/an_ws/test_cacc/src/Calculating_PC/src/cacc/packages/cacc_communicator/package.xml")
endif()

