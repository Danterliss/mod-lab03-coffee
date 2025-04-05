// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public ::testing::Test {
 protected:
    Automata atm;

    void SetUp() override {
        atm.on();
    }

    bool testCheck(unsigned int choice) {
        return atm.check(choice);
    }

    void testCook() {
        atm.cook();
    }

    void testFinish() {
        atm.finish();
    }

    unsigned getCash() const {
        return atm.cash;
    }

    STATES getCurrentState() const {
        return atm.state;
    }
};

TEST_F(AutomataTest, InitialStateIsOff) {
    Automata newAtm;
    ASSERT_EQ(newAtm.getState(), STATES::OFF);
}

TEST_F(AutomataTest, TurnsOnCorrectly) {
    ASSERT_EQ(atm.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, TurnsOffCorrectly) {
    atm.off();
    ASSERT_EQ(atm.getState(), STATES::OFF);
}

TEST_F(AutomataTest, AcceptsCoins) {
    atm.coin(50);
    ASSERT_EQ(atm.getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, CancelReturnsMoney) {
    atm.coin(100);
    unsigned refund = atm.cancel();
    ASSERT_EQ(refund, 100);
    ASSERT_EQ(atm.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, SelectsDrinkWithEnoughMoney) {
    atm.coin(100);
    atm.choice(1);
    EXPECT_EQ(atm.getState(), STATES::WAIT);
    EXPECT_EQ(atm.cancel(), 70);
}

TEST_F(AutomataTest, RejectsDrinkWithNotEnoughMoney) {
    atm.coin(20);
    atm.choice(2);
    ASSERT_EQ(atm.getState(), STATES::ACCEPT);
}

TEST_F(AutomataTest, ReturnsToWaitAfterCooking) {
    atm.coin(100);
    atm.choice(1);
    EXPECT_EQ(atm.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, CantSelectWhenOff) {
    atm.off();
    EXPECT_THROW(atm.choice(1), std::runtime_error);
}

TEST_F(AutomataTest, CantInsertCoinWhenOff) {
    atm.off();
    EXPECT_THROW(atm.coin(50), std::runtime_error);
}

TEST_F(AutomataTest, CheckMoneyCorrectly) {
    atm.coin(40);
    EXPECT_FALSE(testCheck(2));
    atm.coin(10);
    EXPECT_TRUE(testCheck(1));
}
