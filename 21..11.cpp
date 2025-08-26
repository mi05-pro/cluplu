/*
Щоб змінити код так, щоб для відображення даних про кожного студента використовувався об'єкт функції, 
потрібно створити окремий клас-функцію, який буде відповідати за виведення інформації про студента. 
Цей клас-функція реалізує перевантаження оператора (), 
щоб об'єкт цього класу можна було викликати як функцію для виведення даних.
Створимо клас, наприклад, StudentPrinter, який буде відповідати за відображення інформації про студента.
В цьому класі реалізуємо оператор (), який буде виводити ім'я та вік студента.
Використаємо цей клас для виведення даних замість прямого використання operator<<.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
    Student();
    Student(const string &name, const int age);
    Student(const Student &rhs);
    ~Student();

    void SetName(const string &name);
    string GetName() const;
    void SetAge(const int age);
    int GetAge() const;
    Student &operator=(const Student &rhs);

private:
    string itsName;
    int itsAge;
};

Student::Student()
    : itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
                                       itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
    itsName = name;
}

string Student::GetName() const
{
    return itsName;
}

void Student::SetAge(const int age)
{
    itsAge = age;
}

int Student::GetAge() const
{
    return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
    itsName = rhs.GetName();
    itsAge = rhs.GetAge();
    return *this;
}

// Клас-функція для відображення даних про студента
class StudentPrinter
{
public:
    void operator()(const Student &student) const
    {
        cout << student.GetName() << " is " << student.GetAge() << " years old" << endl;
    }
};

template <class T>
void ShowVector(const vector<T> &v, const StudentPrinter &printer);

typedef vector<Student> SchoolClass;

int main()
{
    Student Harry;
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass GrowingClass;

    // Додаємо студентів до класу
    GrowingClass.push_back(Harry);
    GrowingClass.push_back(Sally);
    GrowingClass.push_back(Bill);
    GrowingClass.push_back(Peter);

    // Виводимо клас до зміни віку
    cout << "GrowingClass before increasing ages:\n";
    StudentPrinter printer;
    ShowVector(GrowingClass, printer);

    // Збільшуємо вік кожного студента на 1
    for (int i = 0; i < GrowingClass.size(); ++i)
    {
        int newAge = GrowingClass[i].GetAge() + 1;
        GrowingClass[i].SetAge(newAge);
    }

    // Виводимо клас після зміни віку
    cout << "GrowingClass after increasing ages by 1:\n";
    ShowVector(GrowingClass, printer);

    return 0;
}

//
// Відображає властивості вектора за допомогою об'єкта функції
//
template <class T>
void ShowVector(const vector<T> &v, const StudentPrinter &printer)
{
    cout << "max_size() = " << v.max_size();
    cout << "\tsize() = " << v.size();
    cout << "\tcapacity() = " << v.capacity();
    cout << "\t " << (v.empty() ? "empty" : "not empty");
    cout << "\n";
    for (int i = 0; i < v.size(); ++i)
    {
        printer(v[i]);  // Викликаємо об'єкт функції для виведення даних про студента
    }
    cout << endl;
}

/*
StudentPrinter:

Це новий клас, який реалізує оператор (). Це дозволяє створити об'єкт цього класу і викликати його як функцію для виведення інформації про студента.

У методі operator() ми отримуємо студента і виводимо його ім'я та вік.

ShowVector:

Тепер функція ShowVector приймає ще один параметр: об'єкт класу StudentPrinter. Для кожного студента вектору викликається цей об'єкт для виведення даних через printer(v[i]).

Використання об'єкта функції:

У функції main() створюється об'єкт printer класу StudentPrinter, який передається в ShowVector для виведення даних.
*/



