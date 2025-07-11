/*1
Щоб перевантажити оператори преінкремента (++i) та постінкремента (i++) 
для класу SimpleCircle, де є змінна itsRadius, 
ЛОГІЧНО потрібно визначити відповідні оператори в класі.
Оператор преінкремента змінює значення до використання, а оператор постінкремента — після.*/
/*
#include <iostream>
using namespace std;

class SimpleCircle {
private:
    double itsRadius;

public:
    // Конструктор
    SimpleCircle(double radius = 1.0) : itsRadius(radius) {}

    // Геттер для отримання значення радіусу
    double getRadius() const {
        return itsRadius;
    }

    // Оператор преінкремента (prefix ++)
    SimpleCircle& operator++() {
        ++itsRadius;  // Збільшуємо радіус перед поверненням об'єкта
        return *this;
    }

    // Оператор постінкремента (postfix i++)
    SimpleCircle operator++(int) {
        SimpleCircle temp = *this;  // Зберігаємо копію поточного об'єкта
        itsRadius++;  // Збільшуємо радіус після того, як копія була створена
        return temp;  // Повертаємо копію (до зміни)
    }

    // Виведення радіусу
    void print() const {
        cout << "Radius: " << itsRadius << endl;
    }
};

int main() {
    SimpleCircle circle(5.0);

    cout << "Initial ";
    circle.print();

    // Преінкремент
    ++circle;
    cout << "After prefix increment: ";
    circle.print();

    // Постінкремент
    circle++;
    cout << "After postfix increment: ";
    circle.print();

    return 0;

    //Initial Radius: 5
    //After prefix increment: Radius: 6
    //After postfix increment: Radius: 7
}
*/

/*2.

Щоб змінити клас SimpleCircle таким чином, щоб змінна itsRadius 
зберігалася в динамічній області пам'яті, 
ми можемо використовувати вказівник і виділяти пам'ять за допомогою оператора new. 
Для цього також потрібно буде реалізувати конструктор копіювання, 
оператор присвоєння та деструктор, 
щоб коректно працювати з динамічною пам'яттю.

*/

/*
#include <iostream>
using namespace std;

class SimpleCircle {
private:
    double* itsRadius;  // Пам'ять для радіусу виділяється динамічно

public:
    // Конструктор за замовчуванням
    SimpleCircle(double radius = 1.0) {
        itsRadius = new double(radius);  // Виділяємо пам'ять для радіусу
    }

    // Деструктор для коректного звільнення пам'яті
    ~SimpleCircle() {
        delete itsRadius;  // Звільняємо пам'ять
    }

    // Конструктор копіювання
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*other.itsRadius);  // Копіюємо значення з іншого об'єкта
    }

    // Оператор присвоєння
    SimpleCircle& operator=(const SimpleCircle& other) {
        if (this != &other) {
            // Спочатку звільняємо стару пам'ять
            delete itsRadius;
            // Виділяємо нову пам'ять та копіюємо значення
            itsRadius = new double(*other.itsRadius);
        }
        return *this;
    }

    // Геттер для отримання значення радіусу
    double getRadius() const {
        return *itsRadius;
    }

    // Оператор преінкремента (prefix ++)
    SimpleCircle& operator++() {
        ++(*itsRadius);  // Збільшуємо радіус перед поверненням об'єкта
        return *this;
    }

    // Оператор постінкремента (postfix i++)
    SimpleCircle operator++(int) {
        SimpleCircle temp = *this;  // Зберігаємо копію поточного об'єкта
        ++(*itsRadius);  // Збільшуємо радіус після того, як копія була створена
        return temp;  // Повертаємо копію (до зміни)
    }

    // Виведення радіусу
    void print() const {
        cout << "Radius: " << *itsRadius << endl;
    }
};

int main() {
    SimpleCircle circle(5.0);

    cout << "Initial ";
    circle.print();

    // Преінкремент
    ++circle;
    cout << "After prefix increment: ";
    circle.print();

    // Постінкремент
    circle++;
    cout << "After postfix increment: ";
    circle.print();

    return 0;

    //Initial Radius: 5
    //After prefix increment: Radius: 6
    //After postfix increment: Radius: 7
}
*/

