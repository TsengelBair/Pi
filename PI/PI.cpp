#include <iostream>
#include <cmath>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::pow;

long double monte_carlo(long long int n) {
    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // Создаем распределение для генерации случайных чисел без явного указания границ (т.е. от 0 до 1)
    std::uniform_real_distribution<double> dist;

    long long int res{ 0 };

    for (int i = 0; i < n; i++) {
        double x = dist(gen);
        double y = dist(gen);

        if (pow(x, 2) + pow(y, 2) < 1) {
            res++;
        }
    }

    return 4.0 * (static_cast<long double>(res) / n);
}

long double leibniz(long long int n) {
    long double pi{ 0.0 };
    for (int i = 0; i < n; i++) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }

    return 4.0 * pi;
}

long double bailey(long long int n) {
    long double sum{ 0.0 };
    for (int k = 0; k < n; k++) {
        sum += 1.0 / pow(16, k) * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6));
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Введите количество итераций" << endl;
    long long int n;
    cin >> n;

    cout << "Выберите метод, 1 - Монте-Карло, 2 - Лейбниц, 3 - Баили" << endl;
    int input;
    cin >> input;

    long double res;

    switch (input) {
    case 1:
        res = monte_carlo(n);
        cout << res;
        break;
    case 2:
        res = leibniz(n);
        cout << res;
        break;
    case 3:
        res = bailey(n);
        cout << res;
        break;
    default:
        cout << "Некорректный ввод";
    }
}