#ifndef ENUMERATOR_RANGE_HPP
#define ENUMERATOR_RANGE_HPP

#include "enumeration.hpp"

namespace enumerator::enumerations {

class Range : public Enumeration {
    // the set of values
    const std::string name;
    std::set<std::string> values;

   public:
    Range(std::string name, double start, double end, int points);

    const std::set<std::string>& Values() const override { return values; }

    const std::string& Name() const override { return name; }
};
}  // namespace enumerator::enumerations
#endif  // ENUMERATOR_RANGE_HPP
