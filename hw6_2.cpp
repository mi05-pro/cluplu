#include <iostream>
using namespace std;

class Employee {
public:
    int age;
    int yearsOfService;
    double salary;

    // Конструктор за замовчуванням
    Employee() {
        age = 0;
        yearsOfService = 0;
        salary = 0.0;
    }

    void inputData() {      
    }

    void displayData() {     
    }
};

int main() {
    Employee emp;
    emp.inputData();
    emp.displayData();
    return 0;
}
