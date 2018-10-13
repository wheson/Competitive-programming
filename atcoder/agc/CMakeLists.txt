cmake_minimum_required(VERSION 3.4)
project(AGC CXX)

# サブディレクトリ内のソースをすべてプロジェクトにぶちこむマクロ
MACRO(ADD_ALL_SUBDIR result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
            # CMakeがディレクトリにあるか(1のパターン)無いか(2のパターン)で分岐
            IF(EXISTS ${curdir}/${child}/CMakeLists.txt)
                add_subdirectory(${child})
            ELSE()
                aux_source_directory(${child} SOURCE)
            ENDIF()
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

ADD_ALL_SUBDIR(SUBDIRS ${AGC_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++14 -O2")

IF(SOURCE)
    add_executable(AGC ${SOURCE})
ENDIF()
