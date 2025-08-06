/*
Створіть у програмі з вправи 3 вказівник на функцію-член 
для доступу до значення нестатичної змінної-члена 
і скористайтеся ним для виведення цих значень на друк.
*/

#include <iostream>

class MyClass {
private:
    int value;
    static int count;

public:
    MyClass(int val) : value(val) {
        count++;
        std::cout << "Конструктор: створено об'єкт зі значенням " << value << std::endl;
    }

    ~MyClass() {
        std::cout << "Деструктор: видаляється об'єкт зі значенням " << value << std::endl;
        count--;
    }

    int getValue() const {
        return value;
    }

    static int getCount() {
        return count;
    }
};

// Ініціалізація статичної змінної
int MyClass::count = 0;

int main() {
    // Створення трьох об'єктів динамічно
    MyClass* obj1 = new MyClass(10);
    MyClass* obj2 = new MyClass(20);
    MyClass* obj3 = new MyClass(30);

    // === Вказівник на функцію-член ===
    int (MyClass::*funcPtr)() const = &MyClass::getValue;

    // Використання вказівника для виведення значень:
    std::cout << "Значення об'єкта obj1: " << (obj1->*funcPtr)() << std::endl;
    std::cout << "Значення об'єкта obj2: " << (obj2->*funcPtr)() << std::endl;
    std::cout << "Значення об'єкта obj3: " << (obj3->*funcPtr)() << std::endl;

    std::cout << "Кількість об'єктів: " << MyClass::getCount() << std::endl;

    // Видалення об'єктів
    delete obj1;
    std::cout << "Кількість після видалення obj1: " << MyClass::getCount() << std::endl;

    delete obj2;
    std::cout << "Кількість після видалення obj2: " << MyClass::getCount() << std::endl;

    delete obj3;
    std::cout << "Кількість після видалення obj3: " << MyClass::getCount() << std::endl;

    return 0;
}












/*
У C++ вказівник на функцію-член класу оголошується так:
ReturnType (ClassName::*pointerName)(ParameterTypes);

якщо маємо метод:
int getValue() const;

вказівник виглядатиме так:
int (MyClass::*funcPtr)() const = &MyClass::getValue;

А виклик через об'єкт-вказівник:

(obj1->*funcPtr)();

*/