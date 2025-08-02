#include <iostream>
using namespace std;

// Абстрактний клас Vehicle
class Vehicle {
public:
    // Чисто віртуальні функції
    virtual void start() {} // запуск транспортного засобу
    virtual void stop() = 0;  // зупинка транспортного засобу
    
    // Деструктор
    virtual ~Vehicle() {}
};

// Абстрактний клас Car (Легковий автомобіль), який наслідує від Vehicle
class Car : public Vehicle {
public:
    // Замістимо одну з віртуальних функцій базового класу
    void start() {
        Vehicle::start(); // Це можна використовувати, якщо базовий клас має реальну реалізацію
        cout << "Легковий автомобіль стартував." << endl;
    }
    
    // Чисто віртуальна функція в класі Car
    virtual void stop() = 0;
    
    virtual ~Car() {}
};

// Клас SportCar (Спортивний автомобіль), який наслідує від Car
class SportCar : public Car {
public:
    // Реалізація чисто віртуальної функції stop
    void stop() {
        cout << "Спортивний автомобіль зупинився." << endl;
    }

    // Додатковий метод для спортивного автомобіля
    void turboBoost() {
        cout << "Спортивний автомобіль активує турбо!" << endl;
    }
};

// Клас Wagon (Фургон), який наслідує від Car
class Wagon : public Car {
public:
    // Реалізація чисто віртуальної функції stop
    void stop() {
        cout << "Фургон зупинився." << endl;
    }

    // Додатковий метод для фургона
    void loadCargo() {
        cout << "Фургон завантажує тварин." << endl;
    }
};

// Клас Coupe (Двомісний автомобіль-купе), який наслідує від Car
class Coupe : public Car {
public:
    // Реалізація чисто віртуальної функції stop
    void stop() {
        cout << "Двомісний автомобіль-купе зупинився." << endl;
    }

    // Додатковий метод для купе
    void openRoof() {
        cout << "Автомобіль-купе піднімає дах." << endl;
    }
};

int main() {
    // Створення об'єктів класів SportCar, Wagon та Coupe
    Vehicle* sportCar = new SportCar();
    Vehicle* wagon = new Wagon();
    Vehicle* coupe = new Coupe();
    
    // Виклик методів через вказівники на абстрактний тип
    sportCar->start();
    sportCar->stop();
    
    wagon->start();
    wagon->stop();
    
    coupe->start();
    coupe->stop();
    
    // Очищення пам'яті
    delete sportCar;
    delete wagon;
    delete coupe;

    return 0;

    
}
