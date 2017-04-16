cmake_minimum_required(VERSION 3.5)
project(Protein_Matching)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp primes.h lcs.h primes.cpp lcs.cpp gcd.cpp gcd.h amino_acids.cpp amino_acids.h)
add_executable(Protein_Matching ${SOURCE_FILES})