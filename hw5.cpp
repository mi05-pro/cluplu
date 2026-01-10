#include <iostream>
using namespace std;

// 1,2

//int Perimeter(int length, int width); // прототип функції

// 5

float Dilen(unsigned short int a, unsigned short int b);

int main()
{
	// 5

	/*
	unsigned short int a = 100;
    unsigned short int b = 2;

	if (b==0) cout << "-1" ; 
    else cout << "Результат: " ; cout << Dilen(a,b);
    */

    // 1,2

	/*
	int length;
	int width;
	int perimeter;

	cout << "\nLength? ";
	cin >> length;
	cout << "\nWidth? ";
	cin >> width;


	cout << "\nLength? ";
	cin >> length;
	cout << "\nWidth? ";
	cin >> width;

	perimeter = Perimeter(length, width);

	cout << "\nPerimeter is ";
	cout << perimeter;
	*/
	
}

// 5

float Dilen(unsigned short int a, unsigned short int b){
	return a / b;
}

// 1,2
/*
int Perimeter(int length, int width)
{
	return 2 * length + 2 * width;
}
*/


// 3 баг в лістингу-неправильний запис int - не змінна:  y = myFunc(int);
// 4 перша помилка: int myFunc(unsigned short int x);{ - зайва ; друга майже помилка нема вводу x 
