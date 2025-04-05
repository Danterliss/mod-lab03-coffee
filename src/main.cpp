#include <iostream>
#include <locale>
#include "Automata.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== ������������ ������ �������� ===\n\n";

    Automata automata;

    std::cout << "1. �������� �������\n";
    automata.on();
    std::cout << "���������: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "2. ���������� ����:\n";
    automata.getMenu();
    std::cout << "\n";

    std::cout << "3. ������ 100 ������\n";
    automata.coin(100);
    std::cout << "���������: " << static_cast<int>(automata.getState()) << " (ACCEPT)\n\n";

    std::cout << "4. �������� ��� (������� 1)\n";
    automata.choice(1);
    std::cout << "���������: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "5. �������� �������� (������� 3)\n";
    automata.choice(3);
    std::cout << "���������: " << static_cast<int>(automata.getState()) << " (WAIT)\n\n";

    std::cout << "6. �������� ������� ���� ��� �����\n";
    automata.choice(2);
    std::cout << "\n";

    std::cout << "7. ��������� �������\n";
    automata.off();
    std::cout << "���������: " << static_cast<int>(automata.getState()) << " (OFF)\n";

    std::cout << "\n=== ������������ ��������� ===\n";
    return 0;
}