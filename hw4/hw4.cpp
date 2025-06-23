#include <iostream>
using namespace std;
int main()
{
  // 1.

  int a = 10;
  int b = 20;

  int a3, b3, c3;
  int a5 = 1, b5 = 1, c5;

  cout << "a: "<<a<< ", b: "<<b; 


  // треба присвоїти змінній з більшим значенням менше значення
  if (a>b) a=b;
  else b=a;

  cout << "\nnew a: "<<a<< ", new b: "<<b; 



  // 2. Запросить три змінні кожну з нової строки, потім виконається блок if , оскільки " = " присвоєння
  // якщо a та b нерівні одне одному інакше виконається else блок



// 3. нове  error: redefinition of 'a', error: redefinition of 'b'

// warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
//if (c = (a - b))
//note: place parentheses around the assignment to silence this warning
//if (c = (a - b))
//note: use '==' to turn this assignment into an equality comparison
//if (c = (a - b))
      
     // ==
//1 warning and 2 errors generated.

// В outputvscode не запустилося-помилка вводу що тільки для читання,екзешник так результат
/*Please enter three numbers) 
a: 20

b: 10

c: 50
a - b does not equal c: 
Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.
Deleting expired sessions...none found.

[Process completed]*/


cout << "Please enter three numbers) \n";

cout << "a: ";

cin >> a3;

cout << "\nb: ";

cin >> b3;

cout << "\nc: ";

cin >> c3;

if (c3 == a3 - b3)

{

     cout << "\na: ";

     cout << a3;

     cout << " minus b: ";

     cout << b3;

     cout << " equal c: ";

     cout << c3 << endl;

}

else cout << "a - b does not equal c \n";

// 4 Значення c скоріш за все буде 2 на одиницю більше за попереднє ініціалізоване, з минулого досвіду помилка оскільки там не умова а присвоєння і нема дужок лаялося
// 5 по факту проігнорувало і нічого не видало в еxe , і якщо закоментувати задачу з вводом даних бачимо
/*hw4.cpp:102:9: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
        if (c5 = (a5 - b5))
            ~~~^~~~~~~~~~~
hw4.cpp:102:9: note: place parentheses around the assignment to silence this warning
        if (c5 = (a5 - b5))
               ^
            (             )
hw4.cpp:102:9: note: use '==' to turn this assignment into an equality comparison
        if (c5 = (a5 - b5))
               ^
               ==*/

// : The value of c is 0 // expected, оскільки ми переприсвоїли і тепер вона має нове значення - різницю рівних а і b тобто 0

	if (c5 == a5 - b5)
    
    	cout << "The value of c is: " << c5 << "\n";

	return 0;

}