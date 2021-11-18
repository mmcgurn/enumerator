#include "enumerations/range.hpp"
#include "gtest/gtest.h"
namespace enumeratorTests {

struct RangeTestParameters {
    std::string name;
    double start;
    double end;
    int points;
    std::set<std::string> expectedValues;
};

class RangeTestFixture : public ::testing::TestWithParam<RangeTestParameters> {};

TEST_P(RangeTestFixture, ShouldComputeCorrectRange) {
    // arrange
    // act
    enumerator::enumerations::Range range(GetParam().name, GetParam().start, GetParam().end, GetParam().points);

    // assert
    ASSERT_EQ(GetParam().name, range.Name());
    ASSERT_EQ(GetParam().expectedValues, range.Values());
}

INSTANTIATE_TEST_SUITE_P(RangeTests, RangeTestFixture,
                         testing::Values((RangeTestParameters){.name = "var1", .start = 0.0, .end = 1.0, .points = 0, .expectedValues = {"0.000000", "1.000000"}},
                                         (RangeTestParameters){.name = "var2", .start = 0.0, .end = 1.0, .points = 3, .expectedValues = {"0.000000", "0.250000", "0.500000", "0.750000", "1.000000"}},
                                         (RangeTestParameters){
                                             .name = "var3", .start = -1, .end = 1.0, .points = 3, .expectedValues = {"-1.000000", "-0.500000", "0.000000", "0.500000", "1.000000"}}));

}  // namespace enumeratorTests