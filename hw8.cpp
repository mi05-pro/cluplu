// 1.
// pOne — це вказівник на ціле число, але не ініціалізований.
// vTwo — це звичайна змінна типу int.
// pThree — це вказівник, який вказує на змінну vTwo, і через нього можна змінювати її значення.

// 2. 

// unsigned short yourAge;           // звичайна змінна
//unsigned short *pAge = &yourAge;  // вказівник на yourAge
/*
#include <iostream>
using namespace std;

int main() {
    unsigned short yourAge = 20;
    unsigned short *pAge = &yourAge;

    cout << "Your age: " << *pAge << endl; // виведе 20

    *pAge = 30; // зміна значення через вказівник

    cout << "Your age (updated): " << yourAge << endl; // виведе 30

    return 0;
}
*/

//3
/*
#include <iostream>
using namespace std;

int main() {
    unsigned short yourAge;            // Крок 1: оголошення змінної
    unsigned short *pAge = &yourAge;   // Крок 2: оголошення вказівника

    *pAge = 50;                         // Крок 3: присвоєння значення через вказівник

    cout << "Your age: " << yourAge << endl; // Перевірка

    return 0;
}
*/

//4
/*
#include <iostream>
using namespace std;

int main() {
    int number;        // Оголошення змінної типу int
    int *pNumber = &number; // Збереження адреси змінної в вказівнику

    *pNumber = 42;     // Присвоєння значення змінній через вказівник

    cout << "Значення змінної number: " << number << endl;

    return 0;
}
*/

//5
//Помилка в програмі полягає в використанні непроініціалізованого вказівника pInt
// 5.1 Вказівник вказує на існуючу змінну:
/*
#include <iostream>
using namespace std;

int main()
{
	int value;         // звичайна змінна
	int *pInt = &value; // pInt вказує на value
	*pInt = 9;         // присвоєння значення через вказівник

	cout << "The value at pInt: " << *pInt << endl;

	return 0;
}
*/
//5.2
//Використання динамічної пам’яті (через new):
/*
#include <iostream>
using namespace std;

int main()
{
	int *pInt = new int; // виділення пам’яті
	*pInt = 9;

	cout << "The value at pInt: " << *pInt << endl;

	delete pInt; // очищення пам’яті
	return 0;
}
*/

//6
/*
#include <iostream>

using namespace std;

int main()
{
	int SomeVariable = 5;
	cout << "SomeVariable: " << SomeVariable << "\n";

	int *pVar = &SomeVariable; // вказівник отримує адресу SomeVariable
	*pVar = 9;                 // присвоєння значення через вказівник

	cout << "SomeVariable: " << *pVar << "\n";
	return 0;
}
*/