/*
3. Конструктор копіювання необхідний для створення нового об'єкта, 
який є копією існуючого, причому він повинен правильно обробляти динамічно виділену пам'ять 
(у нашому випадку для itsRadius). Конструктор копіювання має створювати новий об'єкт 
з копією значення, на яке вказує вказівник, щоб уникнути спільного доступу до однієї пам'яті 
в двох об'єктах (це може призвести до помилок, 
якщо один об'єкт буде змінювати значення чи видаляти пам'ять).
*/

/*
#include <iostream>
using namespace std;

class SimpleCircle {
private:
    double* itsRadius;  // Пам'ять для радіусу виділяється динамічно

public:
    // Конструктор за замовчуванням
    SimpleCircle(double radius = 1.0) {
        itsRadius = new double(radius);  // Виділяємо пам'ять для радіусу
    }

    // Конструктор копіювання
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*other.itsRadius);  // Виділяємо нову пам'ять і копіюємо значення
        cout << "Copy constructor called." << endl;
    }

    // Оператор присвоєння
    SimpleCircle& operator=(const SimpleCircle& other) {
        if (this != &other) {
            // Спочатку звільняємо стару пам'ять
            delete itsRadius;
            // Виділяємо нову пам'ять та копіюємо значення
            itsRadius = new double(*other.itsRadius);
        }
        return *this;
    }

    // Деструктор для коректного звільнення пам'яті
    ~SimpleCircle() {
        delete itsRadius;  // Звільняємо пам'ять
    }

    // Геттер для отримання значення радіусу
    double getRadius() const {
        return *itsRadius;
    }

    // Оператор преінкремента (prefix ++)
    SimpleCircle& operator++() {
        ++(*itsRadius);  // Збільшуємо радіус перед поверненням об'єкта
        return *this;
    }

    // Оператор постінкремента (postfix i++)
    SimpleCircle operator++(int) {
        SimpleCircle temp = *this;  // Зберігаємо копію поточного об'єкта
        ++(*itsRadius);  // Збільшуємо радіус після того, як копія була створена
        return temp;  // Повертаємо копію (до зміни)
    }

    // Виведення радіусу
    void print() const {
        cout << "Radius: " << *itsRadius << endl;
    }
};

int main() {
    SimpleCircle circle1(5.0);
    cout << "Circle1: ";
    circle1.print();

    // Використання конструктора копіювання
    SimpleCircle circle2 = circle1;  // Вони викликають конструктор копіювання
    cout << "Circle2 (after copy): ";
    circle2.print();

    // Змінимо значення радіусу у першому колі
    ++circle1;
    cout << "Circle1 (after increment): ";
    circle1.print();

    cout << "Circle2 (after Circle1 increment): ";
    circle2.print();

    return 0;

    //Circle1: Radius: 5
    //Copy constructor called.
    //Circle2 (after copy): Radius: 5
    //Circle1 (after increment): Radius: 6
    //Circle2 (after Circle1 increment): Radius: 5
}

*/


