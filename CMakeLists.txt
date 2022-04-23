cmake_minimum_required(VERSION 3.0.0)
project("PersonalTools" VERSION 0.1.0 LANGUAGES "CXX" "C")

SET(CPACK_PROJECT_NAME ${PROJECT_NAME})
SET(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Some comstem define var 
IF (NOT DEFINED BUILD_BINRARY_TYPE)
    MESSAGE(FATAL_ERROR "Build binrary type are not defined!")
ENDIF()

# set output directories for all builds (Debug, Release, etc.)
FOREACH( OUTPUTCONFIG ${CMAKE_BUILD_TYPE} )
    STRING( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    SET( "CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG}" "${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}" )
    SET( "CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG}" "${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}" )
    SET( "CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG}" "${CMAKE_SOURCE_DIR}/${CMAKE_BUILD_TYPE}" )
ENDFOREACH( OUTPUTCONFIG CMAKE_BUILD_TYPE )

#===========================================================================================
# Compile flags options: -static -mwindows|-mconsole
#===========================================================================================

SET(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS}                  ")
SET(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG   ")
SET(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE}          ")
SET(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL}       ")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}   ")

SET(CMAKE_CXX_STANDARD_LIBRARIES   "${CMAKE_CXX_STANDARD_LIBRARIES} -static -mwindows -ldbghelp -lcomctl32 ")

SET(CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS}                    ")
SET(CMAKE_C_FLAGS_DEBUG            "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG     ")
SET(CMAKE_C_FLAGS_RELEASE          "${CMAKE_C_FLAGS_RELEASE}            ")
SET(CMAKE_C_FLAGS_MINSIZEREL       "${CMAKE_C_FLAGS_MINSIZEREL}         ")
SET(CMAKE_C_FLAGS_RELWITHDEBINFO   "${CMAKE_C_FLAGS_RELWITHDEBINFO}     ")

SET(CMAKE_C_STANDARD_LIBRARIES     "${CMAKE_C_STANDARD_LIBRARIES} -static -mwindows -ldbghelp -lcomctl32 ")

#===========================================================================================
# Linker flags option: -static -mwindows|-mconsole
#===========================================================================================

SET(CMAKE_RC_LINKER_FLAGS                     "${CMAKE_RC_LINKER_FLAGS}                      ")
SET(CMAKE_RC_LINKER_FLAGS_DEBUG               "${CMAKE_RC_LINKER_FLAGS_DEBUG}                ")
SET(CMAKE_RC_LINKER_FLAGS_RELEASE             "${CMAKE_RC_LINKER_FLAGS_RELEASE} -s           ")
SET(CMAKE_RC_LINKER_FLAGS_MINSIZEREL          "${CMAKE_RC_LINKER_FLAGS_MINSIZEREL} -s        ")
SET(CMAKE_RC_LINKER_FLAGS_RELWITHDEBINFO      "${CMAKE_RC_LINKER_FLAGS_RELWITHDEBINFO} -s    ")

SET(CMAKE_EXE_LINKER_FLAGS                    "${CMAKE_EXE_LINKER_FLAGS}                     ")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG              "${CMAKE_EXE_LINKER_FLAGS_DEBUG}               ")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE            "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -s          ")
SET(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL         "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} -s       ")
SET(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO     "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} -s   ")

SET(CMAKE_SHARED_LINKER_FLAGS                 "${CMAKE_SHARED_LINKER_FLAGS}                  ")
SET(CMAKE_SHARED_LINKER_FLAGS_DEBUG           "${CMAKE_SHARED_LINKER_FLAGS_DEBUG}            ")
SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE         "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -s       ")
SET(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL      "${CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL} -s    ")
SET(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO  "${CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO} -s")

SET(CMAKE_STATIC_LINKER_FLAGS                 "${CMAKE_STATIC_LINKER_FLAGS}                  ")
SET(CMAKE_STATIC_LINKER_FLAGS_DEBUG           "${CMAKE_STATIC_LINKER_FLAGS_DEBUG}            ")
SET(CMAKE_STATIC_LINKER_FLAGS_RELEASE         "${CMAKE_STATIC_LINKER_FLAGS_RELEASE} -s       ")
SET(CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL      "${CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL} -s    ")
SET(CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO  "${CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO} -s")

SET(CMAKE_MODULE_LINKER_FLAGS                 "${CMAKE_MODULE_LINKER_FLAGS}                  ")
SET(CMAKE_MODULE_LINKER_FLAGS_DEBUG           "${CMAKE_MODULE_LINKER_FLAGS_DEBUG}            ")
SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE         "${CMAKE_MODULE_LINKER_FLAGS_RELEASE} -s       ")
SET(CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL      "${CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL} -s    ")
SET(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO  "${CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO} -s")

#===========================================================================================
# Source && header search files link to vars
#===========================================================================================

FILE(GLOB_RECURSE PATH_SRCS_LIST 
    "Source/Common.cpp"
    "Source/*.cpp" "Source/*.c"
    "Library/*.cpp" "Library/*.c"

    "Source/*.def"
    "Source/*.rc"
)
MESSAGE(STATUS "PATH_SRCS_LIST = ${PATH_SRCS_LIST}")

#FILE(GLOB_RECURSE PATH_INCS_LIST
#    "Source/*.hpp" "Source/*.h"
#    "Library/*.hpp" "Library/*.h"
#)
#MESSAGE(STATUS "PATH_INCS_LIST = ${PATH_INCS_LIST}")

MACRO(FUNC_FIND_HEADER_FILE result srcdir)
    FILE(GLOB_RECURSE children "${srcdir}/*.hpp" "${srcdir}/*.h" )
    MESSAGE(STATUS "children= ${children}")
    SET(dirlist "")
    FOREACH(child ${children})
        STRING(REGEX REPLACE "(.*)/.*" "\\1" LIB_NAME ${child})
        IF(IS_DIRECTORY ${LIB_NAME})
            LIST(APPEND dirlist ${LIB_NAME})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

FUNC_FIND_HEADER_FILE(PATH_INCS_LIST ${PROJECT_SOURCE_DIR}/Source)
FUNC_FIND_HEADER_FILE(PATH_INCS_LIST ${PROJECT_SOURCE_DIR}/Library)
INCLUDE_DIRECTORIES(${PATH_INCS_LIST}) #add found header files

#===========================================================================================
# Build binrarys type output
#===========================================================================================

IF(${BUILD_BINRARY_TYPE} STREQUAL "exe")
    ADD_EXECUTABLE("${PROJECT_NAME}" "${PATH_SRCS_LIST}")
ELSEIF(${BUILD_BINRARY_TYPE} STREQUAL "dll")
    ADD_LIBRARY("${PROJECT_NAME}" SHARED "${PATH_SRCS_LIST}")
ELSEIF(${BUILD_BINRARY_TYPE} STREQUAL "lib")
    ADD_LIBRARY("${PROJECT_NAME}" STATIC "${PATH_SRCS_LIST}")
ELSEIF(${BUILD_BINRARY_TYPE} STREQUAL "mod")
    ADD_LIBRARY("${PROJECT_NAME}" MODULE "${PATH_SRCS_LIST}")
ELSEIF(${BUILD_BINRARY_TYPE} STREQUAL "mod")
    ADD_LIBRARY("${PROJECT_NAME}" MODULE "${PATH_SRCS_LIST}")
ENDIF()

# TARGET_LINK_LIBRARIES("${PROJECT_NAME}" "${PATH_SRCS_LIST}")
