set(APP_SRCS
  main.cpp
  callStack.cpp
  trace.cpp
)

add_executable(test_app ${APP_SRCS})
target_link_libraries(test_app dl bfd call_stack_lib)