/* 4.
Перевантаження оператора присвоєння в класі SimpleCircle має на меті 
правильне копіювання даних між двома об'єктами. 
Якщо клас використовує динамічну пам'ять (як у нашому випадку з itsRadius), 
потрібно переконатися, що старі ресурси звільняються перед копіюванням нових значень,
 щоб уникнути витоків пам'яті.
*/
/*
#include <iostream>
using namespace std;

class SimpleCircle {
private:
    double* itsRadius;  // Пам'ять для радіусу виділяється динамічно

public:
    // Конструктор за замовчуванням
    SimpleCircle(double radius = 1.0) {
        itsRadius = new double(radius);  // Виділяємо пам'ять для радіусу
    }

    // Конструктор копіювання
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*other.itsRadius);  // Виділяємо нову пам'ять і копіюємо значення
        cout << "Copy constructor called." << endl;
    }

    // Оператор присвоєння
    SimpleCircle& operator=(const SimpleCircle& other) {
        // Перевірка на самоприсвоєння
        if (this != &other) {
            // Спочатку звільняємо стару пам'ять
            delete itsRadius;
            // Виділяємо нову пам'ять та копіюємо значення
            itsRadius = new double(*other.itsRadius);
            cout << "Assignment operator called." << endl;
        }
        return *this;  // Повертаємо поточний об'єкт
    }

    // Деструктор для коректного звільнення пам'яті
    ~SimpleCircle() {
        delete itsRadius;  // Звільняємо пам'ять
    }

    // Геттер для отримання значення радіусу
    double getRadius() const {
        return *itsRadius;
    }

    // Оператор преінкремента (prefix ++)
    SimpleCircle& operator++() {
        ++(*itsRadius);  // Збільшуємо радіус перед поверненням об'єкта
        return *this;
    }

    // Оператор постінкремента (postfix i++)
    SimpleCircle operator++(int) {
        SimpleCircle temp = *this;  // Зберігаємо копію поточного об'єкта
        ++(*itsRadius);  // Збільшуємо радіус після того, як копія була створена
        return temp;  // Повертаємо копію (до зміни)
    }

    // Виведення радіусу
    void print() const {
        cout << "Radius: " << *itsRadius << endl;
    }
};

int main() {
    SimpleCircle circle1(5.0);
    cout << "Circle1: ";
    circle1.print();

    // Використання конструктора копіювання
    SimpleCircle circle2 = circle1;  // Викликається конструктор копіювання
    cout << "Circle2 (after copy): ";
    circle2.print();

    // Зміна значення радіусу в першому колі
    ++circle1;
    cout << "Circle1 (after increment): ";
    circle1.print();

    cout << "Circle2 (after Circle1 increment): ";
    circle2.print();

    // Використання оператора присвоєння
    SimpleCircle circle3(10.0);
    cout << "Circle3 (before assignment): ";
    circle3.print();

    circle3 = circle1;  // Викликається оператор присвоєння
    cout << "Circle3 (after assignment): ";
    circle3.print();

    return 0;
}
*/

/*5. Програма, яка створює два об'єкти класу SimpleCircle, 
один з яких ініціалізується значенням за замовчуванням,
 а другому надається значення 9. 
 З кожним із об'єктів застосовується оператор інкремента, 
 а потім значення одного об'єкта присвоюється іншому. 
Результати виводяться на екран.*/

/*

#include <iostream>
using namespace std;

class SimpleCircle {
private:
    double* itsRadius;  // Пам'ять для радіусу виділяється динамічно

public:
    // Конструктор за замовчуванням
    SimpleCircle(double radius = 1.0) {
        itsRadius = new double(radius);  // Виділяємо пам'ять для радіусу
    }

    // Конструктор копіювання
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new double(*other.itsRadius);  // Виділяємо нову пам'ять і копіюємо значення
    }

    // Оператор присвоєння
    SimpleCircle& operator=(const SimpleCircle& other) {
        // Перевірка на самоприсвоєння
        if (this != &other) {
            // Спочатку звільняємо стару пам'ять
            delete itsRadius;
            // Виділяємо нову пам'ять та копіюємо значення
            itsRadius = new double(*other.itsRadius);
        }
        return *this;  // Повертаємо поточний об'єкт
    }

    // Деструктор для коректного звільнення пам'яті
    ~SimpleCircle() {
        delete itsRadius;  // Звільняємо пам'ять
    }

    // Геттер для отримання значення радіусу
    double getRadius() const {
        return *itsRadius;
    }

    // Оператор преінкремента (prefix ++)
    SimpleCircle& operator++() {
        ++(*itsRadius);  // Збільшуємо радіус перед поверненням об'єкта
        return *this;
    }

    // Оператор постінкремента (postfix i++)
    SimpleCircle operator++(int) {
        SimpleCircle temp = *this;  // Зберігаємо копію поточного об'єкта
        ++(*itsRadius);  // Збільшуємо радіус після того, як копія була створена
        return temp;  // Повертаємо копію (до зміни)
    }

    // Виведення радіусу
    void print() const {
        cout << "Radius: " << *itsRadius << endl;
    }
};

int main() {
    // Створення першого об'єкта за замовчуванням
    SimpleCircle circle1;
    cout << "Initial circle1: ";
    circle1.print();  // Виведення значення радіусу першого кола

    // Створення другого об'єкта з ініціалізацією 9
    SimpleCircle circle2(9.0);
    cout << "Initial circle2: ";
    circle2.print();  // Виведення значення радіусу другого кола

    // Використовуємо оператор преінкремента для обох об'єктів
    ++circle1;
    ++circle2;

    cout << "circle1 after prefix increment: ";
    circle1.print();  // Виведення після преінкремента першого кола

    cout << "circle2 after prefix increment: ";
    circle2.print();  // Виведення після преінкремента другого кола

    // Надаємо значення одного об'єкта іншому
    circle1 = circle2;

    cout << "circle1 after assignment from circle2: ";
    circle1.print();  // Виведення результату після присвоєння

    return 0;

    //Initial circle1: Radius: 1
    //Initial circle2: Radius: 9
    //circle1 after prefix increment: Radius: 2
    //circle2 after prefix increment: Radius: 10
    //circle1 after assignment from circle2: Radius: 10
}
*/

