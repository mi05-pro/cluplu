#include <iostream>
#include <string>  // Підключаємо бібліотеку для роботи з класом string

class Animal {
private:
    //Клас Animal містить змінну-член name типу std::string, яка зберігає ім'я тварини
    std::string name;  // Змінна-член типу string для зберігання імені тварини

public:
    // Конструктор класу приймає ім'я як параметр і ініціалізує змінну-член
    
    // Конструктор класу, який ініціалізує ім'я тварини
    Animal(const std::string& animalName) : name(animalName) {}

    // Метод для отримання імені тварини
    std::string getName() const {
        return name;
    }

    // Метод для встановлення імені тварини
    void setName(const std::string& animalName) {
        name = animalName;
    }

    // Метод для виведення інформації про тварину
    void displayInfo() const {
        std::cout << "Animal's name: " << name << std::endl;
    }
};

int main() {
    // Створюємо об'єкт класу Animal і ініціалізуємо його ім'ям
    Animal dog("Robbie");

    // Виводимо інформацію про тварину
    dog.displayInfo();

    // Змінюємо ім'я тварини
    dog.setName("Rokki");

    // Виводимо нову інформацію
    dog.displayInfo();

    return 0;
}
