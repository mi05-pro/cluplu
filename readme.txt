

1. Напишіть програму, яка використовує чотири стандартні об'єкти класу iostream - cin, cout, cerr і clog.

2. Напишіть програму, яка пропонує користувачеві ввести повне ім'я з наступним виведенням цього імені на екран.

﻿3. Перепишіть лістинг 16.9, відмовившись від використання методів putback() та ignore().


16.9

#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch))
    {
        if (ch == '!')
            cin.putback('$');
        else
            cout << ch;
        while (cin.peek() == '#')
            cin.ignore(1, '#');
    }

    return 0;
}
////
enter a phrase: Now!is#the!time#for!fun#!
Now$isthe$timefor$fun$

