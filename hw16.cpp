#include <iostream>
using namespace std;

// Абстрактний клас Vehicle
class Vehicle {
public:
    // Чисто віртуальні функції
    virtual void start() = 0; // запуск транспортного засобу
    virtual void stop() = 0;  // зупинка транспортного засобу
    
    // Деструктор
    virtual ~Vehicle() {}
};

// Клас Car (Легковий автомобіль), який наслідує від Vehicle
class Car : public Vehicle {
public:
    // Реалізація чисто віртуальних функцій
    void start() {
        cout << "Легковий автомобіль стартував." << endl;
    }
    
    void stop() {
        cout << "Легковий автомобіль зупинився." << endl;
    }
};

// Клас Bus (Автобус), який наслідує від Vehicle
class Bus : public Vehicle {
public:
    // Реалізація чисто віртуальних функцій
    void start() {
        cout << "Автобус стартував." << endl;
    }
    
    void stop() {
        cout << "Автобус зупинився." << endl;
    }
};

int main() {
    // Створення об'єктів класів Car і Bus
    /* Вказівники на тип Vehicle використовуються для виклику методів start() і stop(), 
    що дозволяє реалізувати поліморфізм. */
    Vehicle* car = new Car(); // 
    Vehicle* bus = new Bus();
    
    // Виклик методів через вказівники на абстрактний тип
    car->start();
    car->stop();
    
    bus->start();
    bus->stop();
    
    // Очищення пам'яті
     /*Пам'ять для об'єктів класів Car та Bus виділяється за допомогою оператора new, 
     тому потрібно викликати delete, щоб уникнути витоків пам'яті.*/
    delete car;
    delete bus;

    return 0;
}
