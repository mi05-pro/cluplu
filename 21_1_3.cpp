/*
Перетворимо ваш клас List у шаблон класу, 
щоб він міг працювати з будь-яким типом даних, а не лише з int
Замінюємо всі int на шаблонний тип T.
Додаємо параметр шаблону template <typename T>.
Усередині внутрішнього класу ListCell теж використовуємо T, а не int.
Отримаємо:
*/

#include <iostream>
using namespace std;

template <typename T>
class List {
public:
    List() : head(0), tail(0), theCount(0) {}

    virtual ~List() {
        while (head != nullptr) {
            ListCell* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(T value) {
        ListCell* newCell = new ListCell(value, head);
        head = newCell;
        if (tail == nullptr) {
            tail = head;
        }
        theCount++;
    }

    void append(T value) {
        ListCell* newCell = new ListCell(value);
        if (tail != nullptr) {
            tail->next = newCell;
        } else {
            head = newCell;
        }
        tail = newCell;
        theCount++;
    }

    int is_present(T value) const {
        ListCell* current = head;
        while (current != nullptr) {
            if (current->val == value) {
                return 1;
            }
            current = current->next;
        }
        return 0;
    }

    int is_empty() const {
        return head == nullptr;
    }

    int count() const {
        return theCount;
    }

private:
    class ListCell {
    public:
        ListCell(T value, ListCell* cell = nullptr)
            : val(value), next(cell) {}

        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

int main() {
    List<int> intList;
    intList.append(10);
    intList.insert(5);
    cout << "Is 10 present? " << intList.is_present(10) << endl;
    cout << "Count: " << intList.count() << endl;

    List<string> strList;
    strList.append("hello");
    strList.insert("world");
    cout << "Is 'world' present? " << strList.is_present("world") << endl;
    cout << "Count: " << strList.count() << endl;

    return 0;
}
