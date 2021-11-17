#include <enumerator.hpp>
#include <functional>
#include <memory>
#include "enumeration.hpp"
#include "gtest/gtest.h"
#include "list.hpp"
#include "mocks.hpp"

using namespace enumerator;
using List = enumerator::enumerations::List;

namespace ablateTesting {

struct EnumeratorTestParameters {
    std::string name;
    std::vector<std::shared_ptr<enumerations::Enumeration>> enumerations;
    std::function<std::shared_ptr<Generator>()> setupMockGenerator;
    std::function<std::vector<std::shared_ptr<Reporter>>()> setupMockReporters;
};

class EnumeratorTestFixture : public ::testing::TestWithParam<EnumeratorTestParameters> {};

TEST_P(EnumeratorTestFixture, ShouldEnumerate) {
    // arrange
    auto mockGenerator = GetParam().setupMockGenerator();
    auto mockReporters = GetParam().setupMockReporters();

    enumerator::Enumerator enumerator(GetParam().name, GetParam().enumerations, mockGenerator, mockReporters);

    // act/assert
    enumerator.Enumerate();
}

INSTANTIATE_TEST_SUITE_P(SutherlandTests, EnumeratorTestFixture,
                         testing::Values((EnumeratorTestParameters){.name = "t1_",
                                                                    .enumerations = {std::make_shared<List>("a", 1, 2, 3)},
                                                                    .setupMockGenerator =
                                                                        []() {
                                                                            auto mockGenerator = std::make_shared<enumeratorTests::MockGenerator>();

                                                                            EXPECT_CALL(*mockGenerator, Generate("t1_0", std::map<std::string, std::string>{{"a", "1"}})).Times(::testing::Exactly(1));
                                                                            EXPECT_CALL(*mockGenerator, Generate("t1_1", std::map<std::string, std::string>{{"a", "2"}})).Times(::testing::Exactly(1));
                                                                            EXPECT_CALL(*mockGenerator, Generate("t1_2", std::map<std::string, std::string>{{"a", "3"}})).Times(::testing::Exactly(1));

                                                                            return mockGenerator;
                                                                        },
                                                                    .setupMockReporters =
                                                                        []() {
                                                                            auto mockReporter = std::make_shared<enumeratorTests::MockReporter>();

                                                                            EXPECT_CALL(*mockReporter, Report("t1_0", std::map<std::string, std::string>{{"a", "1"}})).Times(::testing::Exactly(1));
                                                                            EXPECT_CALL(*mockReporter, Report("t1_1", std::map<std::string, std::string>{{"a", "2"}})).Times(::testing::Exactly(1));
                                                                            EXPECT_CALL(*mockReporter, Report("t1_2", std::map<std::string, std::string>{{"a", "3"}})).Times(::testing::Exactly(1));

                                                                            return std::vector<std::shared_ptr<Reporter>>{mockReporter};
                                                                        }},
                                         (EnumeratorTestParameters){
                                             .name = "t2.",
                                             .enumerations = {std::make_shared<List>("a", 1, 2, 3), std::make_shared<List>("b", "aa", "bb", "cc")},
                                             .setupMockGenerator =
                                                 []() {
                                                     auto mockGenerator = std::make_shared<enumeratorTests::MockGenerator>();

                                                     EXPECT_CALL(*mockGenerator, Generate("t2.0", std::map<std::string, std::string>{{"a", "1"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.1", std::map<std::string, std::string>{{"a", "1"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.2", std::map<std::string, std::string>{{"a", "1"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     EXPECT_CALL(*mockGenerator, Generate("t2.3", std::map<std::string, std::string>{{"a", "2"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.4", std::map<std::string, std::string>{{"a", "2"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.5", std::map<std::string, std::string>{{"a", "2"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     EXPECT_CALL(*mockGenerator, Generate("t2.6", std::map<std::string, std::string>{{"a", "3"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.7", std::map<std::string, std::string>{{"a", "3"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockGenerator, Generate("t2.8", std::map<std::string, std::string>{{"a", "3"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     return mockGenerator;
                                                 },
                                             .setupMockReporters =
                                                 []() {
                                                     auto mockReporter1 = std::make_shared<enumeratorTests::MockReporter>();
                                                     auto mockReporter2 = std::make_shared<enumeratorTests::MockReporter>();

                                                     EXPECT_CALL(*mockReporter1, Report("t2.0", std::map<std::string, std::string>{{"a", "1"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.0", std::map<std::string, std::string>{{"a", "1"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.1", std::map<std::string, std::string>{{"a", "1"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.1", std::map<std::string, std::string>{{"a", "1"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.2", std::map<std::string, std::string>{{"a", "1"}, {"b", "cc"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.2", std::map<std::string, std::string>{{"a", "1"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     EXPECT_CALL(*mockReporter1, Report("t2.3", std::map<std::string, std::string>{{"a", "2"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.3", std::map<std::string, std::string>{{"a", "2"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.4", std::map<std::string, std::string>{{"a", "2"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.4", std::map<std::string, std::string>{{"a", "2"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.5", std::map<std::string, std::string>{{"a", "2"}, {"b", "cc"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.5", std::map<std::string, std::string>{{"a", "2"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     EXPECT_CALL(*mockReporter1, Report("t2.6", std::map<std::string, std::string>{{"a", "3"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.6", std::map<std::string, std::string>{{"a", "3"}, {"b", "aa"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.7", std::map<std::string, std::string>{{"a", "3"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.7", std::map<std::string, std::string>{{"a", "3"}, {"b", "bb"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter1, Report("t2.8", std::map<std::string, std::string>{{"a", "3"}, {"b", "cc"}})).Times(::testing::Exactly(1));
                                                     EXPECT_CALL(*mockReporter2, Report("t2.8", std::map<std::string, std::string>{{"a", "3"}, {"b", "cc"}})).Times(::testing::Exactly(1));

                                                     return std::vector<std::shared_ptr<Reporter>>{mockReporter1, mockReporter2};
                                                 }}));
}  // namespace ablateTesting