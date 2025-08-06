#include <iostream>

class MyClass {
private:
    int value;                      // Звичайна змінна-член
    static int count;              // Статична змінна-член

public:
    // Конструктор
    MyClass(int val) : value(val) {
        count++;                   // Збільшення статичної змінної
        std::cout << "Конструктор. Поточна кількість об'єктів: " << count << std::endl;
    }

    // Деструктор
    ~MyClass() {
        count--;                   // Зменшення статичної змінної
        std::cout << "Деструктор. Поточна кількість об'єктів: " << count << std::endl;
    }

    // Статична функція для перегляду count
    static int getCount() {
        return count;
    }

    // Метод для демонстрації значення value
    void showValue() {
        std::cout << "Значення value: " << value << std::endl;
    }
};

// Ініціалізація статичної змінної
int MyClass::count = 0;

int main() {
    {
        MyClass obj1(10);
        obj1.showValue();

        MyClass obj2(20);
        obj2.showValue();

        std::cout << "Кількість об'єктів (через getCount): " << MyClass::getCount() << std::endl;
    } // Тут obj1 і obj2 виходять з області видимості і викликаються деструктори

    std::cout << "Після виходу з блоку main(): " << MyClass::getCount() << std::endl;

    return 0;
}
