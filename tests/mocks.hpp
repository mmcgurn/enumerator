#ifndef ENUMERATOR_MOCKS_HPP
#define ENUMERATOR_MOCKS_HPP
#include "generator.hpp"
#include "gmock/gmock.h"
#include "reporter.hpp"

namespace enumeratorTests {

class MockGenerator : public enumerator::Generator {
   public:
    MOCK_METHOD(void, Generate, (const std::string& caseName, (const std::map<std::string, std::string>&)), (override));
};

class MockReporter : public enumerator::Reporter {
   public:
    MOCK_METHOD(void, Report, (const std::string& caseName, (const std::map<std::string, std::string>&)), (override));
};

}  // namespace enumeratorTests

#endif  // ENUMERATOR_MOCKS_HPP
