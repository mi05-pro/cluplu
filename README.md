1.Запишіть віртуальний конструктор-копіювальник для класу Square.

class Square : public Rectangle {};

2. що неправильно у наступному програмному коді?

void SomeFunction(Shape);
Shape *pRect = new Rectangle;
SomeFunction(*pRect);

3. що неправильно у наступному програмному коді?
class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual Shape(const Shape&);
};
