/*
програма, яка:
Отримує аргументи командного рядка args[]
Виводить їх у зворотному порядку.
Ім’я програми (args[0]) теж має бути виведене, але в самому кінці.
*/

/*

terminal line at folder 
./hw20_2 par1 par2
result
par2 par1 ./hw20_2

*/


#include <iostream>
using namespace std;

int main(int ac, char* args[]) { //ac -argument counts
    if (ac == 1) { 
        cout << "Немає аргументів." << endl;
        return 0;
    }

    // Виводимо аргументи у зворотному порядку, окрім імені програми
    for (int i = ac - 1; i > 0; --i) {
        cout << args[i] << " ";
    }

    // А тепер ім'я програми в самому кінці
    cout << args[0] << endl;

    return 0;
}

