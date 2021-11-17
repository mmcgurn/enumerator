#ifndef ENUMERATOR_LIST_HPP
#define ENUMERATOR_LIST_HPP

#include <sstream>
#include "enumeration.hpp"

namespace enumerator::enumerations {

class List : public Enumeration {
   private:
    // the set of values
    const std::string name;
    std::set<std::string> values;

    template <typename T>
    inline static std::string toString(T value) noexcept {
        std::stringstream stream;
        stream << value;
        return stream.str();
    }

   public:
    List(std::string name, std::vector<std::string> vector) : name(name) {
        for (const auto& v : vector) {
            values.insert(v);
        }
    }

    template <typename... Arg>
    List(std::string name, Arg&&... args) : name(name) {
        values = {{toString(args)}...};
    }

    const std::set<std::string>& Values() const override;

    const std::string& Name() const override;
};

}  // namespace enumerator::enumerations
#endif  // ENUMERATOR_LIST_HPP
