1. Запишіть прототип для функції з ім'ям Perimeter, яка повертає значення типу unsigned long int та приймає два параметри типу unsigned short int.

2. Запишіть визначення функції Perimeter згідно з оголошенням у вправі 1. Два параметри, що нею приймаються, представляють довжину і ширину прямокутника, а функція повертає його периметр (подвоєна довжина плюс подвоєна ширина).

3. Баги: що неправильно у цій функції?

Copy code
#include <iostream>
using namespace std;

void myFunc(unsigned short int x);
int main()
{
    unsigned short int x, y;
    y = myFunc(int);
    cout << "x: " << x << "y: " << y << "\n";
}
void myFunc(unsigned short int x)
{
    return (4 * x);
}
4. Баги: що неправильно у цій функції?

Copy code
#include <iostream>
using namespace std;

int myFunc(unsigned short int x);

int main()
{
    unsigned short int x, y;
    y = myFunc(x);
    cout << "x: " << x << " y: " << y << "\n";
}

int myFunc(unsigned short int x);
{
    return (4 * x);
}
5. Напишіть функцію, яка приймає два параметри типу unsigned short int і повертає результат ділення першого параметра на другий. Функція не повинна виконувати операцію поділу, якщо друге число дорівнює нулю, але в цьому випадку вона має повернути значення -1.

6. Напишіть програму, яка запитує у користувача два числа і викликає функцію, записану при виконанні вправи 5. Виведіть результат або повідомлення про помилку, якщо функція поверне значення, що дорівнює - 1.
