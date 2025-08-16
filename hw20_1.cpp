#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>  // Для getcwd
#include <cctype>    // Для isprint() та ispunct() 


using namespace std;

int main() {
    
ofstream wfile("1.txt", ios::binary); // binary mode to allow non-text chars
    if (!wfile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    // Write normal text
    wfile << "Hello user!\n";

    // Write some "not readable" (binary) characters
    char data[] = {0x00, 0x01, 0x02, 0x7F, (char)0xFF};
    wfile.write(data, sizeof(data));

    wfile.close();
    cout << "File written.\n";


    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        cout << "Поточна робоча директорія: " << cwd << endl;
    } else {
        cerr << "Помилка при отриманні поточної директорії" << endl;
        return 1;
    }

    // Запитуємо ім'я файлу у користувача
    string filename;
    cout << "Введіть ім'я файлу: ";
    getline(cin, filename);

    // Комбінуємо поточний шлях з ім'ям файлу для отримання абсолютного шляху
    string fullPath = string(cwd) + "/" + filename;

    cout << "Абсолютний шлях до файлу: " << fullPath << endl;

    // Відкриваємо файл для читання
    ifstream file(fullPath);
    if (!file) {
        cerr << "Не вдалося відкрити файл: " << fullPath << "\n";
        return 1;
    }

   // Читання файлу символ за символом
    char ch;
    while (file.get(ch)) {
        // Перевірка, чи є символ друкованим або розділовим знаком
        if (std::isprint(ch) || std::ispunct(ch)) {
            std::cout << ch;
        }
    }

    // Закриваємо файл
    file.close();

    return 0;
}
