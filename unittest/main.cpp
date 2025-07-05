#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QCoreApplication>

int main(int argc, char **argv) {
    // Normal usage with public constructor
    QCoreApplication app(argc, argv);
    std::cout << "welcome elsayed i'm the unit test code "<< std::endl;
    testing::InitGoogleTest(&argc ,argv);
    return RUN_ALL_TESTS();
}