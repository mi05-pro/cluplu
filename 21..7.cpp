
/*Повна реалізація дружнього оператора operator== для шаблонного класу List<T>. 
Цей оператор порівнює два списки поелементно — перевіряє, 
чи однакові у них усі елементи в тому самому порядку*/

template <typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}
    ~List() {
        while (head) {
            ListCell* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(T value) {
        ListCell* newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        } else {
            head = newCell;
        }
        tail = newCell;
        ++theCount;
    }

    // ... інші методи ...

    // Оголошення дружнього оператора
    friend bool operator==(const List<T>& lhs, const List<T>& rhs) {
        typename List<T>::ListCell* currentL = lhs.head;
        typename List<T>::ListCell* currentR = rhs.head;

        while (currentL != nullptr && currentR != nullptr) {
            if (!(currentL->val == currentR->val)) {
                return false; // Знайшли різні елементи
            }
            currentL = currentL->next;
            currentR = currentR->next;
        }

        // Якщо один список довший за інший — вони не рівні
        return currentL == nullptr && currentR == nullptr;
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
