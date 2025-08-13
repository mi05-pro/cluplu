#include <iostream>
using namespace std;

bool isPrime(int n) { //2, 3, 5, 7, 11 .. 
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int number;
    cout << "Введіть ціле число: ";
    cin >> number;

    if (!cin) { 
        cerr << "Помилка: введено некоректні дані!\n";
        return 1;
    }

    clog << "[LOG] Користувач ввів число " << number << '\n';

    if (isPrime(number))
        cout << number << " — просте число.\n";
    else
        cout << number << " — не просте число.\n";

    return 0;
}
