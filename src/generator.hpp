#ifndef ENUMERATOR_GENERATOR_HPP
#define ENUMERATOR_GENERATOR_HPP

#include <string>
#include <map>

namespace enumerator {
class Generator {
   public:
    virtual ~Generator() = default;
    virtual void Generate(const std::string& caseName, const std::map<std::string, std::string>& values) = 0;
};
}
#endif  // ENUMERATOR_GENERATOR_HPP
