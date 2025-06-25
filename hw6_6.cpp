#include <iostream>
using namespace std;

class Employee {
private:
    int age;
    int workingYears;
    double salary;

public:
    // Сеттери

    // Конструктор з параметрами
    Employee(int a, int y, double s) {
        if (a >= 0) age = a; else age = 0;
        if (y >= 0) workingYears = y; else workingYears = 0;
        if (s >= 0) salary = s; else salary = 0.0;
    }

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

    int getUsdSalary(){
        float curs = 42; 
        return salary / curs;
    }

    // Метод для виводу
    void displayData() {
        cout << "Вік: " << getAge() << " років" << endl;
        cout << "Стаж роботи: " << getWorkingYears() << " років" << endl;
        cout << "Зарплата: " << getSalary() << " грн" << endl;
        cout << "Зарплата $: " << getUsdSalary() << " $" << endl;
    }
};

int main() {
// Створення об'єктів через конструктор
    Employee emp1(30, 5, 15000);
    Employee emp2(45, 20, 28000);

    // Виведення інформації
    cout << "Інформація про першого:\n";
    emp1.displayData();

    cout << "\nІнформація про другого:\n";
    emp2.displayData();

    return 0;
}
