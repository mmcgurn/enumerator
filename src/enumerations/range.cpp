#include "range.hpp"
enumerator::enumerations::Range::Range(std::string name, double start, double end, int points) : name(name) {
    // add a point for the number of segments
    auto segments = points + 1;
    // Compute the delta
    const double delta = (end - start) / segments;

    // Add the start and end
    values.insert(std::to_string(start));
    values.insert(std::to_string(end));

    for (auto p = 1; p <= points; p++) {
        auto value = p * delta + start;
        values.insert(std::to_string(value));
    }
}

#include "registrar.hpp"
REGISTER(enumerator::enumerations::Enumeration, enumerator::enumerations::Range, "Computes a range based upon start/end and number of new points",
         ARG(std::string, "name", "the template variable name"), ARG(double, "start", "the inclusive start of the range"), ARG(double, "end", "the inclusive end of the range"),
         ARG(int, "points", "the number of points (not counting the ends) in the range"));
