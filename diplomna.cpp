#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class MyContainer {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    class Iterator {
    private:
        Node* ptr;
    public:
        Iterator(Node* node = nullptr) : ptr(node) {}
        T& operator*() { 
            if (!ptr) throw std::out_of_range("Dereferencing end iterator");
            return ptr->data; 
        }
        T* operator->() { 
            if (!ptr) throw std::out_of_range("Dereferencing end iterator");
            return &(ptr->data); 
        }
        Iterator& operator++() { if (ptr) ptr = ptr->next; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        friend class MyContainer<T>;
    };

    MyContainer() : head(nullptr), tail(nullptr), count(0) {}
    ~MyContainer() { while (head) pop_front(); }

    void push_front(const T& value) {
        Node* node = new Node(value);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
        ++count;
    }

    void push_back(const T& value) {
        Node* node = new Node(value);
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
        ++count;
    }

    void pop_front() {
        if (!head) throw std::out_of_range("pop_front on empty container");
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        --count;
    }

    void pop_back() {
        if (!tail) throw std::out_of_range("pop_back on empty container");
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        --count;
    }

    T& front() { 
        if (!head) throw std::out_of_range("front on empty container"); 
        return head->data; 
    }

    T& back() { 
        if (!tail) throw std::out_of_range("back on empty container"); 
        return tail->data; 
    }

    Iterator insert(Iterator pos, const T& value) {
        if (!pos.ptr) { // вставка в кінець
            push_back(value);
            return Iterator(tail);
        }
        Node* node = new Node(value);
        Node* current = pos.ptr;
        node->next = current;
        node->prev = current->prev;
        if (current->prev) current->prev->next = node;
        else head = node;
        current->prev = node;
        ++count;
        return Iterator(node);
    }

    size_t size() const { return count; }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

// ===== ПРИКЛАДИ РІЗНИХ ТИПІВ ======
class Person {
public:
    std::string name;
    int age;
    Person(std::string n, int a) : name(n), age(a) {}
};

int main() {
    try {
        // ---- Числа ----
        MyContainer<int> numbers;
        numbers.push_back(10);
        numbers.push_front(5);
        numbers.push_back(20);

        std::cout << "Numbers: ";
        MyContainer<int>::Iterator it_num = numbers.begin();
        while (it_num != numbers.end()) {
            std::cout << *it_num << " ";
            ++it_num;
        }
        std::cout << "\n";

        // ---- Рядки ----
        MyContainer<std::string> words;
        words.push_back("Hello");
        words.push_front("World");
        words.push_back("C++");

        std::cout << "Strings: ";
        MyContainer<std::string>::Iterator it_str = words.begin();
        while (it_str != words.end()) {
            std::cout << *it_str << " ";
            ++it_str;
        }
        std::cout << "\n";

        // ---- Власні об’єкти ----
        MyContainer<Person> people;
        people.push_back(Person("Alice", 30));
        people.push_front(Person("Bob", 25));
        people.push_back(Person("Charlie", 40));

        std::cout << "People:\n";
        MyContainer<Person>::Iterator it_person = people.begin();
        while (it_person != people.end()) {
            std::cout << it_person->name << ", " << it_person->age << "\n";
            ++it_person;
        }

        // Виклики front, back, pop_front, pop_back для винятків
        std::cout << "Front number: " << numbers.front() << "\n";
        std::cout << "Back word: " << words.back() << "\n";

        numbers.pop_front();
        numbers.pop_back();
        numbers.pop_back(); 
        numbers.pop_back(); // тут буде виняток, бо порожньо
       

    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}

/*

Numbers: 5 10 20 
Strings: World Hello C++ 
People:
Bob, 25
Alice, 30
Charlie, 40
Front number: 5
Back word: C++
Exception caught: pop_back on empty container

*/