/*6. Помилки
що неправильно у наступному прикладі використання оператора присвоєння?
SQUARE SQUARE::operator=(const SQUARE &rhs)
{
	itsSide = new int;
	*itsSide = rhs.GetSide();
	return *this:
}   
-
Відсутність звільнення старої пам'яті - витік пам'яті р 468 перед new, 470 ;
Копіювання вказівника без перевірки на самоприсвоєння: if (this != &rhs)

правильний код

SQUARE& SQUARE::operator=(const SQUARE& rhs)
{
    // Перевірка на самоприсвоєння
    if (this != &rhs) {
        // Якщо вже є виділена пам'ять для itsSide, звільняємо її
        delete itsSide;

        // Виділяємо нову пам'ять і копіюємо значення
        itsSide = new int;
        *itsSide = rhs.GetSide();
    }
    return *this;  // Повертаємо поточний об'єкт
}

*/

/* 7.
Що є неправильним у наступному прикладі використання оператора сумування?
VeryShort VeryShort::operator+(const VeryShort &rhs)
{
	itsVal += rhs.GetItsVal();
	return *this;
}   
-
правильний код
VeryShort VeryShort::operator+(const VeryShort &rhs)
{
    VeryShort result;                // Створюємо новий об'єкт для результату
    result.itsVal = this->itsVal + rhs.GetItsVal();  // Сумуємо значення і зберігаємо в новому об'єкті
    return result;                    // Повертаємо новий об'єкт
}

*/

/* 8.
Запишіть оголошення класу Square, 
успадкованого від класу Rectangle, який, у свою чергу, 
виготовлений від класу Shape.
*/

