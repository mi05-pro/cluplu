#include <iostream>
using namespace std;

class MyClass {
private:
    int regularVar; // Звичайна змінна-член
    static int staticVar; // Статична змінна-член

public:
    // Конструктор, який ініціалізує regularVar та збільшує staticVar
    MyClass(int value) {
        regularVar = value; // Ініціалізація звичайної змінної
        staticVar++; // Збільшення статичної змінної
        cout << "Конструктор: regularVar = " << regularVar << ", staticVar = " << staticVar << endl;
    }

    // Деструктор, який зменшує значення staticVar
    ~MyClass() {
        staticVar--; // Зменшення статичної змінної
        cout << "Деструктор: regularVar = " << regularVar << ", staticVar = " << staticVar << endl;
    }

    // Статичний метод для виведення значення статичної змінної
    static void showStaticVar() {
        cout << "staticVar = " << staticVar << endl;
    }
};

// Ініціалізація статичної змінної
int MyClass::staticVar = 0;

int main() {
    cout << "До створення об'єктів:" << endl;
    MyClass::showStaticVar(); // Виведення значення статичної змінної

    // Створення об'єктів
    MyClass obj1(5);
    MyClass obj2(10);

    cout << "Після створення об'єктів:" << endl;
    MyClass::showStaticVar(); // Виведення значення статичної змінної

    // Об'єкти будуть знищені автоматично при виході з функції main, і викличеться деструктор
    return 0;

    /* 

    Результат:
    
До створення об'єктів:
staticVar = 0
Конструктор: regularVar = 5, staticVar = 1
Конструктор: regularVar = 10, staticVar = 2
Після створення об'єктів:
staticVar = 2
Деструктор: regularVar = 10, staticVar = 1
Деструктор: regularVar = 5, staticVar = 0
    
    
    */
}
