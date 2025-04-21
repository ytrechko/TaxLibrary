#include "../TaxLib/pch.h"

#include <fstream>
using namespace std;
int main()
{
	ifstream in("in.json");
	nlohmann::json j;
	in >> j;
	Owner own;
	own.fromJson(j);
	j = own.toJson();
	int i;

}
