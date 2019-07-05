#include "Tests.h"
#include "gtest/gtest.h"
#include "HomeWork.h"

namespace
{
    TEST(HomeWorkTests, ex_1_Positive)
    {
        double index = exec_1(1.80, 60);
        EXPECT_NEAR(18.51, index, 0.01);
    }
}




