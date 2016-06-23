/* Copyright [2014] <Jean Martina>
 * TestePilha.cpp
 */

#include <stdio.h>
#include "gtest/gtest.h"




int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    int a = RUN_ALL_TESTS();
    return a;
}

class Objeto{
};
