#pragma once

#include <optional>
#include <string>

namespace instrumentation {

struct ResolvedFrame {
  std::string timestamp;
  std::optional<void *> callee_address;
  std::string callee_function_name;
  std::string caller_filename;
  std::optional<unsigned int> caller_line_number;
};

} // namespace instrumentation