/*
#include <iostream>
using namespace std;

// Базовий клас Shape
class Shape {
public:
    // Функція для малювання 
    void draw() const {
        cout << "Drawing a Shape" << endl;
    }

    // Деструктор 
    ~Shape() {}
};

// Клас Rectangle, успадкований від Shape
class Rectangle : public Shape {
protected:
    double width, height;  // Ширина і висота прямокутника
public:
    // Конструктор
    Rectangle(double w, double h) : width(w), height(h) {}

    // Функція для обчислення площі
    double area() const {
        return width * height;
    }

    // Функція для малювання прямокутника (не віртуальна)
    void draw() const {
        cout << "Drawing a Rectangle with width = " << width << " and height = " << height << endl;
    }

    // Встановлення ширини та висоти
    void setDimensions(double w, double h) {
        width = w;
        height = h;
    }
};

// Клас Square, успадкований від Rectangle
class Square : public Rectangle {
public:
    // Конструктор класу Square, який приймає один параметр (довжина сторони)
    Square(double length) : Rectangle(length, length) {
        // Викликається конструктор класу Rectangle, передаючи однакові значення для довжини і ширини
    }

    // Функція для малювання квадрата 
    void draw() const {
        cout << "Drawing a Square with side = " << width << endl;
    }

    // Функція для обчислення площі квадрата
    double area() const {
        return width * width;  // Площа квадрата = сторона * сторона
    }
};

int main() {
    // Створення об'єкта Square
    Square sq(5.0);

    // Використання функцій класів
    sq.draw();  // Виведе "Drawing a Square with side = 5"
    cout << "Area of Square: " << sq.area() << endl;  // Виведе "Area of Square: 25"

    // Зміна сторони квадрата
    sq.setDimensions(10.0, 10.0);
    sq.draw();  // Виведе "Drawing a Square with side = 10"
    cout << "Area of Square: " << sq.area() << endl;  // Виведе "Area of Square: 100"

    return 0;
}
//Drawing a Square with side = 5
//Area of Square: 25
//Drawing a Square with side = 10
//Area of Square: 100
*/

/*9.
Припустимо, що у попередньому прикладі об'єкт класу Shape не використовує параметри, 
об'єкт класу Rectangle приймає два параметри (length і width), 
а об'єкт класу Square - один параметр (length); запишіть конструктор класу Square.
*/

/*
#include <iostream>
using namespace std;

// Базовий клас Shape
class Shape {
public:
    // Конструктор класу Shape, без параметрів
    Shape() {
        // Якщо потрібно, можна додати деяку ініціалізацію або виведення
        cout << "Shape created" << endl;
    }

    // Функція для малювання (не віртуальна)
    void draw() const {
        cout << "Drawing a Shape" << endl;
    }

    // Деструктор (не віртуальний)
    ~Shape() {}
};

// Клас Rectangle, успадкований від Shape
class Rectangle : public Shape {
protected:
    double width, height;  // Ширина і висота прямокутника
public:
    // Конструктор класу Rectangle
    Rectangle(double w, double h) : width(w), height(h) {
        // Викликається конструктор Shape, який не приймає параметрів
        cout << "Rectangle created with width = " << width << " and height = " << height << endl;
    }

    // Функція для обчислення площі
    double area() const {
        return width * height;
    }

    // Функція для малювання прямокутника (не віртуальна)
    void draw() const {
        cout << "Drawing a Rectangle with width = " << width << " and height = " << height << endl;
    }

    // Встановлення ширини та висоти
    void setDimensions(double w, double h) {
        width = w;
        height = h;
    }
};

// Клас Square, успадкований від Rectangle
class Square : public Rectangle {
public:
    // Конструктор класу Square, який приймає один параметр (довжина сторони)
    Square(double length) : Rectangle(length, length) {
        // Викликається конструктор класу Rectangle, передаючи однакові значення для довжини і ширини
        cout << "Square created with side = " << length << endl;
    }

    // Функція для малювання квадрата (не віртуальна)
    void draw() const {
        cout << "Drawing a Square with side = " << width << endl;
    }

    // Функція для обчислення площі квадрата
    double area() const {
        return width * width;  // Площа квадрата = сторона * сторона
    }
};

int main() {
    // Створення об'єкта Square
    Square sq(5.0);

    // Використання функцій класів
    sq.draw();  // Виведе "Drawing a Square with side = 5"
    cout << "Area of Square: " << sq.area() << endl;  // Виведе "Area of Square: 25"

    // Зміна сторони квадрата
    sq.setDimensions(10.0, 10.0);
    sq.draw();  // Виведе "Drawing a Square with side = 10"
    cout << "Area of Square: " << sq.area() << endl;  // Виведе "Area of Square: 100"

    return 0;
}

// Shape created
// Rectangle created with width = 5 and height = 5
// quare created with side = 5
// Drawing a Square with side = 5
// Area of Square: 25
// Drawing a Square with side = 10
// Area of Square: 100

*/