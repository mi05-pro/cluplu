#include <iostream>
#include <string>
using namespace std;

// Базовий клас Rocket
class Rocket {
public:
    Rocket(double fuel = 0) : fuelCapacity(fuel) {}

    // Віртуальний метод для запуску ракети
    virtual void launch() {
        cout << "Rocket is launching with fuel capacity: " << fuelCapacity << " liters.\n";
    }

    virtual ~Rocket() {}  // Віртуальний деструктор

protected:
    double fuelCapacity;
};

// Базовий клас Airplane
class Airplane {
public:
    Airplane(int wings = 2) : numberOfWings(wings) {}

    // Віртуальний метод для польоту літака
    virtual void fly() {
        cout << "Airplane is flying with " << numberOfWings << " wings.\n";
    }

    virtual ~Airplane() {}  // Віртуальний деструктор

protected:
    int numberOfWings;
};

// Клас JetPlane — успадковує від Rocket і Airplane
class JetPlane : public Rocket, public Airplane {
public:
    JetPlane(double fuel, int wings, double speed)
        : Rocket(fuel), Airplane(wings), maxSpeed(speed) {}

    // Віртуальний метод для відображення інформації
    virtual void showInfo() {
        cout << "JetPlane Info:\n";
        cout << " - Max Speed: " << maxSpeed << " km/h\n";
        cout << " - Fuel Capacity: " << fuelCapacity << " liters\n";
        cout << " - Number of Wings: " << numberOfWings << endl;
    }

    // Віртуальний метод для запуску літака
    virtual void launch() {
        cout << "JetPlane launching with " << fuelCapacity << " liters of fuel!\n";
    }

    // Віртуальний метод для польоту літака
    virtual void fly() {
        cout << "JetPlane flying at " << maxSpeed << " km/h!\n";
    }

    virtual ~JetPlane() {}  // Віртуальний деструктор

protected:
    double maxSpeed;
};

// Клас Boeing747 — успадковує від JetPlane
class Boeing747 : public JetPlane {
public:
    Boeing747(double fuel, int wings, double speed, int passengers)
        : JetPlane(fuel, wings, speed), passengerCapacity(passengers) {}

    // Метод для відображення інформації про Boeing747
    void showInfo() {
        JetPlane::showInfo(); // Викликаємо метод з JetPlane
        cout << " - Passenger Capacity: " << passengerCapacity << " people\n";
    }

    // Метод для запуску Boeing747
    void launch() {
        cout << "Boeing747 is launching with " << fuelCapacity << " liters of fuel!\n";
    }

    // Метод для польоту Boeing747
    void fly() {
        cout << "Boeing747 is flying at " << maxSpeed << " km/h with " << passengerCapacity << " passengers.\n";
    }

    virtual ~Boeing747() {}  // Віртуальний деструктор

private:
    int passengerCapacity;
};

int main() {
    // Створюємо об'єкт класу Boeing747
    Boeing747 *plane = new Boeing747(50000, 2, 920, 416);

    // Викликаємо поліморфічні методи
    plane->fly();        // Виведе метод з Boeing747
    plane->launch();     // Виведе метод з Boeing747
    plane->showInfo();   // Виведе метод з Boeing747

    // Очищаємо пам'ять
    delete plane;

    return 0;
}
