#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

#include <dmlc/logging.h>
#include <tvm/runtime/packed_func.h>
#include <tvm/runtime/registry.h>

#include "callStack.h"

int main() {
  using namespace tvm;
  using namespace tvm::runtime;

  auto conn_ep = tvm::runtime::Registry::Get("rpc.Connect");
  tvm::runtime::Module conn_m = (*conn_ep)("192.168.33.205", 9096, "");
  sleep(5);

  tvm::runtime::PackedFunc test_func = conn_m.GetFunction("test.rpc.string");
  sleep(5);

  std::string ret_str = test_func(std::string("this is a test string."));
  sleep(5);

  // LOG(INFO) << "output: " << ret_str;
  sync();
  return 0;
}
