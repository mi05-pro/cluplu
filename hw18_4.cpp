 /*Для чого потрібен оператор виведення:
В C++ стандартний потік std::cout працює з типами даних, 
такими як int, char, double, і т.д.
 Але якщо ви створюєте свій клас, вам потрібно визначити, 
 як об'єкти цього класу будуть виводитися.

За допомогою перевантаження оператора <<, 
ви надаєте стандартному потоку виведення 
можливість працювати з об'єктами вашого класу так само, 
як і з іншими типами даних.*/

/*
Щоб додати перевантажений оператор виведення << в клас String, 
потрібно створити глобальну функцію, яка приймає потік виведення (ostream) 
і об'єкт класу String, та дозволяє виводити рядок на екран.
*/

#include <iostream>
#include <string>

using namespace std;

class String
{
public:
    // конструктори
    String();
    String(const char *const);
    String(const String &);
    ~String();
    // Перевантажені оператори
    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);
    // Загальні методи доступу
    int GetLen() const { return itsLen; }
    const char *GetString() const { return itsString; }
    
private:
    String(int); // закритий конструктор
    char *itsString;
    unsigned short itsLen;
};

// конструктор класу String за замовчуванням створює рядок завдовжки 0 байт
String::String()
{
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen = 0;
}

// закритий конструктор, який використовується тільки
// методами класу до створення нового рядка
// Вказаного розміру, заповненого нулями
String::String(int len)
{
    itsString = new char[len + 1];
    for (int i = 0; i <= len; i++)
        itsString[i] = '\0';
    itsLen = len;
}

// Перетворює масив символів у рядок
String::String(const char *const cString)
{
    itsLen = strlen(cString);
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = cString[i];
    itsString[itsLen] = '\0';
}

// Конструктор-копіювальник
String::String(const String &rhs)
{
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
}

// Деструктор звільняє зайняту пам'ять
String::~String()
{
    delete[] itsString;
    itsLen = 0;
}

// Цей оператор звільняє пам'ять, та копіює рядок і розмір
String &String::operator=(const String &rhs)
{
    if (this == &rhs)
        return *this;
    delete[] itsString;
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    return *this;
}

// Неконстантний оператор індексування.
// Повертає посилання на символ, який можна змінити
char &String::operator[](int offset)
{
    if (offset > itsLen)
        return itsString[itsLen - 1];
    else
        return itsString[offset];
}

// Константний оператор індексування,
// використовується для константних об'єктів
char String::operator[](int offset) const
{
    if (offset > itsLen)
        return itsString[itsLen - 1];
    else
        return itsString[offset];
}

// створює новий рядок, додаючи поточний
// рядок до rhs
String String::operator+(const String &rhs)
{
    int totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
        temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
        temp[i] = rhs[j];
    temp[totalLen] = '\0';
    return temp;
}

// змінює поточний рядок, нічого не повертаючи
void String::operator+=(const String &rhs)
{
    unsigned short rhsLen = rhs.GetLen();
    unsigned short totalLen = itsLen + rhsLen;
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
        temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
        temp[i] = rhs[i - itsLen];
    temp[totalLen] = '\0';
    *this = temp;
}

// Перевантажений оператор виведення (<<)
ostream& operator<<(ostream& os, const String& str)
{
    os << str.GetString();
    return os;
}

int main()
{
    String str1("Hello");
    String str2(" World!");
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    
    String str3 = str1 + str2;
    cout << "str3 (str1 + str2): " << str3 << endl;

    str1 += str2;
    cout << "str1 after += str2: " << str1 << endl;

    return 0;
}

/*
str1: Hello
str2:  World!
str3 (str1 + str2): Hello World!
str1 after += str2: Hello World!

*/
