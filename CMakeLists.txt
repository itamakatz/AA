cmake_minimum_required(VERSION 3.5)
project(Protein_Matching)
find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp primes.h lcs.h primes.cpp lcs.cpp gcd.cpp gcd.h amino_acid_properties.cpp amino_acid_properties.h Protein.cpp Protein.h AA.cpp AA.h CSV.h tests.h)
add_executable(AA ${SOURCE_FILES})
target_link_libraries( AA ${OpenCV_LIBS} )

INCLUDE_DIRECTORIES(/usr/local/boost_1_64_0)