#ifndef ENUMERATOR_ENUMERATOR_HPP
#define ENUMERATOR_ENUMERATOR_HPP

#include <memory>
#include <vector>
#include "enumerations/enumeration.hpp"
#include "generator.hpp"
#include "reporter.hpp"

namespace enumerator {

class Enumerator {
   private:
    const std::string name;
    const std::vector<std::shared_ptr<enumerations::Enumeration>> enumerations;
    const std::shared_ptr<Generator> generator;
    const std::vector<std::shared_ptr<Reporter>> reporters;

    // Recursive call to
    void Enumerate(const std::vector<std::shared_ptr<enumerations::Enumeration>>& remainingEnumerations, const std::map<std::string, std::string>& values, int& caseCount);

    std::string BuildCaseName(const int& caseCount);

   public:
    Enumerator(std::string name, std::vector<std::shared_ptr<enumerations::Enumeration>> enumerations,std::shared_ptr<Generator> generator, std::vector<std::shared_ptr<Reporter>> reporters);

    void Enumerate();


};
}

#endif  // ENUMERATOR_ENUMERATOR_HPP
