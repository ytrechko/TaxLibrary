#include "../TaxLib/pch.h"

#include <fstream>
#include <vector>
using namespace std;
int main()
{
	vector<Owner> owns = FromJsonFileToVector("in.json");
	ToJsonFile("out.json", owns);
	int i;

}
