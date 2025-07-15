//1.
//Створити в базовому класі  — Shape віртуальну функцію clone().
//реалізувати цю функцію в Square — повернення копії себе через new Square(*this)

#include <iostream>
using namespace std;

// Базовий клас
class Shape {
public:
    virtual ~Shape() {}

    // Віртуальний "конструктор копіювання"
    virtual Shape* clone() const = 0;

    virtual void draw() const = 0;
};

// Похідний клас
class Rectangle : public Shape { /*...*/ };

// Похідний клас
class Square : public Rectangle {
public:
    Square(int s = 0) : side(s) {}

    // Конструктор копіювання
    Square(const Square& other) : side(other.side) {}

    // Реалізація clone() — без 'override'
    virtual Shape* clone() const {
        return new Square(*this);
    }

    virtual void draw() const {
        cout << "Square with side " << side << endl;
    }

private:
    int side;
};

void drawClone(const Shape& shape) {
    Shape* copy = shape.clone();  // Віртуальне копіювання
    copy->draw();                 // Поліморфний виклик
    delete copy;
}

int main() {
    for (int i=1; i<=5; i++) {
       Square ss(i);
       drawClone(ss);  
        // Виведе: 
        /*
        Square with side 1
        Square with side 2
        Square with side 3
        Square with side 4
        Square with side 5
        */
    }
  
    return 0;
}

