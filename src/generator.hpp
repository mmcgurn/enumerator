#ifndef ENUMERATOR_GENERATOR_HPP
#define ENUMERATOR_GENERATOR_HPP

#include <map>
#include <string>

namespace enumerator {
class Generator {
   public:
    virtual ~Generator() = default;
    virtual void Generate(const std::string& caseName, const std::map<std::string, std::string>& values) = 0;
};
}  // namespace enumerator
#endif  // ENUMERATOR_GENERATOR_HPP
