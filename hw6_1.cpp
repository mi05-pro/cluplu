#include <iostream>
using namespace std;

// 1. 

// Рекурсивна функція піднесення до степеня
int power(int base, int e) {
    if (e == 0)
        return 1; // будь-яке число у нульовому степені дорівнює 1
    else
        return base * power(base, e - 1);
}

int main() {
    int base, e;

    cout << "Введіть число (основу): ";
    cin >> base;

    cout << "Введіть показник ступеня: ";
    cin >> e;

    if (e < 0) {
        cout << "Програма не підтримує від’ємні показники ступеня." << endl;
    } else {
        int result = power(base, e);
        cout << base << " у ступені " << e << " = " << result << endl;
    }

    return 0;
}
