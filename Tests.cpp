//
// Created by alexa on 02.07.2019.
//

#include "Tests.h"
#include "gtest/gtest.h"
#include "HomeWork.h"

namespace
{
    TEST(HomeWorkTests, ex_1_Positive)
    {
        double index = exec_1(180, 60);
        EXPECT_NEAR(18.51, index, 0.01);
    }
}




