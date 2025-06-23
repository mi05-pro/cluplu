1. Напишіть один оператор if, який перевіряє дві цілі численні змінні і присвоює змінній з більшим значенням менше значення, використовуючи лише один додатковий оператор else.

2. Проаналізуйте наступну програму. Уявіть, що ви ввели три значення. Який результат ви очікуєте отримати?

Copy code
#include <iostream>

using namespace std;

int main()

{

int a, b, c;

cout << "Please enter three numbers) \n";

cout << "a: ";

cin >> a;

cout << "\nb: ";

cin >> b;

cout << "\nc: ";

cin >> c;

if (c = (a - b))

{

     cout << "\na: ";

     cout << a;

     cout << " minus b: ";

     cout << b;

     cout << " equals c: ";

     cout << c << endl;

}

else

     cout << "a - b does not equal c: " << endl;

return 0;

}
3. Ведіть програму з вправи 2. Скомпілюйте і запустіть її на виконання. Ведіть числа 20, 10 і 50.Ви отримали результат який очікували? Чому ні?

4. Проаналізуйте цю програму та спрогнозуйте результат:


Copy code
#include <iostream>

using namespace std;
int main()

{

	int a = 1, b = 1, c;

	if (c = (a - b))

    	cout << "The value of c is: " << c;

	return 0;

}

5. Введіть, скомпілюєте і запустіть на виконання програму з вправи 4. Який був результат? Чому?
