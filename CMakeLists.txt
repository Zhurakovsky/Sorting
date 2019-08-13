cmake_minimum_required(VERSION 3.14)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorting main.cpp BubbleSort.cpp BubbleSort.h RandomGenerator.h BinarySearch.h TreeSort.h Node.h Heap.h QuickSort.h Routes.h GrowingSequence.h RadixSort.h)