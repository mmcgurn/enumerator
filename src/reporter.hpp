#ifndef ENUMERATOR_REPORTER_HPP
#define ENUMERATOR_REPORTER_HPP

#include <map>
#include <string>

namespace enumerator {

class Reporter {
   public:
    virtual ~Reporter() = default;
    virtual void Report(const std::string& caseName, const std::map<std::string, std::string>& values) = 0;
};
}  // namespace enumerator
#endif  // ENUMERATOR_REPORTER_HPP
