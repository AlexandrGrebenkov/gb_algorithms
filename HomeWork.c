//
// Created by alexa on 02.07.2019.
//

#include "HomeWork.h"

/// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
/// \param height – рост в метрах
/// \param mass – масса тела в килограммах
/// \return - индекс массы тела
double exec_1(double height, double mass)
{
    return mass/(height * height);
}