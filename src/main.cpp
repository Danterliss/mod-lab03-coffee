#include <iostream>
#include <locale>
#include "Automata.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== Демонстрация работы автомата ===\n\n";

    Automata automata;

    std::cout << "1. Включаем автомат\n";
    automata.on();
    std::cout << "Состояние: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "2. Показываем меню:\n";
    automata.getMenu();
    std::cout << "\n";

    std::cout << "3. Вносим 100 рублей\n";
    automata.coin(100);
    std::cout << "Состояние: " << static_cast<int>(automata.getState()) << " (ACCEPT)\n\n";

    std::cout << "4. Выбираем чай (позиция 1)\n";
    automata.choice(1);
    std::cout << "Состояние: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "5. Выбираем капучино (позиция 3)\n";
    automata.choice(3);
    std::cout << "Состояние: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "6. Пытаемся выбрать кофе без денег\n";
    automata.choice(2);
    std::cout << "\n";

    std::cout << "7. Выключаем автомат\n";
    automata.off();
    std::cout << "Состояние: " << static_cast<int>(automata.getState()) << " (OFF)\n";

    std::cout << "\n=== Демонстрация завершена ===\n";
    return 0;
}