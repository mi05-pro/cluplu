#include <iostream>
#include <stdexcept>  // Для виключень

class BoundedArray {
private:
    int arr[5];  // Масив фіксованого розміру
    size_t size; // Поточний розмір масиву

public:
    BoundedArray() : size(0) {}  // Ініціалізуємо масив і встановлюємо розмір на 0

    // Метод для додавання елементів в масив
    bool add(int value) {
        if (size >= 5) {
            std::cout << "Масив переповнений!" << std::endl;
            return false;  // Не можемо додати елемент, якщо масив заповнений
        }

        // Перевіряємо, чи елемент уже є в масиві
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == value) {
                std::cout << "Елемент " << value << " вже є в масиві!" << std::endl;
                return false;  // Якщо елемент вже є, повертаємо false
            }
        }

        // Додаємо новий елемент
        arr[size++] = value;
        return true;
    }

    // Метод для перевірки наявності елемента в масиві
    bool contains(int value) const {
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return true;  // Елемент знайдений
            }
        }
        return false;  // Елемент не знайдений
    }

    // Метод для виведення всіх елементів масиву
    void display() const {
        std::cout << "Елементи в масиві: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Метод для отримання кількості елементів у масиві
    size_t getSize() const {
        return size;
    }
};

class Set {
private:
    BoundedArray array;  // Використовуємо BoundedArray для зберігання елементів набору

public:
    // Метод для додавання елементів до набору
    bool add(int value) {
        return array.add(value);  // Викликаємо метод add з BoundedArray
    }

    // Метод для перевірки наявності елемента в наборі
    bool contains(int value) const {
        return array.contains(value);  // Викликаємо метод contains з BoundedArray
    }

    // Метод для виведення елементів набору
    void display() const {
        array.display();  // Викликаємо метод display з BoundedArray
    }

    // Метод для отримання кількості елементів у наборі
    size_t getSize() const {
        return array.getSize();  // Викликаємо метод getSize з BoundedArray
    }
};

int main() {
    Set mySet;

    // Додаємо елементи до набору
    mySet.add(10);
    mySet.add(20);
    mySet.add(30);
    mySet.add(10);  // Цей елемент не буде додано, оскільки він вже є
    mySet.add(40);

    // Виводимо елементи набору
    mySet.display();  // Виведе: Елементи в масиві: 10 20 30 40

    // Перевірка наявності елемента в наборі
    if (mySet.contains(20)) {
        std::cout << "Елемент 20 є в наборі!" << std::endl;
    }
    if (!mySet.contains(50)) {
        std::cout << "Елемент 50 відсутній в наборі!" << std::endl;
    }

    return 0;
}
