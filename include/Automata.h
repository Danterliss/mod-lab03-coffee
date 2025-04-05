#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>
#include <stdexcept>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
    friend class AutomataTest;
private:
    unsigned int cash;
    std::vector<std::string> menu;
    std::vector<unsigned int> prices;
    STATES state;

    bool check(unsigned int choice);
    void cook();
    void finish();

public:
    Automata();

    void on();
    void off();
    void coin(unsigned int amount);
    void getMenu() const;
    STATES getState() const;
    void choice(unsigned int drinkIdx);
    unsigned int cancel();
};

#endif