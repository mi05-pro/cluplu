#include <iostream>
#include <string>
using namespace std;

// Клас власного винятку
class MyException {
private:
    string message; // змінна-член для збереження тексту помилки

public:
    // Конструктор
    MyException(const string& msg) : message(msg) {}

    // Метод доступу
    string getMessage() const {
        return message;
    }
};

int main() {
    try {
        int a = 10;
        int b = 0;

        if (b == 0) {
            // Генеруємо власний виняток
            throw MyException("Спроба ділення на нуль!");
        }

        int result = a / b;
        cout << "Результат: " << result << endl;
    }
    catch (const MyException& e) {
        cout << "Виникла помилка: " << e.getMessage() << endl;
    }

    return 0;
}
