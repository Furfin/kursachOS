# Install script for directory: /home/furf1n/Desktop/sketch/vuz_prog/OSprogs/kurs/kursach

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/furf1n/Desktop/sketch/vuz_prog/OSprogs/kurs/build-kursach-Desktop_Qt_6_4_2_GCC_64bit-Debug/kursach")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach"
         OLD_RPATH "/home/furf1n/Qt/6.4.2/gcc_64/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kursach")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/furf1n/Desktop/sketch/vuz_prog/OSprogs/kurs/build-kursach-Desktop_Qt_6_4_2_GCC_64bit-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
