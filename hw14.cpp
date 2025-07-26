
/*

1. Яка максимальна кількість елементів, які можна додати до зв'язаного списку?
Теоретично — необмежена, обмеження залежать лише від обсягу оперативної пам’яті (RAM) комп’ютера.
Кожен вузол списку виділяється динамічно. Поки вистачає пам’яті, можна додавати нові елементи.
*/
/*
2. Чи можна у зв'язаному списку використовувати індекси?
Ні напряму. Зв’язаний список не підтримує індексацію, як масив.
Щоб доступитися до елемента з індексом i, 
треба послідовно пройти список від початку до i-го вузла.

3. Яким є останній символ у рядку "Сергій - хороший хлопець"?
'ь'
Це останній символ в слові "хлопець".

4. Оголосіть клас вузла Node, який підтримує цілі числа

*/

#include <iostream>
using namespace std;

// Клас вузла
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Клас однозв'язаного списку
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Додавання елемента в кінець
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    // Виведення списку
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Пошук елемента за індексом
    int get(int index) const {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index)
                return current->data;
            current = current->next;
            count++;
        }
        throw out_of_range("Index out of range");
    }

    // Деструктор для очищення пам'яті
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Список: ";
    list.print();

try {
        cout << "Елемент [1]: " << list.get(1) << endl;     // 20
        cout << "Елемент [5]: " << list.get(5) << endl;     // Помилка
} 
catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

