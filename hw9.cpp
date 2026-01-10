// 1.
/*
#include <iostream>
int main() {
    int x = 10;            // Звичайна змінна типу int
    int &ref = x;          // Посилання на змінну x
    int *ptr = &x;         // Вказівник на змінну x

    std::cout << "Початкове значення x: " << x << std::endl;

    // Змінимо значення через посилання
    ref = 20;
    std::cout << "Після зміни через посилання: " << x << std::endl;


    // Змінимо значення через вказівник
    *ptr = 30;
    std::cout << "Після зміни через вказівник: " << x << std::endl;

    return 0;
}
*/

//2.
/*
константний вказівник на постійне ціле значення означає, що:
Значення, на яке вказує вказівник, не можна змінювати через вказівник.
Сам вказівник не можна перепризначити (тобто він завжди вказує на ту саму адресу).
*/

/*
#include <iostream>
using namespace std;

int main() {
    int varOne = 6;

    // Константний вказівник на константне значення
    const int* const ptr = &varOne;

    // *ptr = 7; // ПОМИЛКА: не можна змінювати значення через ptr
    // int varTwo = 10;
    // ptr = &varTwo; // ПОМИЛКА: не можна перенаправити ptr

    cout << "varOne: " << varOne << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    return 0;
}
*/

//3.
/*
#include <iostream>
using namespace std;

int main() {
    int varOne = 6;

    // Константний вказівник на константне значення
    const int* const ptr = &varOne; 

    *ptr = 7; // error: read-only variable is not assignable
    int varTwo = 10;
    ptr = &varTwo; // error: cannot assign to variable 'ptr' with const-qualified type 'const int *const'
    // note: variable 'ptr' declared const here 62: const int* const ptr = &varOne;
    cout << "varOne: " << varOne << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    return 0;
}
    */
//4.
/*Блукаючий вказівник (dangling pointer). 
Це вказівник, який вказує на область пам’яті, яка більше не дійсна (наприклад, після видалення динамічного об’єкта)*/
// Не компілювати!

/*
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);  // виділяємо пам’ять і присвоюємо значення
    cout << "Value: " << *ptr << endl;

    delete ptr;              // звільняємо пам’ять

    // Блукаючий вказівник: ptr досі вказує на область, яка вже не дійсна
    cout << "Accessing dangling pointer (undefined behavior): " << *ptr << endl;

    // замісць однієї 
    // delete ptr;    
    //ptr = nullptr;  // Безпечний стан

    return 0;
}
*/

//5
/*
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);  // виділення пам’яті
    cout << "Value: " << *ptr << endl;

    delete ptr;    // звільнення пам’яті
    ptr = nullptr; // обнулення вказівника

    if (ptr != nullptr) {
        cout << "Still valid: " << *ptr << endl;
    } else {
        cout << "Pointer is null. Memory was freed safely." << endl;
    }

    return 0;
}
*/

// 6
/*
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);  // виділення пам’яті

    // Ми забули викликати delete, тому пам’ять не буде звільнена
    cout << "Value: " << *ptr << endl;

    // Втрачаємо доступ до пам’яті (наприклад, перепризначаємо вказівник)
    ptr = nullptr;

    return 0;

    // new int(42) — виділяє 4 байти в динамічній пам’яті (heap).
    // Ми не викликаємо delete ptr; — пам’ять не звільнена.
    // Присвоєння ptr = nullptr; означає, що ми втратили посилання на цю область пам’яті.
    //Ця пам’ять більше ніколи не буде доступна → витік.

}
    */

// 7
/* 
#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(42);
    cout << "Value: " << *ptr << endl;

    delete ptr;     // звільняємо пам’ять
    ptr = nullptr;  // захист від блукаючого вказівника

    return 0;
}
    */   

// 8
/*
#include <iostream>

using namespace std;

class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat &MakeCat(int age);

int main()
{
	int age = 7;
	Cat Boots = MakeCat(age);
	cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
	return 0;
}

Cat &MakeCat(int age)
{
	Cat *pCat = new Cat(age);
	return *pCat;
}
    // витік пам’яті, небезпечне повернення посилання на динамічний об’єкт
*/ 

// 9

#include <iostream>
using namespace std;

class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat* MakeCat(int age)
{
    return new Cat(age); // повертаємо вказівник
}

int main()
{
    int age = 7;
    Cat* pBoots = MakeCat(age); // отримуємо вказівник
    cout << "Boots is: " << pBoots->GetAge() << " years old" << endl;

    delete pBoots; // не забуваємо видалити!
    pBoots = nullptr;  // захист від блукаючого вказівника
    return 0;
}

