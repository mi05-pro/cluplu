/*
#include <iostream>

int main() {
    char ticTacToe[3][3];
    // Ініціалізація всіх елементів нульовим символом
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ticTacToe[i][j] = 0;
        }
    }

    // Для перевірки — виведемо коди символів у кожній клітинці
    std::cout << "Коди символів у масиві:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << ticTacToe[i][j]<< " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/

// 3. помилка у порядку індексів, яка може призвести до виходу за межі масиву і неправильної ініціалізації
// правильний варіант 5 рядків (індекс i: від 0 до 4) 4 стовпці (індекс j: від 0 до 3)
/*
#include <iostream>

int main() {

unsigned short SomeArray[5][4];

for (int i = 0; i < 5; i++)        // Рядки
    for (int j = 0; j < 4; j++)    // Стовпці
        SomeArray[i][j] = i + j;


for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 4; j++) {
            std::cout <<  SomeArray[i][j] << " ";  
            }

        std::cout << std::endl;

    }
         return 0;
}
*/
/* 4 правильна версія 
for (int i = 0; i < 5; i++)        // 0 до 4
    for (int j = 0; j < 4; j++)    // 0 до 3
        SomeArray[i][j] = 0;
*/

#include <iostream>

int main() {

unsigned short SomeArray[5][4];

for (int i = 0; i < 5; i++)        // 0 до 4
    for (int j = 0; j < 4; j++)    // 0 до 3
        SomeArray[i][j] = 0;

for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 4; j++) {
            std::cout <<  SomeArray[i][j] << " ";  
            }

        std::cout << std::endl;

    }

return 0;      

}