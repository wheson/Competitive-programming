cmake_minimum_required(VERSION 3.4)
project(OTHERS CXX)

MACRO(ADD_ALL_SUBDIR result curdir)
    FILE(GLOB_RECURSE children RELATIVE ${curdir} ${curdir}/*/CMakeLists.txt)
    SET(dirlist "")
    FOREACH(child ${children})
        get_filename_component(dir ${child} DIRECTORY)
        message(STATUS ${dir})
        LIST(APPEND dirlist ${dir})
        add_subdirectory(${dir})
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

ADD_ALL_SUBDIR(SUBDIRS ${OTHERS_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++14 -O2")