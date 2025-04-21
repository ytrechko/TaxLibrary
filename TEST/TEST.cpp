#include "../TaxLib/pch.h"


#include <fstream>
#include <vector>
using namespace std;
int main()
{
	vector<Owner> owns = FromXmlFileToVector("in.xml");
	ToXmlFile("out.xml", owns);

}
