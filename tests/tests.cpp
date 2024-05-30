#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>
#include <prototype.h>

class PrototypeMock: public ConcretePrototype {
public:
    ~PrototypeMock() override = default;
    MOCK_METHOD0(Clone, Prototype*());
};

TEST(Prototype_tests, test1) {
    PrototypeMock p_mock;
    EXPECT_CALL(p_mock, Clone()).Times(1);
    Prototype* p1 = p_mock.Clone();
}

TEST(Prototype_tests, test2) {
    PrototypeMock p_mock;
    EXPECT_CALL(p_mock, Clone()).Times(1);
    Prototype* p1 = p_mock.Clone();
    PrototypeMock p1_mock;
    EXPECT_CALL(p1_mock, Clone()).Times(1);
    Prototype* p2 = p1_mock.Clone();
}

TEST(Prototype_tests, test3) {
    std::ostringstream oss;
    std::streambuf* cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    Prototype* p = new ConcretePrototype();
    Prototype* p1 = p->Clone();

    std::cout.rdbuf(cout_streambuf);
    EXPECT_EQ(oss.str(), "ConcretePrototype copy ...\n");
}
