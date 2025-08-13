#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    string surName;
    string fullName;

    cout << "Введіть Ваше ім'я: ";
    getline(cin, name);
    cout << "Введіть Ваше прізвище: ";
    getline(cin, surName);

     if (name.empty() || surName.empty()) {
        cerr << "Помилка: ви не ввели ім'я або прізвище!\n";
        return 1;
    }

    clog << "[LOG] Користувач ввів " << surName << '\n';

    fullName = name + " " + surName;

    cout << "Вас звати: " << fullName << endl;

    return 0;
}
