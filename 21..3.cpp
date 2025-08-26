#include <iostream>
#include <string>
using namespace std;

// === Шаблон класу List<T> ===
template <typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}

    ~List() {
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
        ListCell(T value, ListCell* nextCell = nullptr)
            : val(value), next(nextCell) {}

        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

// === Клас Cat (для прикладу) ===
class Cat {
public:
    Cat(string name = "") : name(name) {}
    bool operator==(const Cat& other) const {
        return name == other.name;
    }
private:
    string name;
};

// === Головна функція ===
int main() {
    // 1. Список рядків
    List<string> stringList;
    stringList.append("Привіт");
    stringList.append("Світ");

    // 2. Список котів
    List<Cat> catList;
    catList.append(Cat("Мурчик"));
    catList.insert(Cat("Барсик"));

    // 3. Список цілих чисел
    List<int> intList;
    intList.append(1);
    intList.append(2);
    intList.insert(0);

    cout << "Кількість рядків: " << stringList.count() << endl;
    cout << "Кількість котів: " << catList.count() << endl;
    cout << "Кількість чисел: " << intList.count() << endl;

    return 0;
}
