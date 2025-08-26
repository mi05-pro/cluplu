/*
operator== оголошено як friend всередині шаблонного класу, щоб мати доступ до head і внутрішніх деталей.
Порівняння відбувається поелементно.
Використовується оператор == для типу T (currentL->val == currentR->val), тому тип T повинен підтримувати operator==.
*/

template <typename T>
class List {
    // ... інші оголошення ...

    // Оголошення дружнього оператора
    friend bool operator==(const List<T>& lhs, const List<T>& rhs) {
        typename List<T>::ListCell* currentL = lhs.head;
        typename List<T>::ListCell* currentR = rhs.head;

        while (currentL != nullptr && currentR != nullptr) {
            if (!(currentL->val == currentR->val)) {
                return false;  // Знайшли різні елементи
            }
            currentL = currentL->next;
            currentR = currentR->next;
        }

        // Якщо один список закінчився раніше за інший — вони не рівні
        return currentL == nullptr && currentR == nullptr;
    }

private:
    class ListCell {
        // ...
        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};
