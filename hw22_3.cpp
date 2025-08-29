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

// Похідний виняток (без override)
class DerivedException : public BaseException {
public:
    DerivedException(const string& msg) : BaseException(msg) {}
};

int main() {
    try {
        int a = 10;
        int b = 0;

        if (b == 0) {
            // Кидаємо похідний виняток
            throw DerivedException("Спроба ділення на нуль!");
        }

        int result = a / b;
        cout << "Результат: " << result << endl;
    }
    // Спочатку перехоплюємо похідний
    catch (const DerivedException& e) {
        cout << "Обробка похідного винятку: " << e.getMessage() << endl;
    }
    // Потім базовий
    catch (const BaseException& e) {
        cout << "Обробка базового винятку: " << e.getMessage() << endl;
    }

    return 0;
}
