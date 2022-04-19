cmake_minimum_required(VERSION 3.16)
project(DA_T1_G119)

set(CMAKE_CXX_STANDARD 20)

add_executable(DA_T1_G119 main.cpp Empresa.cpp Empresa.h Carrinha.cpp Carrinha.h Encomenda.cpp Encomenda.h)

find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)
    doxygen_add_docs(documentation Carrinha.h Empresa.h Encomenda.h)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)