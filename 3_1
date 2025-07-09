#include <iostream>
using namespace std;
int main()
{
	cout << "The size of an int is:\t\t" << sizeof(int) << " bytes.\n";
	cout << "The size of a short int is:\t\t" << sizeof(short) << " bytes.\n";
	cout << "The size of a long int is:\t\t" << sizeof(long) << " bytes.\n";
	cout << "The size of a char is:\t\t" << sizeof(char) << " bytes,\n";
	cout << "The size of a float is:\t\t" << sizeof(float) << " bytes.\n";
	cout << "The size of a double is:\t\t" << sizeof(double) << " bytes.\n";
	cout << "The size of a bool is:\t\t" << sizeof(bool) << " bytes.\n";

	return 0;
};
////
The size of an int is:		4 bytes.
The size of a short int is:		2 bytes.
The size of a long int is:		8 bytes.
The size of a char is:		1 bytes,
The size of a float is:		4 bytes.
The size of a double is:		8 bytes.
The size of a bool is:		1 bytes.
////
#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void showMinMax() {
   cout << "min: " << numeric_limits<T>::min() << endl;
   cout << "max: " << numeric_limits<T>::max() << endl;
   cout << endl;
}

int main() {

   cout << "short:" << endl;
   showMinMax<short>();
   cout << "int:" << endl;
   showMinMax<int>();
   cout << "long:" << endl;
   showMinMax<long>();
   cout << "float:" << endl;
   showMinMax<float>();
   cout << "double:" << endl;
   showMinMax<double>();
   cout << "long double:" << endl;
   showMinMax<long double>();
   cout << "unsigned short:" << endl;
   showMinMax<unsigned short>();
   cout << "unsigned int:" << endl;
   showMinMax<unsigned int>();
   cout << "unsigned long:" << endl;
   showMinMax<unsigned long>();
}

