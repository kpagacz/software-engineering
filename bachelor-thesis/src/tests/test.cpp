#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iterator>
#include <vector>

#include "../../lib/doctest.h"

namespace doctest {
template <typename T>
struct StringMaker<std::vector<T>> {
  static String convert(const std::vector<T>& vec) {
    std::ostringstream oss;
    oss << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(oss, " "));
    oss << "]";
    return oss.str().c_str();
  }
};
}  // namespace doctest
