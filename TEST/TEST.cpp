#include "../TaxLib/pch.h"


#include <fstream>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	if (argc < 3) { clog << "Error: Укажите путь к файлу в аргументах командной строки.\n"; return 1; }
	try {
		TaxService tx(argv[1]);
		tx.upploadTaxOwnersToFile(argv[2]);
	}
	catch (exception const& e) {
		clog << e.what() << '\n';
	}
	return 0;
}
