#ifndef ENUMERATOR_ENUMERATION_HPP
#define ENUMERATOR_ENUMERATION_HPP

#include <set>
#include <string>
#include <vector>

namespace enumerator::enumerations {
class Enumeration {
   public:
    virtual ~Enumeration() = default;

    /**
     * Return a list of values
     */
    virtual const std::set<std::string>& Values() const = 0;

    /**
     * Get the variable/name to replace
     * @return
     */
    virtual const std::string& Name() const = 0;
};

}  // namespace enumerator::enumerations
#endif  // ENUMERATOR_ENUMERATION_HPP
