// Copyright 2022 UNN-IASR
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Automata.h"

Automata::Automata() : cash(0), state(STATES::OFF) {
    menu = { "Tea", "Americano", "Capuchino", "Hot chocolate" };
    prices = { 30, 50, 70, 60 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        std::cout << "Automata on. Waiting for action.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Automata off.\n";
    }
}

void Automata::coin(unsigned int amount) {
    if (state == STATES::OFF) {
        throw std::runtime_error("Automata off");
    }
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "deposit: " << amount << " coins. current balance: "
            << cash << " coins.\n";
    }
}

void Automata::getMenu() const {
    if (state != STATES::OFF) {
        std::cout << "\n======== MENU ========\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i]
                << " couns.\n";
        }
        std::cout << "======================\n";
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(unsigned int drinkIdx) {
    std::cout << "Current state: " << static_cast<int>(state) << std::endl;
    if (state != STATES::ACCEPT) {
        throw std::runtime_error("You can't choose a drink.");
        return;
    }

    if (drinkIdx > 0 && drinkIdx <= menu.size()) {
        state = STATES::CHECK;
        if (check(drinkIdx - 1)) {
            cash -= prices[drinkIdx - 1];
            cook();
            finish();
        } else {
            state = STATES::ACCEPT;
        }
    }
}

unsigned int Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::WAIT) {
        unsigned int refund = cash;
        cash = 0;
        state = STATES::WAIT;
        std::cout << "The operation was canceled. Returned: "
            << refund << " coins.\n";
        return refund;
    }
    return 0;
}

bool Automata::check(unsigned int choice) {
    if (choice >= prices.size()) {
        throw std::out_of_range("Wrong choice of drink");
    }
    return cash >= prices[choice];
}

void Automata::cook() {
    state = STATES::COOK;
    std::cout << "Preparation of the drink...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\n";
}

void Automata::finish() {
    std::cout << "The drink is ready! Pick up your order.\n";
    state = STATES::WAIT;
}
