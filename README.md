1. Поясніть зміст наступних об'яв змінних.

	• int *pOne;

	• int vTwo:

	• int *pThree = &vTwo;

2. Допустимо, в програмі оголошена змінна yourAge типу unsigned short. Як оголосити вказівник, що дозволяє маніпулювати цією змінною?

3. За допомогою вказівника присвойте змінній вашого значення 50.

4. Напишіть невелику програму і оголосіть змінну типу int і вказівник на цей тип. Збережіть адресу змінної в вказівнику. Використовуючи вказівник, надайте змінній якесь значення.

#include <iostream>

using namespace std;

int main()
{
	int *pInt;
	*pInt = 9;
	cout << " The value at pInt: "<< *pInt;

	return 0;
}

5. знайдіть помилку у наступному фрагменті програми.
#include <iostream>

using namespace std;

int main()
{
	int *pInt;
	*pInt = 9;
	cout << " The value at pInt: "<< *pInt;

	return 0;
}

6. знайдіть помилку у наступному фрагменті програми.
#include <iostream>

using namespace std;

int main()
{
	int SomeVariable = 5;
	cout << "SomeVariable: " << SomeVariable << "\n";
	int *pVar = &SomeVariable;
	pVar = 9;
	cout << "SomeVariable: " << *pVar << "\n";
	return 0;
}


