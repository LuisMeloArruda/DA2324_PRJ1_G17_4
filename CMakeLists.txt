cmake_minimum_required(VERSION 3.23)
project(DA2324_PRJ1_G17_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA2324_PRJ1_G17_4
        src/Menu.cpp
        src/Menu.h
        src/main.cpp
        src/Graph.h
        src/Station.h
        src/Station.cpp
        src/Reservoir.h
        src/Reservoir.cpp
        src/City.cpp
        src/City.h
        src/Manager.cpp
        src/Manager.h
        src/Pipe.h
        src/Pipe.cpp
)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)