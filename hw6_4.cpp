#include <iostream>
using namespace std;

class Employee {
private:
    int age;
    int workingYears;
    double salary;

public:
    // Сеттери
    void setAge(int a) {
        if (a >= 0)
            age = a;
        else
            cout << "Некоректний вік!" << endl;
    }

    void setWorkingYears(int y) {
        if (y >= 0)
            workingYears = y;
        else
            cout << "Некоректний стаж!" << endl;
    }

    void setSalary(double s) {
        if (s >= 0)
            salary = s;
        else
            cout << "Некоректна зарплата!" << endl;
    }

    // Геттери
    int getAge() {
        return age;
    }

    int getWorkingYears() {
        return workingYears;
    }

    double getSalary() {
        return salary;
    }

    // Метод для виводу
    void displayData() {
        cout << "Вік: " << getAge() << " років" << endl;
        cout << "Стаж роботи: " << getWorkingYears() << " років" << endl;
        cout << "Зарплата: " << getSalary() << " грн" << endl;
    }
};

int main() {
    // Створення двох об'єктів
    Employee emp1, emp2;

    // Встановлення даних для emp1
    emp1.setAge(30);
    emp1.setWorkingYears(5);
    emp1.setSalary(15000);

    // Встановлення даних для emp2
    emp2.setAge(45);
    emp2.setWorkingYears(20);
    emp2.setSalary(28000);

    // Виведення інформації
    cout << "Інформація про першого:\n";
    emp1.displayData();

    cout << "\nІнформація про другого:\n";
    emp2.displayData();

    return 0;
}
