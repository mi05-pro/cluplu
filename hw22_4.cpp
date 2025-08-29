#include <iostream>
#include <string>
using namespace std;

// Базовий виняток
class BaseException {
protected:
    string message;

public:
    BaseException(const string& msg) : message(msg) {}

    string getMessage() const {
        return "BaseException: " + message;
    }
};

// Похідний виняток
class DerivedException : public BaseException {
public:
    DerivedException(const string& msg) : BaseException(msg) {}
};

// Третій рівень
void level3() {
    int a = 10;
    int b = 0;

    if (b == 0) {
        throw DerivedException("Спроба ділення на нуль у level3()");
    }

    cout << "Результат: " << a / b << endl;
}

// Другий рівень
void level2() {
    cout << "Виклик level2()" << endl;
    level3();
}

// Перший рівень
void level1() {
    cout << "Виклик level1()" << endl;
    level2();
}

int main() {
    try {
        cout << "Початок програми" << endl;
        level1();
        cout << "Кінець програми" << endl;
    }
    catch (const DerivedException& e) {
        cout << "Обробка похідного винятку: " << e.getMessage() << endl;
    }
    catch (const BaseException& e) {
        cout << "Обробка базового винятку: " << e.getMessage() << endl;
    }

    return 0;
}
