#include <iostream>
using namespace std;

class TV {
public:
    // Конструктор за замовчуванням
    TV() : itsStation(1) {}

    // Конструктор з параметром
    TV(int station) {
        itsStation = station;
    }

    void setStation(int station) {
        itsStation = station;
    }

    int getStation() const {
        return itsStation;
    }

private:
    int itsStation;
};

int main() {
    TV myTV;
    myTV.setStation(9);  

    cout << "Станція myTV: " << myTV.getStation() << endl;

    TV myOtherTV(2);     
    cout << "Станція myOtherTV: " << myOtherTV.getStation() << endl;

    return 0;
}
