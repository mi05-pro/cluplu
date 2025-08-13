/*
Читає кожен символ з потоку cin (cin.get(ch)).

Якщо зустрічає ! — він не виводить !, а повертає в потік символ $ за допомогою putback('$').
Потім цей $ знову зчитується при наступному витку циклу і виводиться.

Якщо бачить, що наступний символ — # (cin.peek()), то ігнорує його (не виводить) за допомогою ignore().


 у переписаній версії без putback() і ignore():

putback('$') просто прямий вивід $, коли побачили !.

ignore() - на перевірку if (ch == '#') continue;, щоб пропустити символи # без читання "зайвого разу".

example string:
Some dogs are #Large some very #small. No matter the size Dog is easier to handle then Horse!
*/


#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "enter a phrase: ";

    while (cin.get(ch)) {
        if (ch == '!') {
            cout << '$'; // одразу виводимо $
        }
        else if (ch == '#') {
            continue; // просто пропускаємо #
        }
        else {
            cout << ch; // звичайний символ
        }
    }

    return 0;
}
