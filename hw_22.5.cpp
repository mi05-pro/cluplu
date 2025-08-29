/*

Очікуваний результат при звичайному запуску (без нестачі пам’яті):
(порожній екран, нічого не виводиться)

Якщо пам’яті не вистачить (дуже рідкісна ситуація) → відбудеться:
створення xOutOfMemory,
кидання throw px;,
перехоплення у catch, де виведеться:
error in memory
Memory restored.

*/


#include <iostream>
#include <string>
#include <cstring>   // додали!

using namespace std;

class xOutOfMemory {
public:
    xOutOfMemory() {
        theMsg = new char[20];
        strcpy(theMsg, "error in memory");
    }
    ~xOutOfMemory() {
        delete[] theMsg;
        cout << "Memory restored." << endl;
    }
    char *Message() { return theMsg; }

private:
    char *theMsg;
};

int main() {
    try {
        char *var = new (nothrow) char;  // ← nothrow
        if (var == nullptr) {
            xOutOfMemory *px = new xOutOfMemory;
            throw px;
        }
        delete var;  // ← не забуваємо звільняти пам’ять
    }
    catch (xOutOfMemory *theException) {
        cout << theException->Message() << endl;
        delete theException;
    }
    return 0;
}
