#include <stdio.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Lesson1.h"
#include <locale.h>

// Автор: Александр Гребеньков
// Проект на C++ из-за использования google test, но само задание выполнено на чистом Си

int main()
{
	char* locale = setlocale(LC_ALL, ""); // для использования кириллицы

    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}