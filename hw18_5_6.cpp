/*
проблема в тому, що намагаєшся оголосити friend class Animal
всередині тіла звичайної функції
friend у C++ можна використовувати тільки всередині оголошення класу, 
щоб надати іншому класу або функції доступ до приватних членів
Треба оголосити функцію setValue як friend-функцію прямо в класі Animal:
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    int GetWeight() const { return itsWeight; }
    int GetAge() const { return itsAge; }

    friend void setValue(Animal &, int); // friend-оголошення тут

private:
    int itsWeight;
    int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight; // тепер можна
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    cout << "Weight: " << peppy.GetWeight() << endl;
    return 0;
}
