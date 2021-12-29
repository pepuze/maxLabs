#include <windows.h>
#include <iostream>

struct Parallelogram {
    double a, b, angleDeg;
};

bool checkIfRectangle(Parallelogram par) {
    if (par.angleDeg == 90) return 1;
    return 0;
}

bool checkIfSquare(Parallelogram par) {
    if (checkIfRectangle(par) && par.a == par.b) return 1;
    return 0;
}

int main()
{
    int k, k1 = 0, k2 = 0;
    Parallelogram pars[1000];
    system("chcp 1251"); //Вывод кириллицы
    std::cout << "Введите количество параллелограммов:\n";
    std::cin >> k;
    std::cout << "Введите стороны параллелограммов и больший угол между их сторонами (в градусах):\n";
    for (int i = 0; i < k; ++i) std::cin >> pars[i].a >> pars[i].b >> pars[i].angleDeg;

    for (int i = 0; i < k; ++i) {
        if (checkIfRectangle(pars[i])) {
            ++k1;
            if (checkIfSquare(pars[i])) ++k2;
        }
    }

    std::cout << "Количество прямоугольников: " << k1 << "\nКоличество квадратов: " << k2 << "\n";
}