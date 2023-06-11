# CMakeList.txt : CMake project for inverse_root_benchmark, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (inverse_root_benchmark "inverse_root_benchmark.cpp")

set_property(TARGET inverse_root_benchmark PROPERTY CXX_STANDARD 20)

if (MVCS)
	set(ASSEMBLY_LISTING_FILE "inverse_root_benchmark.s")
	target_compile_options(inverse_root_benchmark PRIVATE "/Fa${CMAKE_CURRENT_BINARY_DIR}/${ASSEMBLY_LISTING_FILE}" /FA)
else()
	set(inverse_root_benchmark PRIVATE "-S")
endif()

# TODO: Add tests and install targets if needed.
