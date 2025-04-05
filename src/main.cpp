// Copyright 2022 UNN-IASR
#include <iostream>
#include <locale>
#include "Automata.h"

int main() {

    std::cout << "=== Demonstration of the machine's operation ===\n\n";

    Automata automata;

    std::cout << "1. On Automata\n";
    automata.on();
    std::cout << "State: " << static_cast<int>(automata.getState())
        << " (WAIT)\n\n";

    std::cout << "2. Menu:\n";
    automata.getMenu();
    std::cout << "\n";

    std::cout << "3. Deposit 100 coins\n";
    automata.coin(100);
    std::cout << "State: " << static_cast<int>(automata.getState())
        << " (ACCEPT)\n\n";

    std::cout << "4. Choice tea\n";
    automata.choice(1);
    std::cout << "State: " << static_cast<int>(automata.getState())
        << " (WAIT)\n\n";

    std::cout << "5. Choice Capuchino\n";
    automata.choice(3);
    std::cout << "State: " << static_cast<int>(automata.getState())
        << " (WAIT)\n\n";

    std::cout << "6. Choice Americano without money\n";
    automata.choice(2);
    std::cout << "\n";

    std::cout << "7. Off automata\n";
    automata.off();
    std::cout << "State: " << static_cast<int>(automata.getState())
        << " (OFF)\n";

    std::cout << "\n=== demonstration finish ===\n";
    return 0;
}
