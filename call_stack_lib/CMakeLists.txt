set(call_stack_lib_SRCS
  call_stack_lib.cpp
)

add_library(call_stack_lib SHARED ${call_stack_lib_SRCS})
target_link_libraries(call_stack_lib ${TVM_RUNTIME_LIBS} pthread dl)
# target_link_libraries(test_app dl bfd)

