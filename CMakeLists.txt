cmake_minimum_required(VERSION 2.8.9)
project(SumProject)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(sum-llvm-ir sum.cpp)
target_compile_features(sum-llvm-ir PRIVATE cxx_range_for)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs core)

# Link against LLVM libraries
target_link_libraries(sum-llvm-ir ${llvm_libs})
