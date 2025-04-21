#include "../TaxLib/pch.h"
using namespace std;
int main()
{
	Owner own("pop", "123");
	own.addProperty(new Apartment(12, 23));
	own.addProperty(new Car(1222, 123));
	own.addProperty(new CountryHouse(3332, 55523));
	cout << own << endl;
	own.removeProperty(0);
	cout << own << endl;

}
