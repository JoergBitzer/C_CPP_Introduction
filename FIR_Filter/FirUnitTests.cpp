#include <gtest/gtest.h>
#include "FIR.h"
/*
class MonoFIRTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};


TEST(MonoFIRTest, DefaultConstructorTest) {
    MonoFIR fir;
    std::vector<float> data{1.0, 2.0, 3.0};
    fir.processSamples(data);
    EXPECT_EQ(data, std::vector<float>{1.0, 2.0, 3.0});
    //EXPECT_EQ(1.f,1.f);
}
*/
TEST(MonoFIRTest, ParameterizedConstructorTest) {
    std::vector<float> coeffs{0.5, 0.5};
    MonoFIR fir(coeffs);
    std::vector<float> data{1.0, 2.0, 3.0};
    fir.processSamples(data);
    EXPECT_FLOAT_EQ(data[0], 0.5);
    EXPECT_FLOAT_EQ(data[1], 1.5);
    EXPECT_FLOAT_EQ(data[2], 2.5);
}

TEST(MonoFIRTest, SetCoeffsTest) {
    MonoFIR fir;
    fir.setCoeffs(std::vector<float>{0.2, 0.8});
    std::vector<float> data{10.0, 20.0, 30.0};
    fir.processSamples(data);
    EXPECT_FLOAT_EQ(data[0], 2.0);
    EXPECT_FLOAT_EQ(data[1], 12.0);
    EXPECT_FLOAT_EQ(data[2], 22.0);
}

TEST(MonoFIRTest, ResetTest) {
    MonoFIR fir;
    fir.setCoeffs(std::vector<float>{0.3, 0.7});
    std::vector<float> data{5.0, 10.0, 15.0};
    fir.processSamples(data);
    fir.reset();
    fir.processSamples(data);
    EXPECT_FLOAT_EQ(data[0], 0.45);
    EXPECT_FLOAT_EQ(data[1], 3.0);
    EXPECT_FLOAT_EQ(data[2], 8.0);
}
