
/*

// Правильний підхід:  в ф-ю передавати за посиланням або вказівником.
// 1.

void SomeFunction(const Shape& s);  

Shape *pRect = new Rectangle;
SomeFunction(*pRect);    

//2. 

void SomeFunction(const Shape* s);

Shape *pRect = new Rectangle;
SomeFunction(pRect);

*/

/*

//1.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}

    virtual void draw() const {
        cout << "Drawing Shape" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const {
        cout << "Drawing Rectangle" << endl;
    }
};

// Функція приймає Shape за посиланням
void SomeFunction(const Shape& s) {
    s.draw();  // Поліморфний виклик
}

int main() {
    Shape* pRect = new Rectangle;
    SomeFunction(*pRect);  // Передаємо посилання — викликається Rectangle::draw()
    delete pRect;
    return 0;
}
*/

/* 

//2. 

#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}

    virtual void draw() const {
        cout << "Drawing Shape" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const {
        cout << "Drawing Rectangle" << endl;
    }
};

// Функція приймає Shape через вказівник
void SomeFunction(const Shape* s) {
    if (s) {
        s->draw();  // Поліморфний виклик
    }
}

int main() {
    Shape* pRect = new Rectangle;
    SomeFunction(pRect);  // Передаємо вказівник — викликається Rectangle::draw()
    delete pRect;
    return 0;
}

*/