cmake_minimum_required(VERSION 3.10)
project(AED2324_PRJ1_G11)

set(CMAKE_CXX_STANDARD 11)


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

add_executable(AED2324_PRJ1_G11 code/main.cpp
        code/Turma.h
        code/Aluno.h
        code/Aluno.cpp
        code/Turma.cpp
        code/Log.h
        code/Log.cpp
        code/Operation.cpp
        code/Operation.h
        code/Data/students_classes.csv
        code/Data/classes.csv
        code/Data/classes_per_uc.csv
        code/DataReader.cpp
        code/DataReader.h
        code/BSTree.cpp
        code/BSTree.h
)

