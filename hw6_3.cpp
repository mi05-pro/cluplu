#include <iostream>
using namespace std;

class Employee {
private:
    int age;
    int workYears;
    double salary;

public:
    // Сеттери (методи встановлення значень)
    void setAge(int a) {
        if (a >= 0)
            age = a;
        else
            cout << "Некоректний вік!" << endl;
    }

    void setWorkYears(int y) {
        if (y >= 0)
            workYears = y;
        else
            cout << "Некоректний стаж!" << endl;
    }

    void setSalary(double s) {
        if (s >= 0)
            salary = s;
        else
            cout << "Некоректна зарплата!" << endl;
    }

    // Геттери (методи читання значень)
    int getAge() {
        return age;
    }

    int getWorkYears() {
        return workYears;
    }

    double getSalary() {
        return salary;
    }

    // Метод для виведення даних
    void displayData() {
        cout << "Вік: " << getAge() << " років" << endl;
        cout << "Стаж роботи: " << getWorkYears() << " років" << endl;
        cout << "Зарплата: " << getSalary() << " грн" << endl;
    }
};

int main() {
    Employee emp;

    int age, workYears;
    double salary;

    cout << "Введіть вік: ";
    cin >> age;
    emp.setAge(age);

    cout << "Введіть стаж роботи: ";
    cin >> workYears;
    emp.setWorkYears(workYears);

    cout << "Введіть зарплату: ";
    cin >> salary;
    emp.setSalary(salary);

    cout << "\nІнформація про службовця:" << endl;
    emp.displayData();

    return 0;
}
