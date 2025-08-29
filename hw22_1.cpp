#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;

        if (b == 0) {
            throw runtime_error("Ділення на нуль!");
        }

        int result = a / b;
        cout << "Результат: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
