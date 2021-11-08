cmake_minimum_required(VERSION 3.2)


project(call_stack_test C CXX)


set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)


#execute_process(COMMAND	"sh -c `gcc -print-prog-name=cc1plus` -v < /dev/null 2>&1
#								| LC_ALL=C sed -ne '/starts here/,/End of/p'
#								| grep -o '/[^\"]*' "
#				COMMAND	"sh -c 		`gcc -print-prog-name=cpp` -v < /dev/null 2>&1 \
#								| LC_ALL=C sed -ne '/starts here/,/End of/p' \
#								| grep -o '/[^\"]*' ) \
#						| cat | sort | uniq | tr '\n' ',' | sed 's/\(.*\),/\1 /' | xargs"
#                OUTPUT_VARIABLE CPP_STD_INC)
#message(STATUS ${CPP_STD_INC})

string(CONCAT cpp_std_inc_str
    "/usr/include,/usr/include/c++/5,/usr/include/c++/5/backward,/usr/include/x86_64-linux-gnu,"
    "/usr/include/x86_64-linux-gnu/c++/5,/usr/lib/gcc/x86_64-linux-gnu/5/include,/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed,"
    "/usr/lib/gcc/x86_64-linux-gnu/7/include,/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed,/usr/local/include,app/callStack.h,"
    "app/unwinder.h,app/types.h,app/format.h,app/prettyTime.h"
)

set(CPP_STD_INCLUDES "${cpp_std_inc_str}")

set(CMAKE_C_FLAGS "-O0 -g -Wall -rdynamic -std=c++17 -finstrument-functions -fPIC ${CMAKE_C_FLAGS} -finstrument-functions-exclude-file-list=${CPP_STD_INCLUDES}")
set(CMAKE_CXX_FLAGS "-O0 -g -Wall -rdynamic -std=c++17 -finstrument-functions -fPIC ${CMAKE_CXX_FLAGS} -finstrument-functions-exclude-file-list=${CPP_STD_INCLUDES}")

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

include_directories("${PROJECT_SOURCE_DIR}/app")
include_directories("${PROJECT_SOURCE_DIR}/call_stack_lib")
link_directories("${PROJECT_SOURCE_DIR}/lib")


add_subdirectory("call_stack_lib")
add_subdirectory("app")

