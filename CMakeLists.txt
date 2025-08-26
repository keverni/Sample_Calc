cmake_minimum_required (VERSION 3.14)

# variables

set(PROJECT_NAME sample_calc)
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(TEST_PROJECT unittest)
set(TEST_PATH ${CMAKE_SOURCE_DIR}/test)

# project
project(${PROJECT_NAME} VERSION 1.0)

# builds

file(GLOB_RECURSE SRC_SOURCES "${SRC_PATH}/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_SOURCES})

add_executable(${TEST_PROJECT} "${TEST_PATH}/test.cpp" "${SRC_PATH}/SampleCalc.cpp")

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

# libs

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main)

target_include_directories(${TEST_PROJECT} PRIVATE ${GTEST_INCLUDE_DIRS} ${SRC_PATH})

target_link_libraries(${TEST_PROJECT} PRIVATE ${GTEST_BOOTH_LIBRARIES} 	
	gtest 
	gtest_main
)


# compiler settings

if (MSVC)

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")

	add_compile_options("/std:c++latest")
	
	target_compile_options(${PROJECT_NAME} PRIVATE
		/W4
	)

	target_compile_options(${TEST_PROJECT} PRIVATE
		/W4
	)
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)

	target_compile_options(${TEST_PROJECT} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)
endif (MSVC)


enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT})