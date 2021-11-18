#ifndef ENUMERATOR_STREAMREPORTER_HPP
#define ENUMERATOR_STREAMREPORTER_HPP

#include "reporter.hpp"
#include <iostream>
namespace enumerator::reporters {

class StreamReporter: public Reporter {
   private:
    std::ostream& outputStream;

   public:
    explicit StreamReporter(std::ostream& outputStream = std::cout);
    void Report(const std::string& caseName, const std::map<std::string, std::string>& values) override;

};

}
#endif  // ENUMERATOR_STREAMREPORTER_HPP
