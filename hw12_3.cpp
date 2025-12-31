/*
class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual Shape(const Shape&); // тут помилка не може бути тут virtual
};
*/

class Shape
{
public:
	Shape();                        // Конструктор
	virtual ~Shape();               // Віртуальний деструктор
	Shape(const Shape&);            // Звичайний (НЕ virtual) конструктор копіювання

	// Альтернатива — віртуальний метод-клонер (віртуальний "конструктор-копіювальник")
	virtual Shape* clone() const = 0;
};
