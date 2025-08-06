/*
Додайте дві додаткові змінні-члени до класу з попередніх вправ. 
Додайте методи доступу, які повертають значення всіх цих змінних. 
Усі функції-члени повинні повертати значення однакового типу та мати однакову сигнатуру. 
Для доступу до цих методів використовуйте вказівник на функцію члена.
*/

#include <iostream>

class MyClass {
private:
    int value;
    int id;
    int code;
    static int count;

public:
    MyClass(int val, int ident, int c) : value(val), id(ident), code(c) {
        count++;
        std::cout << "Конструктор: об'єкт (value=" << value
                  << ", id=" << id << ", code=" << code << ") створено.\n";
    }

    ~MyClass() {
        std::cout << "Деструктор: об'єкт з id=" << id << " видаляється.\n";
        count--;
    }

    int getValue() const { return value; }
    int getId() const { return id; }
    int getCode() const { return code; }

    static int getCount() { return count; }
};

int MyClass::count = 0;

int main() {
    MyClass* obj = new MyClass(123, 42, 9001);

    // Вказівник на функцію-член
    int (MyClass::*getter)() const = nullptr;

    int choice;
    do {
        std::cout << "\nОберіть, що хочете вивести:\n";
        std::cout << "1 - value\n";
        std::cout << "2 - id\n";
        std::cout << "3 - code\n";
        std::cout << "0 - Вийти\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                getter = &MyClass::getValue;
                break;
            case 2:
                getter = &MyClass::getId;
                break;
            case 3:
                getter = &MyClass::getCode;
                break;
            case 0:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір!\n";
                continue;
        }

        if (choice >= 1 && choice <= 3) {
            std::cout << "Результат: " << (obj->*getter)() << std::endl;
        }

    } while (choice != 0);

    delete obj;
    std::cout << "Залишилось об'єктів: " << MyClass::getCount() << std::endl;

    return 0;
}

/*
Оберіть, що хочете вивести:
1 - value
2 - id
3 - code
0 - Вийти
Ваш вибір: 2
Результат: 42

Оберіть, що хочете вивести:
1 - value
2 - id
3 - code
0 - Вийти
Ваш вибір: 9
Невірний вибір!
*/