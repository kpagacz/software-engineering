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

template <typename T>
struct StringMaker<std::unordered_set<T>> {
  static String convert(const std::unordered_set<T>& set) {
    std::ostringstream oss;
    oss << "{ ";
    std::copy(set.begin(), set.end(), std::ostream_iterator<T>(oss, " "));
    oss << "}";
    return oss.str().c_str();
  }
};
}  // namespace doctest
