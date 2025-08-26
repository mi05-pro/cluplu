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

ostream &operator<<(ostream &os, const Student &rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}

template <class T>
void ShowVector(const vector<T> &v); // Displays vector properties

typedef vector<Student> SchoolClass;

int main()
{
    Student Harry;
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass GrowingClass;

    // Adding 4 students to the class using push_back()
    GrowingClass.push_back(Harry);
    GrowingClass.push_back(Sally);
    GrowingClass.push_back(Bill);
    GrowingClass.push_back(Peter);

    // Display class before changing ages
    cout << "GrowingClass before increasing ages:\n";
    ShowVector(GrowingClass);

    // Increase each student's age by 1
    for (int i = 0; i < GrowingClass.size(); ++i)
    {
        int newAge = GrowingClass[i].GetAge() + 1;
        GrowingClass[i].SetAge(newAge);
    }

    // Display class after changing ages
    cout << "GrowingClass after increasing ages by 1:\n";
    ShowVector(GrowingClass);

    return 0;
}

//
// Displays properties of the vector
//
template <class T>
void ShowVector(const vector<T> &v)
{
    cout << "max_size() = " << v.max_size();
    cout << "\tsize() = " << v.size();
    cout << "\tcapacity() = " << v.capacity();
    cout << "\t " << (v.empty() ? "empty" : "not empty");
    cout << "\n";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << "\n";
    cout << endl;
}
