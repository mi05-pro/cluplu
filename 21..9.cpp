template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 5, y = 10;
    swap(x, y);
    // Тепер x == 10, y == 5

    double a = 1.23, b = 4.56;
    swap(a, b);
    // Тепер a == 4.56, b == 1.23

    return 0;
}
