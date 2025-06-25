#include <iostream>
using namespace std;

float Dilen(unsigned short int a, unsigned short int b);

int main()
{
    float a, b, c;
    c = Dilen(a,b);
    return 0;
}

float Dilen(unsigned short int a, unsigned short int b){
    cout << "\na? ";
	cin >> a;
	cout << "\nb? ";
	cin >> b;
    if (b==0) {
        cout << "Error";
        return -1; 
    }
    else {
        cout << a / b;
        return a / b;
    }
    
}