#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Automata.h"

Automata::Automata() : cash(0), state(STATES::OFF) {
    menu = { "Чай", "Американо", "Капучино", "Горячий шоколад" };
    prices = { 30, 50, 70, 60 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        std::cout << "Автомат включен. Ожидание действий.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Автомат выключен.\n";
    }
}

void Automata::coin(unsigned int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "Внесено: " << amount << " руб. Текущий баланс: " << cash << " руб.\n";
    }
}

void Automata::getMenu() const {
    if (state != STATES::OFF) {
        std::cout << "\n======== МЕНЮ ========\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб.\n";
        }
        std::cout << "======================\n";
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(unsigned int drinkIdx) {
    if (state == STATES::ACCEPT) {
        if (drinkIdx > 0 && drinkIdx <= menu.size()) {
            state = STATES::CHECK;
            if (check(drinkIdx - 1)) {
                cook();
            }
            else {
                state = STATES::WAIT;
            }
        }
    }
}

unsigned int Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::WAIT) {
        unsigned int refund = cash;
        cash = 0;
        state = STATES::WAIT;
        std::cout << "Операция отменена. Возвращено: " << refund << " руб.\n";
        return refund;
    }
    return 0;
}

bool Automata::check(unsigned int choice) {
    if (choice < prices.size()) {
        return cash >= prices[choice];
    }
    return false;
}

void Automata::cook() {
    state = STATES::COOK;
    std::cout << "Приготовление напитка...\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\n";
}

void Automata::finish() {
    std::cout << "Напиток готов! Заберите ваш заказ.\n";
    cash = 0;
    state = STATES::WAIT;
}