#include "list.hpp"
const std::set<std::string>& enumerator::enumerations::List::Values() const { return values; }
const std::string& enumerator::enumerations::List::Name() const { return name; }

#include "registrar.hpp"
REGISTERDEFAULT(enumerator::enumerations::Enumeration, enumerator::enumerations::List, "Simple list of arguments", ARG(std::string, "name", "the template variable name"),
                ARG(std::vector<std::string>, "values", "the list of values"));